#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Quaternion.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <fstream>

double cur_x = 5.544;
double cur_y = 5.544;
double cur_theta = 0;

double p_x = 5.544;
double p_y = 5.544;
double p_z = 0;


// update pose then genearte next /cmd_vel
void poseCallback(const turtlesim::Pose& msg) {

    cur_x = msg.x;
    cur_y = msg.y;
    cur_theta = msg.theta;

    ROS_INFO_STREAM("updating pose");
    ROS_INFO_STREAM(cur_x);
    ROS_INFO_STREAM(cur_y);
    ROS_INFO_STREAM(cur_theta);

} // poseCallback()


void targetCallback(const geometry_msgs::Pose& msg) {
    
    geometry_msgs::Point p_tar = msg.position;
    p_x = p_tar.x;
    p_y = p_tar.y;
    p_z = p_tar.z;

    ROS_INFO_STREAM("updating path target");
    ROS_INFO_STREAM(p_x);
    ROS_INFO_STREAM(p_y);
    ROS_INFO_STREAM(p_z);

} // targetCallback()

int main(int argc, char** argv){

    ros::init(argc, argv, "sim_controller");    
    ros::NodeHandle nh_pub;
    ros::Rate loop_rate(10);
    
    ros::Publisher pub = nh_pub.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    ros::Subscriber sub1 = nh_pub.subscribe("turtle1/pose", 1000, poseCallback);
    
    ros::Subscriber sub2 = nh_pub.subscribe("turtle1/target", 1000, targetCallback);
    
    //int index = 0;
    while (ros::ok()) {
	/*if(index >= path.size()) {
    		geometry_msgs::Twist t;
    		pub.publish(t);
		break;
	}
	*/
	//float theta = atan((path[index].y-cur_y)/(path[index].x-cur_x)) - cur_theta;
	float theta = atan((p_y-cur_y)/(p_x-cur_x)) - cur_theta;
    	geometry_msgs::Twist t;
	if(abs(theta)>=0.02) {
		t.angular.z = theta;
		pub.publish(t);
	}else{
		t.linear.z = 0;
		pub.publish(t);
		if(abs(cur_x - p_x) < 0.1 &&abs(cur_y - p_y) < 0.1) {
			ROS_INFO_STREAM("Arrive A Goal");
			//++index;
		}else{
  			t.linear.x = p_x - cur_x;
    			//t.linear.y = path[index].y - cur_y;
    			pub.publish(t);
		}
	}
    		
    		// also check if you hit the target yet, otherwise, you would go past it unnoticed
    		
    	ros::spinOnce();
    	loop_rate.sleep();
  	}
    
	
	return 0;
	
}
