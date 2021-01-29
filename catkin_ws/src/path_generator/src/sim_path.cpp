#include <ros/ros.h>
#include <stdlib.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <turtlesim/Pose.h>
#include <string>

//geometry_msgs::PoseStamped arr[1000];
std::vector<geometry_msgs::PoseStamped> vec;
int size = 0;
double cur_x = 5.544;
double cur_y = 5.544;
double cur_theta = 0;

void pathCallback(const nav_msgs::Path& msg) {
	size = msg.poses.size();
	for(int i = 0; i<size; i++) {
		vec.push_back(msg.poses[i]);
	}
} // pathCallback()

void poseCallback(const turtlesim::Pose& msg) {
	cur_x = msg.x;
	cur_y = msg.y;
	cur_theta = msg.theta;
}
int main(int argc, char** argv){

	ros::init(argc, argv, "sim_path");
	ros::NodeHandle nh_pub;
	ros::Publisher pub = nh_pub.advertise<geometry_msgs::Pose>("turtle1/target", 1000);
	ros::Subscriber sub1 = nh_pub.subscribe("turtle1/path", 1000, pathCallback);
	ros::Subscriber sub2 = nh_pub.subscribe("turtle1/pose", 1000, poseCallback);
	ros::Rate loop_rate(10);
	int count = 0;
	while(ros::ok()) {
		if(!(vec.empty())){
			geometry_msgs::Pose p;
			geometry_msgs::Point p1;
			p = vec[count].pose;
			p1 = p.position;
			if((abs(cur_x - p1.x)<=0.1) && (abs(cur_y - p1.y)<=0.1)) {
				if(count < size-1) {
					count++;
				}
			}
			pub.publish(p);	
		}
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;

}
