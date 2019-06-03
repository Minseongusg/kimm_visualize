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

int main(int argc, char** argv)
{
    ros::init(argc,argv,"test_pub_pcl");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<PointCloud> ("points_test_map",1);

    //std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/test_points.txt");
    std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/point_conv_0214.txt");

while(1){
    inFile.getline(inputString,100);
    std::stringstream sts;
    sts << inputString;
    std::string x;
    std::string y;
    std::string z;

    sts >> x;
    sts >> y;
    sts >> z;

//    x = x-332746;
//    y = y-4140894;

    double x_ = atof(x.c_str())-332746.0;
    double y_ = atof(y.c_str())-4140894.0;
//    double x_ = atof(x.c_str())-332746.0;
//    double y_ = atof(y.c_str())-4140894.0;
    double z_ = atof(z.c_str());



    PointCloud::Ptr msg (new PointCloud);
    msg->header.frame_id = "map";
    msg->height = msg->width = 1.0;
    msg->points.push_back (pcl::PointXYZ(x_,y_,z_));

    ROS_INFO("xyz_coordinate");
    ROS_INFO("x_ : %f, y_ : %f, z_ : %f",x_,y_,z_);
    ROS_INFO("x : %s, y : %s, z : %s",x.c_str(),y.c_str(),z.c_str());

    ros::Rate loop_rate(100);
//    while(nh.ok())
//    {
        pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
        pub.publish(msg);
        ros::spinOnce ();
        loop_rate.sleep();
//    }

}


}