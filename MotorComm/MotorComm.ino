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
ros::Publisher chatter("turtle1/dist", &msg);

float m;

int m1enable = 22;
int m2enable = 24;
int m1forward = 2; //pwm
int m1reverse = 3; //pwm
int m2forward = 4; //pwm
int m2reverse = 5; //pwm
int mlforwardspeed;

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
   pinMode(m1enable, OUTPUT);
   pinMode(m2enable, OUTPUT);
   pinMode(m1forward, OUTPUT);
   pinMode(m1reverse, OUTPUT);
   pinMode(m2forward, OUTPUT);
   pinMode(m2reverse, OUTPUT);
}

void loop()
{
   digitalWrite(m1enable,HIGH);
   digitalWrite(m2enable,HIGH);
   
  msg.linear.x= m; //guardar en el mensaje a enviar la distancia
  mlforwardspeed = (int)m;
 analogWrite(m1forward, mlforwardspeed);
 analogWrite(m2reverse, mlforwardspeed);
  chatter.publish( &msg );
  nh.spinOnce();
  delay(1000);
}
