#include <SPI.h>
#include <LoRa.h>

#define NSS 10
#define RESET 9
#define DIO0 2

void setup() {
  Serial.begin(9600);
    LoRa.setPins(NSS, RESET, DIO0);
  while (!Serial);  //等待序列埠起始完畢
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) { //起始 LoRa
    Serial.println("Starting LoRa failed!");
    while (1);
    }
  }

void loop() {
  int packetSize=LoRa.parsePacket(); //讀取剖析 LoRa 封包大小
  if (packetSize) { //若有封包進來
    Serial.print("Received packet '");
    while (LoRa.available()) { //若接收緩衝器有內容
      Serial.print((char)LoRa.read());  //讀取緩衝器內容並輸出階收到的封包
      }  
    Serial.print("' with RSSI="); //輸出接收封包之 RSSI
    Serial.print(LoRa.packetRssi());  //顯示接收信號強度
    Serial.print(" and SNR="); //輸出接收封包之 SNR (信噪比)
    Serial.println(LoRa.packetSnr());  //顯示接收信號信噪比
    }
  }
