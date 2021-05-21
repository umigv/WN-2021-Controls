#include <ros/ros.h>
#include <stdlib.h>
#include <geometry_msgs/Point32.h>
#include <geometry_msgs/Polygon.h>
#include <string>
#include "Obstacles.h"
#include "Segmentobstacles.h"
#include "Circleobstacles.h"


std::vector<geometry_msgs::Point32> first_points;
std::vector<geometry_msgs::Point32> last_points;
std::vector<geometry_msgs::Point32> centers;
std::vector<double> radius;
std::vector<geometry_msgs::Polygon> zonotope_visual;

void obstaclesCallback(const Obstacles& obs) {
	seg_size = obs.segments.size();
	for(int i = 0; i<seg_size; i++) {
        first_points.push_back(obs.segments[i].first_point);
        last_points.push_back(obs.segments[i].last_point);
	}
    cir_size = obs.circles.size();
    for(int i = 0; i<cir_size; i++) {
        centers.push_back(obs.circles[i].center);
        radius.push_back(obs.circles[i].radius);
    }
} // obstaclesCallback

int main(int argc, char** argv) {

	ros::init(argc, argv, "obstacle_converter");
	ros::NodeHandle nh_pub;
    ros::NodeHandle nh_pub2;
	ros::Publisher pub = nh_pub.advertise<std::vector::geometry_msgs::Polygon>("/rover8/zonotope_visualization", 1000);
    //ros::Publisher pub2 = nh_pub2.advertise<zonotope []>("/rover8/zonotope", 1000);
	ros::Subscriber sub = nh_pub.subscribe("/rover8/Obstacles", 1000, obstaclesCallback);
    ros::Rate loop_rate(10)
    while(ros::ok()) {
        for(int i = 0, i<first_points.size(), i++) {
            geometry_msgs::Polygon = g;
            geometry_msgs::Point32[] = arr;
            geometry_msgs::Point32 = p1;
            geometry_msgs::Point32 = p2;
            arr[0] = p1;
            arr[1] = p2;
            g.points = arr;
            zonotope_visual.push_back(g);
        }
        for(int j = first_points.size(), j<centers.size() j++)
            geometry_msgs::Polygon = g;
            geometry_msgs::Point32[] = arr;
            geometry_msgs::Point32 = c;
            geometry_msgs::Point32 = p1;
            geometry_msgs::Point32 = p2;
            geometry_msgs::Point32 = p3;
            geometry_msgs::Point32 = p4;
            geometry_msgs::Point32 = p5;
            geometry_msgs::Point32 = p6;
            double r;
            r = radius[j]; 
            c = centers[j];
            p1.x = c.x - r;
            p1.y = c.y + r/sqrt(3);
            p2.x = c.x;
            p2.y = c.y + (2*r)/sqrt(3);
            p3.x = c.x + r;
            p3.y = c.y + r/sqrt(3);
            p4.x = c.x + r;
            p4.y = c.y + r/sqrt(3);
            p5.x = c.x;
            p5.y = c.y - (2*r)/sqrt(3);
            c6.x = c.x - r;
            p6.y = c.y - r/sqrt(3);
            arr[0] = p1;
            arr[1] = p2; 
            arr[2] = p3;
            arr[3] = p4;
            arr[4] = p5;
            arr[5] = p6;
            g.points = arr;
            zonotope_visual.push_back(g);
        }
        pub.publish(zonotope_visual);
        ros::spinOnce();
        loop_rate.sleep()
    }
    return 0;
}





