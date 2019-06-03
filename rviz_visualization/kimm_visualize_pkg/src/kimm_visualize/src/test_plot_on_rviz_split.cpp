#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <set>
#include <fstream>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

#define MAX_SIZE 1000
char inputString[MAX_SIZE];
int ros_pub_rate = 10000;

int main(int argc, char** argv)
{
    ros::init(argc,argv,"test_pub_pcl");
    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<PointCloud> ("points_test_map1",1);
    ros::Publisher pub2 = nh.advertise<PointCloud> ("points_test_map2",1);
    ros::Publisher pub3 = nh.advertise<PointCloud> ("points_test_map3",1);
    ros::Publisher pub4 = nh.advertise<PointCloud> ("points_test_map4",1);

    //std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/test_points.txt");
    std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/point_conv_0214.txt");
    int k = 0;

while(1){
    if (k%4==1){
        inFile.getline(inputString,100);
        std::stringstream sts;
        sts << inputString;
        std::string x;
        std::string y;
        std::string z;

        sts >> x;
        sts >> y;
        sts >> z;

        double x_ = atof(x.c_str())-332746.0;
        double y_ = atof(y.c_str())-4140894.0;
        double z_ = atof(z.c_str());



        PointCloud::Ptr msg (new PointCloud);
        msg->header.frame_id = "map";
        msg->height = msg->width = 1.0;
        msg->points.push_back (pcl::PointXYZ(x_,y_,z_));
        
        ros::Rate loop_rate(ros_pub_rate);
        pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
        pub1.publish(msg);
        ros::spinOnce ();
        loop_rate.sleep();
    }

    if (k%4==2){
        inFile.getline(inputString,100);
        std::stringstream sts;
        sts << inputString;
        std::string x;
        std::string y;
        std::string z;

        sts >> x;
        sts >> y;
        sts >> z;

        double x_ = atof(x.c_str())-332746.0;
        double y_ = atof(y.c_str())-4140894.0;
        double z_ = atof(z.c_str());



        PointCloud::Ptr msg (new PointCloud);
        msg->header.frame_id = "map";
        msg->height = msg->width = 1.0;
        msg->points.push_back (pcl::PointXYZ(x_,y_,z_));
        
        ros::Rate loop_rate(ros_pub_rate);
        pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
        pub2.publish(msg);
        ros::spinOnce ();
        loop_rate.sleep();
    }

        if (k%4==3){
        inFile.getline(inputString,100);
        std::stringstream sts;
        sts << inputString;
        std::string x;
        std::string y;
        std::string z;

        sts >> x;
        sts >> y;
        sts >> z;

        double x_ = atof(x.c_str())-332746.0;
        double y_ = atof(y.c_str())-4140894.0;
        double z_ = atof(z.c_str());



        PointCloud::Ptr msg (new PointCloud);
        msg->header.frame_id = "map";
        msg->height = msg->width = 1.0;
        msg->points.push_back (pcl::PointXYZ(x_,y_,z_));
        
        ros::Rate loop_rate(ros_pub_rate);
        pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
        pub3.publish(msg);
        ros::spinOnce ();
        loop_rate.sleep();
    }

        if (k%4==0){
        inFile.getline(inputString,100);
        std::stringstream sts;
        sts << inputString;
        std::string x;
        std::string y;
        std::string z;

        sts >> x;
        sts >> y;
        sts >> z;

        double x_ = atof(x.c_str())-332746.0;
        double y_ = atof(y.c_str())-4140894.0;
        double z_ = atof(z.c_str());

        PointCloud::Ptr msg (new PointCloud);
        msg->header.frame_id = "map";
        msg->height = msg->width = 1.0;
        msg->points.push_back (pcl::PointXYZ(x_,y_,z_));
        
        ros::Rate loop_rate(ros_pub_rate);
        pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
        pub4.publish(msg);
        ros::spinOnce ();
        loop_rate.sleep();
    }

    k++;
}


}