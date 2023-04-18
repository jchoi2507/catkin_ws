/*
keyboard_node.cpp
By: Jacob Choi
Date: 4/18/2023

- Allows keyboard control of the quadruped, specifically:
	- 'f' input: forward
	- 's' input: stop
	- 'r' input: turn right
	- 'l' input: turn left
	- 'd' input: dance!
- Under the hood: publishes appropriate character to the topic: /topic_actuate
*/

#include <ros/ros.h>
#include <std_msgs/Char.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	ros::init(argc, argv, "keyboard_node");
	ros::NodeHandle node_handle;
	ros::Publisher publisher = node_handle.advertise<std_msgs::Char>("topic_actuate", 1);
	ros::Rate rate(10);

	std::string input; // cin input stream variable
	std_msgs::Char msg; // message-type variable to publish to topic

	ROS_INFO("f/s/r/l/d");

	while (ros::ok()) {
		std::cin >> input;
		msg.data = input[0]; // Converting <string> to <char>
		publisher.publish(msg);
		ROS_INFO("Message sent: %c", msg.data);
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
