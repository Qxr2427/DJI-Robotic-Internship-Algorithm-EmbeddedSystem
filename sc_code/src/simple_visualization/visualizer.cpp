/****************************************************************************
 *  Copyright (C) 2019 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <simple_msgs/GameStatus.h>
#include <visualization_msgs/MarkerArray.h>


namespace robomaster{
    class Visualizer{
    public:
        Visualizer(ros::NodeHandle& given_nh):
                nh(given_nh){
            game_status_sub_ = nh.subscribe("/game_status", 5, &Visualizer::GameStatusCallback,this);
            region_pub_ = nh.advertise<visualization_msgs::MarkerArray>("region", 10);
            castle_pub_ = nh.advertise<visualization_msgs::MarkerArray>("castle", 10, true);
            ros::Duration(0.5).sleep();

                PublishStaticCastle();


        }
        ~Visualizer()= default;

    private:
        void PublishStaticCastle() {
            visualization_msgs::MarkerArray castle_array;
            castle_array.markers.resize(7);
            std::array<int, 7> castle_pos = {2, 6, 27, 31, 35, 56, 60};
            for (int i = 0; i < 7; i++) {
                castle_array.markers[i].header.frame_id = "tag_" + std::to_string(castle_pos[i]);
                castle_array.markers[i].header.stamp = ros::Time::now();
                castle_array.markers[i].ns = "castle";
                castle_array.markers[i].id = i;
                castle_array.markers[i].action = visualization_msgs::Marker::ADD;
                castle_array.markers[i].type = visualization_msgs::Marker::CYLINDER;
                castle_array.markers[i].pose.position.x = 0;
                castle_array.markers[i].pose.position.y = 0;
                castle_array.markers[i].pose.position.z = 0.1;
                castle_array.markers[i].pose.orientation.x = 0.0;
                castle_array.markers[i].pose.orientation.y = 0.0;
                castle_array.markers[i].pose.orientation.z = 0.0;
                castle_array.markers[i].pose.orientation.w = 1.0;

                castle_array.markers[i].scale.x = 0.3;
                castle_array.markers[i].scale.y = 0.3;
                castle_array.markers[i].scale.z = 0.01;

                castle_array.markers[i].color.a = 1.0;
                castle_array.markers[i].color.r = 0.0;
                castle_array.markers[i].color.g = 1.0;
                castle_array.markers[i].color.b = 0.0;

            }
            castle_pub_.publish(castle_array);
        }
        void GameStatusCallback(const simple_msgs::GameStatus::ConstPtr& msg){
            visualization_msgs::MarkerArray region_array;
            region_array.markers.resize(7*9+2);

            for ( int i = 0; i < 63; i++)
            {

                region_array.markers[i].header.frame_id = "tag_"+std::to_string(i);
                region_array.markers[i].header.stamp = ros::Time::now();
                region_array.markers[i].ns = "region";
                region_array.markers[i].id = i;
                region_array.markers[i].action = visualization_msgs::Marker::ADD;
                region_array.markers[i].type = visualization_msgs::Marker::CUBE;
                region_array.markers[i].pose.position.x = 0;
                region_array.markers[i].pose.position.y = 0;
                region_array.markers[i].pose.position.z = 0;
                region_array.markers[i].pose.orientation.x = 0.0;
                region_array.markers[i].pose.orientation.y = 0.0;
                region_array.markers[i].pose.orientation.z = 0.0;
                region_array.markers[i].pose.orientation.w = 1.0;

                region_array.markers[i].scale.x = 0.5;
                region_array.markers[i].scale.y = 0.5;
                region_array.markers[i].scale.z = 0.01;
//                        region_array.markers[i].lifetime = 0;
                switch (msg->region_occupy[i].status) {
                    case 0:
                        region_array.markers[i].color.a = 0.1;
                        break;
                    case 1:
                        region_array.markers[i].color.a = 0.5;
                        break;
                    case 2:
                        region_array.markers[i].color.a = 1.0;
                        break;
                    default:
                        ROS_ERROR("Invalid value for region occupy status");
                        return;
                }
                switch (msg->region_occupy[i].belong){
                    case 2:
                        region_array.markers[i].color.r = 1.0;
                        region_array.markers[i].color.g = 1.0;
                        region_array.markers[i].color.b = 1.0;
                        break;
                    case 0:
                        region_array.markers[i].color.r = 1.0;
                        region_array.markers[i].color.g = 0.0;
                        region_array.markers[i].color.b = 0.0;
                        break;
                    case 1:
                        region_array.markers[i].color.r = 0.0;
                        region_array.markers[i].color.g = 0.0;
                        region_array.markers[i].color.b = 1.0;
                        break;
                    default:
                        ROS_ERROR("Invalid value for region occupy belong");
                        return;
                }

            }
            //Draw red robot
            region_array.markers[63].header.frame_id = "tag_" + std::to_string(msg->red_position);
            region_array.markers[63].header.stamp = ros::Time::now();
            region_array.markers[63].ns = "robot";
            region_array.markers[63].id = 0;
            region_array.markers[63].action = visualization_msgs::Marker::ADD;
            region_array.markers[63].type = visualization_msgs::Marker::SPHERE;
            region_array.markers[63].pose.position.x = 0;
            region_array.markers[63].pose.position.y = 0;
            region_array.markers[63].pose.position.z = 0;
            region_array.markers[63].pose.orientation.x = 0.0;
            region_array.markers[63].pose.orientation.y = 0.0;
            region_array.markers[63].pose.orientation.z = 0.0;
            region_array.markers[63].pose.orientation.w = 1.0;

            region_array.markers[63].scale.x = 0.1;
            region_array.markers[63].scale.y = 0.1;
            region_array.markers[63].scale.z = 0.01;
            region_array.markers[63].color.a = 1.0;
            region_array.markers[63].color.r = 1.0;
            region_array.markers[63].color.g = 0.0;
            region_array.markers[63].color.b = 0.0;
            //Draw blue robot
            region_array.markers[64].header.frame_id = "tag_" + std::to_string(msg->blue_position);
            region_array.markers[64].header.stamp = ros::Time::now();
            region_array.markers[64].ns = "robot";
            region_array.markers[64].id = 1;
            region_array.markers[64].action = visualization_msgs::Marker::ADD;
            region_array.markers[64].type = visualization_msgs::Marker::SPHERE;
            region_array.markers[64].pose.position.x = 0;
            region_array.markers[64].pose.position.y = 0;
            region_array.markers[64].pose.position.z = 0;
            region_array.markers[64].pose.orientation.x = 0.0;
            region_array.markers[64].pose.orientation.y = 0.0;
            region_array.markers[64].pose.orientation.z = 0.0;
            region_array.markers[64].pose.orientation.w = 1.0;

            region_array.markers[64].scale.x = 0.1;
            region_array.markers[64].scale.y = 0.1;
            region_array.markers[64].scale.z = 0.01;
            region_array.markers[64].color.a = 1.0;
            region_array.markers[64].color.r = 0.0;
            region_array.markers[64].color.g = 0.0;
            region_array.markers[64].color.b = 1.0;

            region_pub_.publish(region_array);
        }



    private:
        ros::NodeHandle nh;
        ros::Subscriber game_status_sub_;
        ros::Publisher region_pub_;
        ros::Publisher castle_pub_;
    };
}

using namespace robomaster;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "visualizer");
    ros::NodeHandle nh("~");
    Visualizer visualizer(nh);
    ros::spin();
    return 0;
}


