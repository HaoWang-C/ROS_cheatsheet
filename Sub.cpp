/* This is an frame of a Subscriber          */
/* Subscriber                                */
/* subscribe to topic : "chatter"            */
/* Message type       : "std_msgs::String"   */

/* Basic Procedure */
/* 1. Include head files
   2. Initialize ROS node  
   3. Instantiate a node handler
   4. Use a method of the node handler to instantiate an object as subscriber

*/


// 1. Include head files
#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  // This is the important function that process the data received
  // The input parameter is decied by the message type of the subscribed topic
}



int main(int argc, char*argv[])
{
	// 2. Initialize ROS node (with the name of the node)
	ros::init(argc, argv, "listener");
	// 3. Instantiate a node handler
	ros::NodeHandle n;
	
	// 4. Use a method of the node handler to instantiate an object as subscriber
	// In this case, "std_msgs::String" is msg type, "chatter" is the topic name(subscriber need to subscrib the same topic)	
	// chatterCallBack is the name of the callback function
	ros::Publisher sub = n.subscribe<std_msgs::String>("chatter",10,chatterCallBack);
	
	// In this ros::spin() function, the program will check if there is any msgs in buffer, if there are msgs, it will jump to
	// the callback function
	ros::spin();
	}	
}