//
// Created by kevin on 19-7-27.
//
#include "ros/ros.h"
#include <tf/transform_listener.h>
#include <memory>
#include <iostream>
#include <std_msgs/Bool.h>
#include <cmath>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <png.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <vector>
#include <queue>
#include "simple_msgs/GameStatus.h"
#define INF 99999
//using namespace std;
int graph [63][63];
int team_id=0; //change if on the other side
int round_team=0;
using namespace std;
struct Board{
    int type; //road==-1,
    int isStrong; // 0 N, 1W, 2 S
    int belong; //0 N, 1R 2B;
    int have_robot; //same as above
    int pointValue=0;
    //int isTower;
    int tag_id;
    int energyDiff;
};
namespace Game {
    const int GAME_TOTAL_STEP = 15;
    const int GAME_TOTAL_MS = 40000;
    //time consts
    const int ACTION_MOVE_MS = 1000;
    const int ACTION_OCCUPY_MS = 1000;
    const int ACTION_PLACE_FIRST_BALL_MS = 7000;
    const int ACTION_PLACE_FIRST_CUP_MS = 20000;
    const int ACTION_PLACE_BALL_MS = 6000;
    const int ACTION_PLACE_CUP_MS = 20000;
    //point consts
    const int POINTS_PENALTY_CROSS = 5;
    const int POINTS_HAVE_TOWER = 50;
    const int POINTS_OCCUPY = 15;
    const int POINTS_STRONG_OCCUPY = 20;
    //Consts
    const int MAX_X = 9;
    const int MAX_Y = 7;
    const int MAX_CASTLE = 7;
    int CUP_COUNT = 8;
    int BALL_COUNT = 25;
    /*const int CASTLE_ID[MAX_X][MAX_Y] = {
            {-1, -1, 0,  -1, -1, -1, 1,  -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {2,  -1, -1, -1,  3, -1, -1, -1,  4},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1},
            {-1, -1, 5,  -1, -1, -1, 6,  -1, -1},
    };*/
    const int CASTLE_PLACE_ID[2][MAX_X][MAX_Y] = {
            {
                    /*{-1,  0, -2, -1, -1,  1, -2, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
                    { 2, -1, -1, -1,  3, -1, -1, -1, -1},
                    {-2, -1, -1, -1, -2, -1, -1, -1, -2},
                    {-1, -1, -1, -1, -1, -1, -1, -1,  4},
                    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -2,  5, -1, -1, -2,  6, -1},*/
                    {-1,-1,-1,-2,2,-1,-1},
                    {-1,-1,-1,-1,-1,-1,5},
                    {-2,-1,-1,-1,-1,-1,-2},
                    {0,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-2,3,-1,-1},
                    {-1,-1,-1,-1,-1,-1,6},
                    {-2,-1,-1,-1,-1,-1,-2},
                    {1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,4,-2,-1,-1,-1}
            },
            {
                    /*{-1, -1, -1,  0, -1, -1, -1,  1, -1},
                    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1, -1,  4},
                    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
                    { 2, -1, -1, -1,  3, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
                    {-1,  5, -1, -1, -1,  6, -1, -1, -1},*/
                    {-1,-1,2,-2,-1,-1,-1},
                    {0,-1,-1,-1,-1,-1,-1},
                    {-2,-1,-1,-1,-1,-1,-2},
                    {-1,-1,-1,-1,-1,-1,5},
                    {-1,-1,3,-2,-1,-1,-1},
                    {1,-1,-1,-1,-1,-1,-1},
                    {-2,-1,-1,-1,-1,-1,-2},
                    {-1,-1,-1,-1,-1,-1,6},
                    {-1,-1,-1,-2,4,-1,-1}
            } //-2 =blocked, -1=road, >=0 = tower
    };
    const int CASTLE_COORD[MAX_CASTLE][2] = {
            {0, 2},
            {0, 6},
            {3, 0},
            {3, 4},
            {3, 8},
            {6, 2},
            {6, 6}
    };
}
using namespace Game;
Board board[MAX_X][MAX_Y];
int high=-9999999;
vector<int> path;
vector<int> execution;
vector<float> exec_delay;
queue<int> putStuff; //first is cup, second is extra balls after cups
int timeOptimal;
int cupcount=5;
int ballcount=12;
void eval(){ //time calc prob needs more changes
    vector<float> delay;
    int total=0;
    int time=GAME_TOTAL_MS;
    for(int i=0;i<path.size();i+=2){
        int x=path.at(i);
        int y=path.at(i+1);
        if(board[x][y].type==-2){
            //cout<<"Blocked";
            return;
        }
        if(board[x][y].type==-1) {
            if (board[x][y].belong == team_id) {
                time -= 1200;
                if (time <= 0) return;
                delay.push_back(0);
            } else if (board[x][y].belong == 0) {
                time -= 3000;
                if (time <= 0) return;
                total += board[x][y].pointValue;
                delay.push_back(3);
            } else if (board[x][y].isStrong == 1) {
                time -= 3000;
                if (time <=0) return;
                total += board[x][y].pointValue; //25
                delay.push_back(3);
            } else if (board[x][y].isStrong == 2) {
                time -= 1200;
                if (time <= 0) return;
                total += board[x][y].pointValue; //-5
                delay.push_back(0);
            } else if (board[x][y].isStrong == 0) {
                time -= 3000;
                if (time <= 0) return;
                total += board[x][y].pointValue; //15
                delay.push_back(3);
            }
        }
        if(board[x][y].type>=0){
            if(board[x][y].belong==team_id) {
                time-=3000;
                if(time<=0) return;
                delay.push_back(3);
            }
            else if(board[x][y].energyDiff>5&&(cupcount>board[x][y].energyDiff+1)/6&&ballcount>(board[x][y].energyDiff+1)/6+(board[x][y].energyDiff+1)%6){
                time-=ACTION_PLACE_FIRST_CUP_MS+
                      (board[x][y].energyDiff+1-6)/6*ACTION_PLACE_CUP_MS+
                      (board[x][y].energyDiff+1-6)%6*ACTION_PLACE_BALL_MS;
                if(time<=0) return;
                total+=100;
                cupcount-=1+(board[x][y].energyDiff+1-6)/6;
                ballcount-=1+(board[x][y].energyDiff+1-6)/6+(board[x][y].energyDiff+1-6)%6;
                putStuff.push(1+(board[x][y].energyDiff+1-6)/6);
                putStuff.push((board[x][y].energyDiff+1-6)%6);
                delay.push_back(25);
                //   cout<<"Occupy1 "<<total<<endl;
            }
            else if(board[x][y].energyDiff<=5){
                if(cupcount>0&&ballcount>0) {
                    time -= 20000;
                    if (time <= 0) return;
                    total+=100;
                    cupcount--;
                    ballcount--;
                    putStuff.push(1);
                    putStuff.push(0);
                    delay.push_back(25);
                    //    cout<<"Occupy2 "<<total<<endl;
                }
                else if(ballcount>=board[x][y].energyDiff+1){
                    time-=(ACTION_PLACE_BALL_MS*(board[x][y].energyDiff+1));
                    if(time<=0) return;
                    total+=100;
                    ballcount-=board[x][y].energyDiff+1;
                    delay.push_back(25);
                    putStuff.push(0);
                    putStuff.push(board[x][y].energyDiff+1);
                    //   cout<<"Occupy3 "<<total<<endl;
                }
            }
            //ball count and stuff...
        }
        if(total>high){
            high=total;
            execution.assign(path.begin(),path.begin()+i+2); //OR IT CAN GO ALL THE WAY TO THE END
            exec_delay.assign(delay.begin(),delay.end()); //magical number is 8
            timeOptimal=time;
        }
    }
    //cout<<total<<endl;
    return;
}
bool twoTower;
bool noTower;
void dfeSearchTower(int x, int y){
}
/*void redef(){ //initialize adjmatrix
    for(int i=0;i<MAX_X;i++){
        for(int j=0;j<MAX_Y;j++){
            if(j+1<7)
                graph[board[i][j].tag_id][board[i][j+1].tag_id]=board[i][j+1].pointValue;
            if(j-1>-1)
                graph[board[i][j].tag_id][board[i][j-1].tag_id]=board[i][j-1].pointValue;
            if(i+1<9)
                graph[board[i][j].tag_id][board[i+1][j].tag_id]=board[i+1][j].pointValue;
            if(i-1>-1)
                graph[board[i][j].tag_id][board[i-1][j].tag_id]=board[i-1][j].pointValue;
        }
    }
} */
bool visited[9][7];
void greedyOptimal(int count,int x, int y, int prev_x, int prev_y){
    if(count==15){
        eval();
        return;
    }
    if(board[x][y].type==-2) return;
    if(x+1<9&&!visited[x+1][y]) {
        visited[x+1][y]=true;
        path.push_back(x+1);
        path.push_back(y);
        greedyOptimal(count + 1, x + 1, y, x, y);
        visited[x+1][y]=false;
        path.pop_back();
        path.pop_back();
    }
    if(y+1<7&&!visited[x][y+1]) {
        visited[x][y+1]=true;
        //  path.push_back(board[x][y+1].tag_id);
        path.push_back(x);
        path.push_back(y+1);
        greedyOptimal(count + 1, x, y + 1, x, y);
        visited[x][y+1]=false;
        path.pop_back();
        path.pop_back();
    }
    if(x-1>=0&&!visited[x-1][y]) {
        visited[x-1][y]=true;
        path.push_back(x-1);
        path.push_back(y);
        // path.push_back(board[x-1][y].tag_id);
        greedyOptimal(count + 1, x - 1, y, x, y);
        visited[x-1][y]=false;
        path.pop_back();
        path.pop_back();
    }
    if(y-1>=0&&!visited[x][y-1]) {
        visited[x][y-1]=true;
        path.push_back(x);
        path.push_back(y-1);
        //path.push_back(board[x][y-1].tag_id);
        greedyOptimal(count + 1, x, y-1, x, y);
        visited[x][y-1]=false;
        path.pop_back();
        path.pop_back();
    }
}
void firstRound(){
}
/*bool isConnected(){
    int x,y;
    for(int i=0;i<MAX_X;i++){
        for(int j=0;j<MAX_Y;j++){
            if(region_occupy[i][j].have_robot==team_id) {
                x=i;y=j;
                break;
            }
        }
    }
} */
//firstroundoptimal........
float time_left;
int ROBOT_POS_X;
int ROBOT_POS_Y;
void refereeCallback(const simple_msgs::GameStatus::ConstPtr& msg ){
    time_left=msg->round_remain_tick;
    round_team=msg->round_team;
    int a,b; //enemy position
    int c,d; //our position
    for(int i=0;i<MAX_X;i++) {
        for (int j = 0; j < MAX_Y; j++) {
            board[i][j].belong = msg->region_occupy[i+j*9].belong;
            board[i][j].tag_id = i+j*9;
            board[i][j].isStrong = msg->region_occupy[i+j*9].status;
            board[i][j].type =CASTLE_PLACE_ID[team_id][i][j];
            if (board[i][j].type > -1) {
                if (board[i][j].belong == 1 - team_id || board[i][j].belong == 2) board[i][j].pointValue = 50;
                else board[i][j].pointValue = 0;
                if(team_id==0){
                    board[i][j].energyDiff = msg->castle_energy[CASTLE_PLACE_ID[team_id][i][j]].blue_energy-msg->castle_energy[CASTLE_PLACE_ID[team_id][i][j]].red_energy;
                }
                else{
                    board[i][j].energyDiff = msg->castle_energy[CASTLE_PLACE_ID[team_id][i][j]].red_energy-msg->castle_energy[CASTLE_PLACE_ID[team_id][i][j]].blue_energy;
                }
            }
            else if(board[i][j].type==-1){
                if(board[i][j].belong==1-team_id&&board[i][j].isStrong==2) board[i][j].pointValue=-5;
                else if (board[i][j].belong==1-team_id&&board[i][j].isStrong==1) board[i][j].pointValue=25;
                else if (board[i][j].belong==2) board[i][j].pointValue=15;
                else board[i][j].pointValue=0;
            }
            else if(board[i][j].type==-2) board[i][j].pointValue=-999;
        }
    }
    if(team_id==0){
        a=msg->blue_position%9;
        b=msg->blue_position/9;
        board[a][b].type=-2;
        board[a][b].pointValue==-999;
        ROBOT_POS_X=msg->red_position%9;
        ROBOT_POS_Y=msg->red_position/9;
    }
    else{
        a=msg->red_position%9;
        b=msg->red_position/9;
        board[a][b].type=-2;
        board[a][b].pointValue==-999;
        ROBOT_POS_X=msg->blue_position%9;
        ROBOT_POS_Y=msg->blue_position/9;
    }
}
double GetYawFromOrientation(const geometry_msgs::Quaternion& orientation){
    tf::Quaternion q;
    tf::quaternionMsgToTF(orientation,q);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    return yaw;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "make_a_move");
    ros::NodeHandle nh_;
    double ini_time=ros::Time::now().toSec();
    ros::Publisher pub_velocity;
    ros::Subscriber referee_receiver=nh_.subscribe("game_status", 1000, &refereeCallback);
    tf::TransformListener listener;
    tf::StampedTransform map_baselink;
    /*  for(int i=0;i<MAX_X;i++) {
          for (int j = 0; j < MAX_Y; j++) {
              board[i][j].belong = rand()%2;
              board[i][j].tag_id = i+j*9;
              board[i][j].isStrong = rand()%2;
              board[i][j].pointValue = 0;
              board[i][j].type =CASTLE_PLACE_ID[team_id][i][j];
              if (CASTLE_PLACE_ID[team_id][i][j] > -1) {
                  board[i][j].pointValue = 50;
              }
              if (CASTLE_PLACE_ID[team_id][i][j] >= 0) {
                  board[i][j].energyDiff = 0;
              }
          }
      }*/

        //srand(int(time(0)));
        /* for(int i=0;i<MAX_X;i++) {
               for (int j = 0; j < MAX_Y; j++) {
                   board[i][j].belong = rand()%3;
                   board[i][j].tag_id = i+j*9;
                   board[i][j].isStrong = rand()%3;
                   board[i][j].type =CASTLE_PLACE_ID[team_id][i][j];
                   if (board[i][j].type > -1) {
                       if (board[i][j].belong == 1 - team_id || board[i][j].belong == 2) board[i][j].pointValue = 50;
                       else board[i][j].pointValue = 0;
                       if(team_id==0){
                         board[i][j].energyDiff = 0;
                       }
                      else{
                           board[i][j].energyDiff = 0;
                       }
                   }
                   else if(board[i][j].type==-1){
                       if(board[i][j].belong==1-team_id&&board[i][j].isStrong==2) board[i][j].pointValue=-5;
                       else if (board[i][j].belong==1-team_id&&board[i][j].isStrong==1) board[i][j].pointValue=25;
                       else if (board[i][j].belong==2) board[i][j].pointValue=15;
                       else board[i][j].pointValue=0;
                   }
                   else if(board[i][j].type==-2) board[i][j].pointValue=-999;
               }
           }*/
        /*for(int i=0;i<MAX_X;i++){
            for(int j=0;j<MAX_Y;j++){
                board[i][j].tag_id = i+j*9;
            }
        }*/
        // cout<<board[4][2].tag_id<<endl;
        ros::spinOnce();
        greedyOptimal(0, ROBOT_POS_X, ROBOT_POS_Y, 0, 0);
        cout<<ROBOT_POS_X<<" "<<ROBOT_POS_Y<<endl;
        /*  for(int i=0;i<execution.size();i++){
              cout<<execution.at(i)<<endl;
          }*/
        cout << high << endl;
        pub_velocity = nh_.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 5);
        float x_distance = 0;
        float y_distance = 0;
        tf::StampedTransform map_tag_transform;


        while (!listener.waitForTransform("map", "base_link", ros::Time(0), ros::Duration(1.0))) {
            ros::Duration(1.0).sleep();
        }
        try {
            listener.lookupTransform("map", "base_link", ros::Time(0), map_baselink);
        }
        catch (tf::TransformException ex) {
            ROS_ERROR("2:%s", ex.what());
//            ros::Duration(1.0).sleep();
        }
        ros::Rate r(30); /// 30 hz
//        ros::Rate loop_rate(1);
        /// Main while loop
        //  cout<<"g"<<endl;
        cout << "Size: " << execution.size() << endl;
//    pub_velocity.publish(paths);
        int count = 0;
        geometry_msgs::PoseStamped goal_pose;
        goal_pose.header.frame_id = "map";
        goal_pose.header.stamp = ros::Time();
        ros::Duration(0.5).sleep();
        for (int i = 0; i < execution.size(); i += 2) {
            ///       if(time_left<2.7) return 0;
            double time_now = ros::Time::now().toSec();
            // if(time_now+exec_delay.at(count)-ini_time>40) break;
            int a = execution.at(i);
            int b = execution.at(i + 1);
            cout<<a<<" "<<b<<endl;
            std::string tag_id = "tag_";
            int tagid;
            tagid = board[a][b].tag_id;
            cout << tagid << endl;
            tag_id = tag_id + std::to_string(tagid);
            // cout<<"1"<<endl;
            try {
                listener.lookupTransform("map", "base_link", ros::Time(0), map_baselink);
                listener.lookupTransform("map", tag_id, ros::Time(0), map_tag_transform);
            }
            catch (tf::TransformException ex) {
                ROS_ERROR("3:%s", ex.what());
            }
            while (ros::ok()) {
                try {
                    listener.lookupTransform("map", "base_link", ros::Time(0), map_baselink);
                    listener.lookupTransform("map", tag_id, ros::Time(0), map_tag_transform);
                }
                catch (tf::TransformException ex) {
                    ROS_ERROR("3:%s", ex.what());
                }
                float now_x = map_baselink.getOrigin().x();
                float now_y = map_baselink.getOrigin().y();
                //cout<< map_baselink.getOrigin().x()<<" ";
                //cout<< map_baselink.getOrigin().y()<<endl;
                float g_x = map_tag_transform.getOrigin().x();
                float g_y = map_tag_transform.getOrigin().y();
                goal_pose.pose.position.x = g_x;
                goal_pose.pose.position.y = g_y;
                goal_pose.pose.orientation.w = 1;
                ros::Duration(0.1).sleep();
                pub_velocity.publish(goal_pose);
                //cout<<tag_id<<endl;
//go down
                /*      if (now_x > g_x && fabs(now_y - g_y) < 0.5) {
                          for (float k = now_x; k >= g_x; k -= 0.15) {
                              //cout<<"2"<<endl;
                              y_distance = g_y;
                              x_distance = k;
                              this_pose_stamped.pose.position.x = x_distance;
                              this_pose_stamped.pose.position.y = y_distance;
                              this_pose_stamped.header.stamp=ros::Time(0);
                              this_pose_stamped.header.frame_id="map";
                              this_pose_stamped.pose.orientation.w = 1;
                              cout<<tag_id<<endl;
                              paths.poses.push_back(this_pose_stamped);
                          }
                      }
          //go forward
                      else if (now_x <= g_x && fabsf(now_y - g_y) < 0.5) {
                          for (float k = now_x; k <= g_x; k += 0.15) {
                              y_distance = g_y;
                              x_distance = k;
                              //cout<<"3"<<endl;
                              this_pose_stamped.pose.position.x = x_distance;
                              this_pose_stamped.pose.position.y = y_distance;
                              this_pose_stamped.header.stamp=ros::Time(0);
                              this_pose_stamped.header.frame_id="map";
                              this_pose_stamped.pose.orientation.w = 1;
                              cout<<tag_id<<endl;
                              paths.poses.push_back(this_pose_stamped);
                          }
                      }
          //go right
                  else if (now_y > g_y && fabsf(now_x - g_x) < 0.5) {
                          for (float k = now_y; k >= g_y; k -= 0.15) {
                              x_distance = g_x;
                              y_distance = k;
                              //cout<<"4"<<endl;
                              this_pose_stamped.pose.position.x = x_distance;
                              this_pose_stamped.pose.position.y = y_distance;
                              this_pose_stamped.header.stamp=ros::Time(0);
                              this_pose_stamped.header.frame_id="map";
                              this_pose_stamped.pose.orientation.w = 1;
                              cout<<tag_id<<endl;
                              paths.poses.push_back(this_pose_stamped);
                          }
                      }
          //go left
                     else if (now_y <= g_y && fabsf(now_x - g_x) < 0.5) {
                          for (float k = now_y; k <= g_y; k += 0.15) {
                              x_distance = g_x;
                              y_distance = k;
                              //cout<<"5"<<endl;
                              this_pose_stamped.pose.position.x = x_distance;
                              this_pose_stamped.pose.position.y = y_distance;;
                              this_pose_stamped.header.stamp=ros::Time(0);
                              this_pose_stamped.header.frame_id="map";
                              this_pose_stamped.pose.orientation.w = 1;
                              cout<<tag_id<<endl;
                              paths.poses.push_back(this_pose_stamped);
                          }
                      }*/
                cout << "000000" << endl;

                break;
            }

            float dl = exec_delay.at(count);
            if (dl == 8) {
                int putCup = putStuff.front();
                cout << "CUP: " << putCup;
                putStuff.pop();
                int putBall = putStuff.front();
                cout << "BALL: " << putBall;
                putStuff.pop();
            }
// send message to motherboard to put ball and stuff using queue
            //else
            cout << "The delay is " << exec_delay.at(count) << endl;
            ros::Duration(dl).sleep();
            count++;
            ros::spinOnce();//?
            //if(round_team!=team_id) break;


        cout << timeOptimal;
    }
    return 0;
}
