#include <ros.h>             //ROS arduino library
#include <std_msgs/String.h> //message type of String

ros::NodeHandle  nh;         //create a handler for this node

int led_pin = 13;

void messageCb(std_msgs::String& toggle_msg) { //enter this function whenever the topic_msg is being updated
    if (String(toggle_msg.data) == "1") {      //turn on LED when message is 1
      digitalWrite(led_pin, HIGH);
    }
    if (String(toggle_msg.data) == "0") {      //turn on LED when message is 0
      digitalWrite(led_pin, LOW);
    }
}

ros::Subscriber<std_msgs::String> sub("toggle_led", messageCb ); //subcribe to topic called "toggle_led" of message type String, enter callback function "messageCb" whenever topic is updated

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);   //set pin 13 as output
  nh.initNode();              //initialise node
  nh.subscribe(sub);          //set "sub" as node's subscriber
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();  //check if topics are being updated
  delay(1);
}
