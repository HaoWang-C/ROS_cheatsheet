/* This is frame of a publisher                  */
/* Publisher                                     */
/* Publish to topic   : "/turtle1/cmd"           */
/* Message type       : "geometry_msgs::Twist" 	 */

/* Basic Procedure */
/* 1. Include head files
   2. Initialize ROS node  
   3. Instantiate a node handler
   4. Use a method of the node handler to instantiate an object as publisher
   5. Instantiate the message object
   6. Setup loop rate
   7. Enter the endless lope and publish msg
   8. Use spin function to check the callback function(don't need in this case)
*/


// 1. Include head files
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char*argv[])
{
	// 2. Initialize ROS node
	ros::init(argc, argv, "circle_ctrl");
	// 3. Instantiate a node handler
	ros::NodeHandle n;
	
	// 4. Use a method of the node handler to instantiate an object as publisher
	// In this case, "geometry_msgs::Twist" is msg type, "/turtle1/cmd_vel" is the topic name(subscriber need to subscrib the same topic)	
	ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
	ROS_INFO("start to draw circle...");
	
	// 5. Instantiate the message object
	geometry_msgs::Twist speed;
	
	// 6. Setup loop rate
	// In this case, looprate is 2HZ
	ros::Rate loopRate(2);
	
	//7. Enter the endless lope and publish msg
	while(ros::ok())
	{
    
    speed.linear.x = 2.0;
    speed.angular.z = 1.2;
	
    vel_pub.publish(speed);

    // 8. Deal with callback function, in this function we don't have one, wirte here just for learning how to use it
	ros::spinOnce();
	loopRate.sleep();
	}	
}