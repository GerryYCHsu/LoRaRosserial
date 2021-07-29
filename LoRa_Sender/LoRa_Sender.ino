#include <ros.h>
#include <ros/time.h>
#include <nav_msgs/Odometry.h>
#include <SPI.h>
#include <LoRa.h>

#define NSS 10
#define RESET 9
#define DIO0 2
int counter=0;  //傳送次數計數器

ros::NodeHandle nh;
ros::Time rosNow(void);
ros::Time addMicros(ros::Time & t, uint32_t _micros); 

void OdomCallback(const nav_msgs::Odometry& odomMsgs){
  //Serial.print("Sending packet: ");
  //Serial.println(counter);
  
  LoRa.beginPacket();  //封包傳送開始
  LoRa.print(odomMsgs.pose.covariance);  //封包內容
  LoRa.print(counter);  //封包內容
  LoRa.endPacket();  //封包傳送結束
  counter++;  //計數器增量 1
}

//nav_msgs::Odometry OdomMsgs;
ros::Subscriber<nav_msgs::Odometry> OdomSubscriber("odom", &OdomCallback);

void setup() {
  Serial.begin(9600);
  LoRa.setPins(NSS, RESET, DIO0);
  while (!Serial);  //等待序列埠起始完畢
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) {  //起始 433MHz LoRa
    Serial.println("Starting LoRa failed!");
    while (1);
    }
  }

void loop() {
  nh.spinOnce();
  delay(5000);
  }
