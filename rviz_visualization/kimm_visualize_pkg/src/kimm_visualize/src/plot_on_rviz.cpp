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


typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

#define MAX_SIZE 1000
char inputString[MAX_SIZE];
int k=1;
float f = 0.0;

int main(int argc, char** argv)
{
    ros::init(argc,argv,"pcl_pub_kimm");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<PointCloud> ("points_4_map",1);

    ros::Rate loop_rate(4);

    while(true){
        std::ifstream inFile("/home/ms/mapping_4th/kimm_visualize/src/kimm_visualize/src/test_points.txt");
        while(!inFile.eof()){
            inFile.getline(inputString,100);
            std::stringstream sts(inputString);



        }


    }
    while(ros::ok())
    {
        // get xyz positions
        while(!inFile.eof()){
            inFile.getline(inputString,100);
            std::vector<std::string> vec = stringstream.ss(inputString);

            double x = atof(vec.at(0).c_str());
            double y = atof(vec.at(1).c_str());
            double z = atof(vec.at(2).c_str());
            
            if(k%4==0){
                if (z>0.0){
                    PointCloud::Ptr msg (new PointCloud);
                    msg->header.frame_id = "map";
                    msg->height = msg->width = 0.1;
                    double x_in = x-332746;
                    double y_in = y-4140894;
                    msg->points.push_back(pcl::PointXYZ(x_in,y_in,z));
                    
                    pcl_conversions::toPCL(ros::Time::now(), msg->header.stamp);
                    pub.publish(msg);
                    ros::spinOnce();
                    loop_rate.sleep();
                    }                    
                }
                else{
                    loop_rate.sleep();
                    f += 0.04;
                    }
        }
    }
}