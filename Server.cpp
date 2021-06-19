/* This is an frame of a Server         	                                    */
/* Server      : Receive the request, process the request, send back a response */
/* Service     : AddInts                                                        */
/* Srv file    : beginner_tutorials::AddTwoInts                                 */


/* Basic Procedure */
/* 1. Include head files
   2. Initialize ROS node  
   3. Instantiate a node handler and creat an server object

*/


// 1. Include head files
// <name of the package>/<name of the srv file that used>.h
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"

/* Input Parameter: <name of the package>::<name of the srv file that used> &req
                    <name of the package>::<name of the srv file that used> &res
	req object have members of the request
	res object have members of the response
*/
bool addCallBack(beginner_tutorials::AddTwoInts::Request  &req,
				 beginner_tutorials::AddTwoInts::Response &res)
{
  res.sum = req.num1 + req.num2;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.num1, (long int)req.num2);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}


int main(int argc, char*argv[])
{
	// 2. Initialize ROS node (with the name of the node)
	ros::init(argc, argv, "add_two_ints_client");
	ros::NodeHandle n;
	
	// 3. Instantiate a node handler and creat an object
	// Service: "AddInts" which is consistent with the service request by client
	// addCallBack is the name of the callBack function to process the request
	ros::ServiceServer server = n.advertiseService("AddInts", addCallBack);
	ROS_INFO("Ready to add two ints.");
	ros::spin();
	

  return 0;
}