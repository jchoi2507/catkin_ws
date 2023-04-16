/*
Nicla_node.cpp
By: Jacob Choi
Date: 4/15/2023

- The node in this file can be thought of as a Arduino Nicla node on the ROS network
	- In reality, it only exists in the RPi and interfaces with the Nicla over serial
- Initializes a publisher node to publish to topic: "topic_actuate"
- Receives data from Arduino Nicla over UART serial
- Publishes data to "topic_actuate"
*/

#include <ros/ros.h>
#include <std_msgs/Char.h>
#include <iostream>
#include <wiringSerial.h>
#include <string>

using namespace std;

/* Serial USB Connection from Arduino Nicla Setup */
const char *port_connection = "/dev/tty[SOMETHING]";
int baudrate = 9600;
int serialDeviceID = serialOpen(port_connection, baudrate);

int main(int argc, char** argv) {
	ros::init(argc, argv, "Nicla_node"); // Initialize node called "Nicla_node"
	ros::NodeHandle node_handle;
	ros::Publisher publisher = node_handle.advertise<std_msgs::Char>("topic_actuate", 1); // Topic name, publisher queue size
	ros::Rate rate(10); // 10 Hz

	if (serialDeviceID == -1) {std::cerr << "Unable to open serial device." << std::endl; return 1;}
	char input; // This var will store the serially transmitted char from the Nicla
	std_msgs::Char msg; // This var is the actual message being sent to the topic
	bool keepReading = true; // This var determines when to stop reading from serial

	while (ros::ok()) {
		while (keepReading) {
			if (serialDataAvail(serialDeviceID) > 0) {
				input = serialGetchar(serialDeviceID);
				if (input == '\n') {} // Terminating byte read, ignore current iteration
				else {
					ROS_INFO("Message sending: %c", input);
					msg.data = input;
					keepReading = false;
				}
			}
		}
		publisher.publish(msg);
		keepReading = true;
		ros::spinOnce(); // Allows for backend to update on every iteration
		rate.sleep();  // Maintains the 10 Hz message publishing rate
	}
	return 0;
}
