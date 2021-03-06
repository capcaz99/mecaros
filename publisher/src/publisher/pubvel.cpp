
// This program publishes randomly


// messages for turtlesim .

#include <ros/ros.h>

#include <geometry_msgs/Twist.h>
// For geometry_msgs:: Twist


#include <stdlib.h>
// For rand() and RAND_MAX

double d;
// A callback function .  Executed each time a new pose
// message arrives .
void  poseMessageReceived ( const  geometry_msgs::Twist& msg)  {
	ROS_INFO_STREAM( std::setprecision(2) << std::fixed
	<< "Distance =(" <<  msg.linear.x << ")" );
	d = msg.linear.x;
}




int  main ( int  argc ,  char  **argv )  {

// Initialize the ROS system and become a node.

ros::init ( argc ,  argv ,  "publish_velocity" ) ;

ros::NodeHandle nh ;


// Create a publisher object .

ros::Publisher  pub = nh.advertise <geometry_msgs::Twist>("turtle1/cmd_vel" ,  1000);
ros::Subscriber  sub = nh.subscribe( "turtle1/dist" , 1000,&poseMessageReceived);

// Seed the random number generator .

srand(time (0) ) ;


// Loop at 2Hz until the node is shut down.

ros::Rate  rate (2) ;

while (ros::ok() )  {

// Create and f i l l  in the message.  The other four

// fields , which are ignored by turtlesim , default to 0.

geometry_msgs::Twist msg ;

//msg.linear.x = double ( rand () ) / double (RAND_MAX) ;
msg.linear.x = rand() % 100 + 1;
//msg.angular.z = 2*double ( rand () ) / double (RAND_MAX)-1;



// Publish the message.

pub.publish(msg);


// Send a message to rosout with the details .

ROS_INFO_STREAM( "Sending random velocity command : "

<< " linear=" << msg.linear.x

<< " angular=" << msg.angular.z) ;

ROS_INFO_STREAM( "Distance : "

<< " distance=" << d) ;

// Wait until  it 's time for another iteration .

rate . sleep () ;

}



}