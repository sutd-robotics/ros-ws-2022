#include <ros.h>               //ROS arduino Library
#include <std_msgs/String.h>   //message type of String

ros::NodeHandle  nh;           //create a handler for this node

std_msgs::String str_msg;      //create variable call "str_msg" of type std_msgs::String
ros::Publisher pub("button_status", &str_msg); //create a publisher object call "pub", publish a topic call "chatter", with the message being "str_msg"

int button_pin = 2;

void setup()
{
  pinMode(button_pin, INPUT);
  nh.initNode();               //initialise node
  nh.advertise(pub);       //set "chatter" as node's publisher
}

void loop()
{
  if (digitalRead(button_pin) ==  HIGH){ //check if button is pressed
    str_msg.data = "pressed";
  }
  else{
    str_msg.data = "not pressed";
  }
  pub.publish( &str_msg ); //publish topic
  nh.spinOnce();               //update ros
  delay(500);
}
