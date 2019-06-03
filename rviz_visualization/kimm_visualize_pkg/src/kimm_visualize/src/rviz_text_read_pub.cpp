#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

std::vector<std::string> split(std::string target, std::string delimiter){
    std::vector<std::string> result;
    int position = target.find(delimiter);

    while (position !=-1){
        std::string str1 = target.substr(0,position);
        result.push_back(str1);
        target = target.substr(position+1);
        position = target.find(delimiter);
    }
    result.push_back(target);
    return result;
}

#define MAX_SIZE 1000
char inputString[MAX_SIZE];
int k=1;



int main (int argc, char** argv )
{
    ros::init(argc, argv, "points_and_lines");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",10);

    ros::Rate r(1000);

    float f = 0.0;
    while (ros::ok())
    {
        visualization_msgs::Marker points, line_strip, line_list;
        points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id="/map";
        points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
        points.ns = line_strip.ns = line_list.ns = "points_and_lines";
        points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
        points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w=1.0;

        points.id = 0;
        line_strip.id = 1;
        line_list.id = 2;

        points.type = visualization_msgs::Marker::POINTS;
        line_strip.type = visualization_msgs::Marker::LINE_STRIP;
        line_list.type = visualization_msgs::Marker::LINE_LIST;

        // POINTS markers use x and y scale for width/height respectively
        points.scale.x = 0.2;
        points.scale.y = 0.2;
        
        // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
        line_strip.scale.x = 0.1;
        line_list.scale.x = 0.1;

        // Points are green
        points.color.g = 1.0f;
        points.color.a = 1.0;

        // Line strip is blue
        line_strip.color.b = 1.0;
        line_strip.color.a = 1.0;

        // Line list is red
        line_list.color.r = 1.0;
        line_list.color.a = 1.0;


        //Open txt_file
        std::ifstream inFile("/home/uasg/rviz_testpkg/src/kimm_rviz_plot/src/point_conv_0214.txt");
        
        //get xyz positions
        while(!inFile.eof()){
        inFile.getline(inputString, 100);
        std::vector<std::string> vec = split(inputString," ");
        
        double x = atof(vec.at(0).c_str());
        double y = atof(vec.at(1).c_str());
        double z = atof(vec.at(2).c_str());
        if (k%4==0){

            if (z>0.0){
            geometry_msgs::Point p;
            p.x = x-332746;
            p.y = y-4140894;
            p.z = z;

            points.points.push_back(p);
            line_strip.points.push_back(p);

            marker_pub.publish(points);
            //marker_pub.publish(line_strip);
            //marker_pub.publish(line_list);

            r.sleep();
            f += 0.04;
            }
            else{
            r.sleep();
            f += 0.04;
         }
        }
        else {
            r.sleep();
            f += 0.04;
            }
            k=k+1;
        }

    }
}