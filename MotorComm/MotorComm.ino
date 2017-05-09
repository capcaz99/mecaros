/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh;
geometry_msgs::Twist msg;
//std_msgs::String str_msg;
ros::Publisher chatter("chatter", &msg);
float m;
void messageCb( const geometry_msgs::Twist& mymessage){
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
   m = mymessage.linear.x;
  
}
ros::Subscriber<geometry_msgs::Twist> sub("turtle1/cmd_vel", &messageCb );

void setup()
{
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatter);
}

void loop()
{
 
  msg.linear.x= m;
  chatter.publish( &msg );
  nh.spinOnce();
  delay(1000);
}
