#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
ros::NodeHandle nh;
float z;
geometry_msgs::Twist x;

int m1enable = 22;
int m2enable = 24;
int m1forward = 2; //pwm
int m1reverse = 3; //pwm
int m2forward = 4; //pwm
int m2reverse = 5; //pwm
int mlforwardspeed;
void cmd_vel( const geometry_msgs::Twist& t){

//Serial.print("Robot(%.2f,%.2f)",t.linear.x, t.angular.z);
mlforwardspeed = (int) t.linear.x;
}

ros::Subscriber<geometry_msgs::Twist> sub("turtle1", &cmd_vel);


//std_msgs::String str_msg;
ros::Publisher chatter("chatter", &x);

//char hello[13] = "hello world!";

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
nh.initNode();
nh.subscribe(sub);
nh.advertise(chatter);
Serial.begin(57600);
 pinMode(m1enable, OUTPUT);
 pinMode(m2enable, OUTPUT);
 pinMode(m1forward, OUTPUT);
 pinMode(m1reverse, OUTPUT);
 pinMode(m2forward, OUTPUT);
 pinMode(m2reverse, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //str_msg.data = hello;
  chatter.publish( &x );
   //enable m1
 digitalWrite(m1enable,HIGH);
 digitalWrite(m2enable,HIGH);
 
 //set a pwm pulse on m1forward;
 analogWrite(m1forward, mlforwardspeed);
 analogWrite(m2reverse, mlforwardspeed);
 
  nh.spinOnce();
  delay(10000);
  //Serial.print(x);

}
