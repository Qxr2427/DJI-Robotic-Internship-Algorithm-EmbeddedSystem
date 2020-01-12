//
// Created by charmyoung on 19-7-17.
//

#ifndef ROBOMASTER_ROBOT_H
#define ROBOMASTER_ROBOT_H

#include "serial_device.h"
#include "protocol.h"
#include "crc.h"

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "simple_msgs/GameStatus.h"
#include <thread>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

/**
 * @brief Robot Base Node
 *        Main Process is
 *        1. RECEIVING:
 *           Virtual Serial Comm -> Unpack and Get Protocol Data
 *           -> Convert to ROS Data -> ROS Publish
 *        2. SENDING:
 *           ROS Subscribe -> Get ROS Data -> Convert to Protocol Data
 *           -> Convert to Protocol Data and Pack -> Virtual Serial Comm
 */
namespace robomaster {
    class Robot {
    public:
        Robot(std::string device_path = "/dev/ttyACM0"):
                device_path_(device_path) {

            if( !( ROSInit() && CommInit() ) ){
                ros::shutdown();
            };

        }
        ~Robot() {
            if(recv_thread_.joinable()){
                recv_thread_.join();
            }
        }


        void ChassisCtrlCallback(const geometry_msgs::TwistConstPtr & msg){

            chassis_ctrl_info_.vx = msg->linear.x;
            chassis_ctrl_info_.vy = msg->linear.y;
            chassis_ctrl_info_.vw = msg->angular.z;

            uint16_t send_length = SenderPackSolve((uint8_t*)&chassis_ctrl_info_,sizeof(chassis_ctrl_info_t),
                                                   CHASSIS_CTRL_CMD_ID,send_buff_.get());
            device_ptr_->Write(send_buff_.get(),send_length);

        }

    private:
        bool ROSInit() {
            ros::NodeHandle nh;
            chassis_ctrl_sub_ = nh.subscribe("cmd_vel", 1, &Robot::ChassisCtrlCallback, this);
            chassis_odom_pub_ = nh.advertise<nav_msgs::Odometry>("odom",1);
            game_status_pub_ = nh.advertise<simple_msgs::GameStatus>("game_status",10);

            odom_.header.frame_id = "odom";
            odom_.child_frame_id = "base_link";

            odom_tf_.header.frame_id = "odom";
            odom_tf_.child_frame_id = "base_link";
            return true;
        }
        bool CommInit() {

            device_ptr_ = std::make_shared<SerialDevice>(device_path_, 921600);

            if (!device_ptr_->Init()) {
                return false;
            }

            recv_buff_ = std::unique_ptr<uint8_t[]>(new uint8_t[BUFF_LENGTH]);
            send_buff_ = std::unique_ptr<uint8_t[]>(new uint8_t[BUFF_LENGTH]);

            memset(&frame_receive_header_, 0, sizeof(frame_header_struct_t));
            memset(&frame_send_header_, 0, sizeof(frame_header_struct_t));

            /** Specific Protocol Data Initialize here**/
            memset(&summer_camp_info_, 0, sizeof(summer_camp_info_t));

            //Start recv thread
            recv_thread_ = std::thread(&Robot::RecvThread, this);
            return true;
        }

        void RecvThread() {
            while (ros::ok()){
                uint16_t read_length = device_ptr_->Read(recv_buff_.get(),BUFF_LENGTH);
//                std::cout<<"length:" << static_cast<int>(read_length)<<std::endl;
                SearchFrameSOF(recv_buff_.get(), read_length);
                usleep(1);
            }

        }

        void SearchFrameSOF(uint8_t *frame, uint16_t total_len) {
            uint16_t i;
            uint16_t index;
            for (i = 0; i < total_len;) {
                if (*frame == HEADER_SOF) {
                    index = ReceiveDataSolve(frame);
                    i += index;
                    frame += index;
                } else {
                    i++;
                    frame++;
                }
            }

        }

        uint16_t ReceiveDataSolve(uint8_t *frame) {
            uint8_t index = 0;
            uint16_t cmd_id = 0;
            if (*frame != HEADER_SOF) {
                return 0;
            }

            memcpy(&frame_receive_header_, frame, sizeof(frame_header_struct_t));
            index += sizeof(frame_header_struct_t);

            if ((!Verify_CRC8_Check_Sum(frame, sizeof(frame_header_struct_t)))
                || (!Verify_CRC16_Check_Sum(frame, frame_receive_header_.data_length + 9))) {
//                std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
                return 1;
            } else {
                memcpy(&cmd_id, frame + index, sizeof(uint16_t));
                index += sizeof(uint16_t);

                switch (cmd_id) {

                    /** Write Your code here to get different types of data and publish them using ROS interface
                     *
                     *  Example:
                     *
                     *   case XXXX_CMD_ID:{
                     *
                     *    memcpy(&xxxx_info, frame + index, sizeof(xxxx_info_t));
                     *
                     *
                     *    break;
                     *
                     *   }
                     *
                     */
                    case CHASSIS_ODOM_CMD_ID: {
                        memcpy(&chassis_odom_info_, frame + index, sizeof(chassis_odom_info_t));

//          ROS_INFO("chassis odom info!");
                        ros::Time current_time = ros::Time::now();
                        odom_.header.stamp = current_time;
                        odom_.pose.pose.position.x = chassis_odom_info_.x;
                        odom_.pose.pose.position.y = chassis_odom_info_.y;
                        odom_.pose.pose.position.z = 0.0;
                        geometry_msgs::Quaternion q = tf::createQuaternionMsgFromYaw(chassis_odom_info_.gyro_yaw);
                        odom_.pose.pose.orientation = q;
                        odom_.twist.twist.linear.x = chassis_odom_info_.vx;
                        odom_.twist.twist.linear.y = chassis_odom_info_.vy;
                        odom_.twist.twist.angular.z = chassis_odom_info_.gyro_vw;
                        chassis_odom_pub_.publish(odom_);

                        odom_tf_.header.stamp = current_time;
                        odom_tf_.transform.translation.x = chassis_odom_info_.x;
                        odom_tf_.transform.translation.y = chassis_odom_info_.y;

                        odom_tf_.transform.translation.z = 0.0;
                        odom_tf_.transform.rotation = q;
                        tf_broadcaster_.sendTransform(odom_tf_);
                        break;
                    }
                    case GAME_STATUS_CMD_ID: {
//                        ROS_INFO("--summer camp info!");
                        memcpy(&summer_camp_info_, frame + index, sizeof(summer_camp_info_t));

                        simple_msgs::GameStatus game_status;
                        simple_msgs::CastleEnergy castle_energy;
                        simple_msgs::RegionOccupy region_occupy;

                        game_status.round_team = summer_camp_info_.round_team;
                        game_status.round_remain_cnt = summer_camp_info_.round_remain_cnt;
                        game_status.round_remain_tick = summer_camp_info_.round_remain_tick;
                        game_status.red_score = summer_camp_info_.realtime_score[0];
                        game_status.blue_score = summer_camp_info_.realtime_score[1];
                        game_status.red_position = (summer_camp_info_.car_location[0]>>4)+
                                                   (summer_camp_info_.car_location[0]&0x0F)*9;
                        game_status.blue_position = (summer_camp_info_.car_location[1]>>4)+
                                                    (summer_camp_info_.car_location[1]&0x0F)*9;
                        game_status.red_step_move = summer_camp_info_.round_step_move[0];
                        game_status.blue_step_move = summer_camp_info_.round_step_move[1];;

                        for(int i = 0; i < 7; i ++){
                            for(int j = 0; j < 9; j ++){
                                region_occupy.status = summer_camp_info_.region_occupy[j][i].status;
                                region_occupy.belong = summer_camp_info_.region_occupy[j][i].belong;
                                game_status.region_occupy.push_back(region_occupy);
                            }
                        }
                        for(int i = 0; i < 7; i ++){
                            castle_energy.red_energy =summer_camp_info_.castle_energy[i].energy[0];
                            castle_energy.blue_energy =summer_camp_info_.castle_energy[i].energy[1];
                            game_status.castle_energy.push_back(castle_energy);
                        }
                        game_status_pub_.publish(game_status);
//                        ROS_INFO("summer camp info!--");
                        break;
                    }
                    default:
                        break;
                }

                index += frame_receive_header_.data_length + 2;

                return index;
            }
        }

        uint16_t SenderPackSolve(uint8_t *data, uint16_t data_length,
                                 uint16_t cmd_id, uint8_t *send_buf) {

            uint8_t index = 0;
            frame_send_header_.SOF = HEADER_SOF;
            frame_send_header_.data_length = data_length;
            frame_send_header_.seq++;

            Append_CRC8_Check_Sum((uint8_t * ) & frame_send_header_, sizeof(frame_header_struct_t));


            memcpy(send_buf, &frame_send_header_, sizeof(frame_header_struct_t));

            index += sizeof(frame_header_struct_t);

            memcpy(send_buf + index, &cmd_id, sizeof(uint16_t));

            index += sizeof(uint16_t);

            memcpy(send_buf + index, data, data_length);

            Append_CRC16_Check_Sum(send_buf, data_length + 9);

            return data_length + 9;
        }

    private:

        //! VCOM Data Receiving Thread (Tips: VCOM Sending part is in Each ROS Data Callback)
        std::thread recv_thread_;

        //! Device Information and Buffer Allocation
        std::string device_path_;
        std::shared_ptr<SerialDevice> device_ptr_;
        std::unique_ptr<uint8_t[]> recv_buff_;
        std::unique_ptr<uint8_t[]> send_buff_;
        const unsigned int BUFF_LENGTH = 1024;

        //! Frame Information
        frame_header_struct_t frame_receive_header_;
        frame_header_struct_t frame_send_header_;

        /** @brief specific protocol data are defined here
         *         xxxx_info_t is defined in protocol.h
         */

        //! Receive from VCOM
        summer_camp_info_t summer_camp_info_;


        chassis_odom_info_t chassis_odom_info_;

        geometry_msgs::TransformStamped odom_tf_;//! ros chassis odometry tf
        nav_msgs::Odometry odom_;//! ros odometry message

        //! Send to VCOM
        chassis_ctrl_info_t chassis_ctrl_info_;


        /** @brief ROS data corresponding to specific protocol data are defined here
         *         You can use ROS provided message data type or create your own one
         *         More information please refer to
         *               http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv
         */


        /** @brief ROS Subscription and Publication
         */
        ros::Subscriber chassis_ctrl_sub_; //! ros subscriber for chassis velocity control
        ros::Publisher chassis_odom_pub_; //! ros publisher for odometry information
        ros::Publisher game_status_pub_; //! ros publisher for game status
        tf::TransformBroadcaster tf_broadcaster_;//! ros chassis odometry tf broadcaster

    };
}

#endif //ROBOMASTER_ROBOT_H
