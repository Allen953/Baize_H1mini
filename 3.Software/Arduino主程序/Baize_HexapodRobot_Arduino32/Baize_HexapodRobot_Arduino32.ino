/*******************************************************
   主板：Baize_ServoDriver_esp32
   功能：六足机器人Arduino程序esp32主控
   引脚：SDA:21   SCL:22
   对于ARDUINO UNO，SCL:A5，SDA:A4
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
*******************************************************/
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Stepdata.h"
#define led 0
#define MAX_SRV_CLIENTS 3   //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个

const char *ssid = "Baize"; 
const char *password = "baizerobot"; 

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();               //驱动1~16或(0~15)号舵机
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);          //驱动17~32或(16~31)号舵机

WiFiServer server(8266);//你要的端口号，随意修改，范围0-65535
WiFiClient serverClients[MAX_SRV_CLIENTS];

//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552

//pwm.setPWM(i, 0, pulselen);第一个参数是通道数;第二个是高电平起始点，也就是从0开始;第三个参数是高电平终止点。

char cmd = 'e';//a:forward;   b:backward;   c:left;   d:right;   e:stop;

int rec[18] = {327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327,327};
int direct[18] = {-1,-1,-1,
-1,-1,-1,
-1,1,1,
-1,1,1,
-1,-1,-1,
-1,1,1
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("UnderWaterHexapodRobot program!");
  
  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

    for(int i=0;i<16;i++)
    {
      pwm.setPWM(i, 0, rec[i]);
      
    }
      pwm1.setPWM(0, 0, rec[16]);
      pwm1.setPWM(1, 0, rec[17]);
  delay(1000);

  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
        delay(500);
  }
  server.begin();
  server.setNoDelay(true);  //加上后才正常些

}

void loop() {

  blink();
  
  uint8_t i;
    if (server.hasClient())
    {
        for (i = 0; i < MAX_SRV_CLIENTS; i++)
        {
            if (!serverClients[i] || !serverClients[i].connected())
            {
                if (serverClients[i]) serverClients[i].stop();//未联接,就释放
                serverClients[i] = server.available();//分配新的
                continue;
            }
 
        }
        WiFiClient serverClient = server.available();
        serverClient.stop();
    }
    for (i = 0; i < MAX_SRV_CLIENTS; i++)
    {
        if (serverClients[i] && serverClients[i].connected())
        {
            digitalWrite(led, 0);//有链接存在,就一直长亮
 
            if (serverClients[i].available())
            {
                while (serverClients[i].available()) 
                cmd = serverClients[i].read();
                delay(1);
                Serial.write(serverClients[i].read());
            }
        }
    }

  
//    for(int j=0;j<120;j++)
//    {
//        for(int i=0;i<16;i++)
//        {
//          pwm.setPWM(i, 0, map(forwardF[j][i]*direct[i],-90,90,-225,225)+rec[i]);
//          
//        }
//        pwm1.setPWM(16-16, 0, map(forwardF[j][16]*direct[16],-90,90,-225,225)+rec[16]);
//        pwm1.setPWM(17-16, 0, map(forwardF[j][17]*direct[17],-90,90,-225,225)+rec[17]);
//        delay(10);
//    }

    if(cmd == 'a')//前进
    {
      for(int j=0;j<120;j++)
      {
          for(int i=0;i<16;i++)
          {
            pwm.setPWM(i, 0, map(forwardF[j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm1.setPWM(16-16, 0, map(forwardF[j][16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(forwardF[j][17]*direct[17],-90,90,-225,225)+rec[17]);
          delay(10);
      }
    }
    else if(cmd == 'b')//后退
    {
      for(int j=0;j<120;j++)
      {
          for(int i=0;i<16;i++)
          {
            pwm.setPWM(i, 0, map(forwardF[119-j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm1.setPWM(16-16, 0, map(forwardF[119-j][16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(forwardF[119-j][17]*direct[17],-90,90,-225,225)+rec[17]);
          delay(10);
      }      
      
    }
    else if(cmd == 'c')
    {
      for(int j=0;j<120;j++)
      {
          for(int i=0;i<6;i++)
          {
            pwm.setPWM(i, 0, map(forwardF[j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          for(int i=6;i<15;i++)
          {
            pwm.setPWM(i, 0, map(forwardF[119-j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm.setPWM(15, 0, map(forwardF[j][15]*direct[15],-90,90,-225,225)+rec[15]);
          pwm1.setPWM(16-16, 0, map(forwardF[j][16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(forwardF[j][17]*direct[17],-90,90,-225,225)+rec[17]);
          delay(10);
      }
    }
    else if(cmd == 'd')
    {
      for(int j=0;j<120;j++)
      {
          for(int i=0;i<6;i++)
          {
            pwm.setPWM(i, 0, map(forwardF[119-j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          for(int i=6;i<15;i++)
          {
            pwm.setPWM(i, 0, map(forwardF[j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm.setPWM(15, 0, map(forwardF[119-j][15]*direct[15],-90,90,-225,225)+rec[15]);
          pwm1.setPWM(16-16, 0, map(forwardF[119-j][16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(forwardF[119-j][17]*direct[17],-90,90,-225,225)+rec[17]);
          delay(10);
      }
    }
    else if(cmd == 'f')//右横移前进
    {
      for(int j=0;j<120;j++)
      {
          for(int i=0;i<16;i++)
          {
            pwm.setPWM(i, 0, map(forwardFHer[j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm1.setPWM(16-16, 0, map(forwardFHer[j][16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(forwardFHer[j][17]*direct[17],-90,90,-225,225)+rec[17]);
          delay(10);
      }
    }
    else if(cmd == 'g')//左横移前进
    {
      for(int j=0;j<120;j++)
      {
          for(int i=0;i<16;i++)
          {
            pwm.setPWM(i, 0, map(forwardFHer[119-j][i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm1.setPWM(16-16, 0, map(forwardFHer[119-j][16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(forwardFHer[119-j][17]*direct[17],-90,90,-225,225)+rec[17]);
          delay(10);
      }      
      
    }
    else
    {
      delay(100);
    }
}

void blink()
{
    static long previousMillis = 0;
    static int currstate = 0;
 
    if (millis() - previousMillis > 200)  //200ms
    {
        previousMillis = millis();
        currstate = 1 - currstate;
        digitalWrite(led, currstate);
    }
}
