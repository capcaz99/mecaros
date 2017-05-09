
#include <ros/ros.h>
//#include <turtlesim/Pose.h>
#include <iomanip>
#include <geometry_msgs/Twist.h>
// for std :: setprecision and std :: fixed


// A callback function .  Executed each time a new pose

// message arrives .

void chatterCallback(const geometry_msgs::Twist& msg)
{
   ROS_INFO_STREAM("I heard: [%s]"<< msg.linear.x);
 }

int  main ( int  argc ,  char  **argv )  {

// Initialize the ROS system and become a node.

ros::init(argc, argv ,  "listener" ) ;

ros::NodeHandle nh ;


// Create a subscriber object .

ros::Subscriber  sub = nh.subscribe ("turtle1/cmd_vel", 1000,
	&chatterCallback) ;


// Let ROS take over .

ros::spin() ;
return 0;

}