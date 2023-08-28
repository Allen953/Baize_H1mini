/*******************************************************
   主板：Baize_ServoDriver_esp8266
   功能：Baize_H1mini六足机器人Arduino程序
   引脚：SDA:21   SCL:22
   对于ARDUINO UNO，SCL:A5，SDA:A4
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-08-22
*******************************************************/
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "StepData.h"
#define led 2               //led为低电平时，灯亮；高电平时，灯灭
#define MAX_SRV_CLIENTS 3   //最大同时联接数，即你想要接入的设备数量，8266tcpserver只能接入五个
#define del 100
#define deltr 3

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

//a:前进; b:后退; c:左转; d:右转; e:停止; f:向左横行 g:向右横行 h:步态切换 i:身高切换；
//last_cmd表示上一个指令，可以表示机器人状态。
char cmd = 'e',last_cmd = 'e';
//gait表示步态，1为波动步态，0为三角步态；body表示身高，0为最低，1为中间，2为最高;robotstatus为机器人状态，
int gait=0,body=0,robotstatus=0;
int rec[18] = {
  327,327,327,
  335,335,327,
  327,327,327,
  327,327,327,
  327,327,327,
  327,327,327
};
int direct[18] = {-1,1,1,
-1,1,1,
-1,1,1,
-1,1,1,
-1,1,1,
-1,1,1
};

//舵机执行函数，通过执行该函数，将会驱动18个舵机运动至s[18]数组传递的角度位置
void DireceServo(float s[18])
{
          for(int i=0;i<16;i++)
          {
            pwm.setPWM(i, 0, map(s[i]*direct[i],-90,90,-225,225)+rec[i]);
            
          }
          pwm1.setPWM(16-16, 0, map(s[16]*direct[16],-90,90,-225,225)+rec[16]);
          pwm1.setPWM(17-16, 0, map(s[17]*direct[17],-90,90,-225,225)+rec[17]);

          //如果想要更改舵机插口，需要写如下代码并把本函数内上方代码全部注释掉
          //舵机如果插在0-15号引脚，调用下面这个代码，m是板子上的接口号，i是机器人的关节号
          //pwm.setPWM(m, 0, map(s[i]*direct[i],-90,90,-225,225)+rec[i]);
          //舵机如果插在16-31号引脚，调用下面这个代码，m是板子上的接口号，i是机器人的关节号
          //pwm1.setPWM(m-16, 0, map(s[i]*direct[i],-90,90,-225,225)+rec[i]);
};

void iic_device_test()//扫描iic芯片，如果开机闪烁一次，说明是0x40未扫描到；如果闪烁两次，则是0x41未扫描到。
{
  bool iic_flag[2];//定义一个iic标志数组用于表示iic扫描结果
  Wire.beginTransmission(0x40);
  if(Wire.endTransmission()!=0)//0是扫描到设备了，非0是未扫描到设备。
  while(1)
  {
    digitalWrite(led,0);
    delay(100);
    digitalWrite(led,1);
    delay(1000);
  }
  Wire.beginTransmission(0x41);
  if(Wire.endTransmission()!=0)//0是扫描到设备了，非0是未扫描到设备。
  while(1)
  {
    digitalWrite(led,0);
    delay(100);
    digitalWrite(led,1);
    delay(100);
    digitalWrite(led,0);
    delay(100);
    digitalWrite(led,1);
    delay(1000);
  }
};

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);//led为低电平时，灯亮；高电平时，灯灭
  Serial.begin(115200);
  Serial.println();
  Serial.println("Baize_HexapodRobot program!");

  Wire.begin();//开启IIC通信
  iic_device_test();
  
  
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
      ESP.wdtFeed();                    //喂狗防止复位
  delay(100);
  
  
  digitalWrite(led, 0);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
        delay(500);
        Serial.print(".");
  }
  server.begin();
  server.setNoDelay(true);  //加上后才正常些


  delay(1000);
  DireceServo(forward[0]);

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

    if(cmd == 'a')          //前进
    {
      if(gait==0)//如果是三角步态
      {
          for(int j=0;j<40;j++)
          {
              DireceServo(forward[j]);
              ESP.wdtFeed();                    //喂狗防止复位
              delay(deltr);
          }
      }
      else if(gait==1)//如果是波动步态
      {
          for(int j=0;j<120;j++)
          {
              DireceServo(forwardF[j]);
              ESP.wdtFeed();                    //喂狗防止复位
              delayMicroseconds(del);
          }
      }
//        for(int j=0;j<120;j++)
//          {
//              DireceServo(forwardF[j]);
//              ESP.wdtFeed();                    //喂狗防止复位
//              delayMicroseconds(del);
//          }
    }
    else if(cmd == 'b')//后退
    {
      if(gait==0)//如果是三角步态
      {
          for(int j=0;j<40;j++)
          {
              DireceServo(forward[39-j]);
              ESP.wdtFeed();                    //喂狗防止复位
              delay(deltr);
          }
      }
      else if(gait==1)//如果是波动步态
      {
          for(int j=0;j<120;j++)
          {
              DireceServo(forwardF[119-j]);
              ESP.wdtFeed();                    //喂狗防止复位
              delayMicroseconds(del);
          }
      }
//          for(int j=0;j<120;j++)
//          {
//              DireceServo(forwardF[119-j]);
//              ESP.wdtFeed();                    //喂狗防止复位
//              delayMicroseconds(del);
//          }
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
          
          ESP.wdtFeed();                    //喂狗防止复位
          delayMicroseconds(del);
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
          
          ESP.wdtFeed();                    //喂狗防止复位
          delayMicroseconds(del);
      }
      
    }
    else if(cmd == 'f')//向左横移
    {
      for(int j=0;j<120;j++)
      {
          DireceServo(forwardFH[j]);
          ESP.wdtFeed();                    //喂狗防止复位
          delayMicroseconds(del);
      }
    }
    else if(cmd == 'g')//向右横移
    {
      for(int j=0;j<120;j++)
      {
          DireceServo(forwardFH[199-j]);
          ESP.wdtFeed();                    //喂狗防止复位
          delayMicroseconds(del);
      }      
    }
    else if(cmd == 'h')//切换步态
    {
      gait=!gait;
    }
    else if(cmd == 'i')//切换身高
    {
      i++;
      i=i%3;
    }
    else if(cmd == 'j')//原地蹲起
    {
          for(int j=0;j<40;j++)
          {
              DireceServo(dunqi[j]);
              delay(deltr*10);
              ESP.wdtFeed();                    //喂狗防止复位
              
          }
    }
    else
    {
      delay(100);
      ESP.wdtFeed();                    //喂狗防止复位
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
