/*******************************************************
   硬件：Baize_ServoDriver_esp32
   功能：KeyControl_Servo,通过按键校准机器人关节
   引脚：key1:35    key2:34    key3:39    key4:36
   Designer: Allen
   E-mail:953598974@qq.com
   Date:2022-09-20 16:39
*******************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include <TFT_eSPI.h>
//四个按键，按下后由低电平变为高电平
#define key1 35
#define key2 34
#define key3 39
#define key4 36

//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();               //驱动1~16或(0~15)号舵机
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);          //驱动17~32或(16~31)号舵机

TFT_eSPI TFT = TFT_eSPI();
//定义一个按键结构体，用于描述四个按键的各种属性和状态
struct keyStruct{
  String name;
  int pin;
  bool lastStatus;
};

keyStruct key[4]={
  "Key 1",35,0,
  "Key 2",34,0,
  "Key 3",39,0,
  "Key 4",36,0
};
//定义一个舵机结构体，用于描述32个舵机的各种属性和状态
struct servoStruct{
  String name;
  int num;
  bool lastStatus;
};

servoStruct servo[32]={
  "Servo 1:",SERVOMID,0,"Servo 2:",SERVOMID,0,"Servo 3:",SERVOMID,0,"Servo 4:",SERVOMID,0,
  "Servo 5:",SERVOMID,0,"Servo 6:",SERVOMID,0,"Servo 7:",SERVOMID,0,"Servo 8:",SERVOMID,0,
  "Servo 9:",SERVOMID,0,"Servo 10:",SERVOMID,0,"Servo 11:",SERVOMID,0,"Servo 12:",SERVOMID,0,
  "Servo 13:",SERVOMID,0,"Servo 14:",SERVOMID,0,"Servo 15:",SERVOMID,0,"Servo 16:",SERVOMID,0,
  "Servo 17:",SERVOMID,0,"Servo 18:",SERVOMID,0,"Servo 19:",SERVOMID,0,"Servo 20:",SERVOMID,0,
  "Servo 21:",SERVOMID,0,"Servo 22:",SERVOMID,0,"Servo 23:",SERVOMID,0,"Servo 24:",SERVOMID,0,
  "Servo 25:",SERVOMID,0,"Servo 26:",SERVOMID,0,"Servo 27:",SERVOMID,0,"Servo 28:",SERVOMID,0,
  "Servo 29:",SERVOMID,0,"Servo 30:",SERVOMID,0,"Servo 31:",SERVOMID,0,"Servo 32:",SERVOMID,0
};
//光标位置，一共四行，定义为0，1，2，3
int insert_f=0;
bool screen_update=0;//1为需要刷新屏幕，0为无需刷新屏幕

void setup() {
  // put your setup code here, to run once:
  //初始化串口
  Serial.begin(115200);
  Serial.print("Program:KeyControl_Servo!");
  //初始化舵机驱动
  pwm.begin();
  pwm1.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pwm1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  //初始化显示屏
  TFT.init();
  TFT.setRotation(3);
  TFT.fillScreen(TFT_BLACK);
  TFT.initDMA();
  //设置4个按键为输入模式
  for(int i=0;i<4;i++)
    pinMode(key[i].pin,INPUT);

  screen_update = 1;
  
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(key[0].pin)==1)
    {
      delayMicroseconds(10);
      if(digitalRead(key[0].pin)==1)
      {
        if(key[0].lastStatus==0)
        {
          servo[insert_f].num++;
          servo[insert_f].num = (servo[insert_f].num)>SERVOMAX?SERVOMAX:servo[insert_f].num;
          key[0].lastStatus=1;
          screen_update = 1;
          Serial.println("hello1");
          delay(200);
        }
        else if(key[0].lastStatus==1)
        {
          Serial.println("hello2");
          servo[insert_f].num++;
          servo[insert_f].num = (servo[insert_f].num)>SERVOMAX?SERVOMAX:servo[insert_f].num;
          delay(60);
          screen_update = 1;
        }
      }
    }
    if(digitalRead(key[0].pin)==0)
    {
      delayMicroseconds(10);
      if(digitalRead(key[0].pin)==0)
      {
        if(key[0].lastStatus==1)
        {
          key[0].lastStatus=0;
        }
      }
    }
    
    if(digitalRead(key[1].pin)==1)
    {
      delayMicroseconds(10);
      if(digitalRead(key[1].pin)==1)
      {
        if(key[1].lastStatus==0)
        {
          servo[insert_f].num--;
          servo[insert_f].num = (servo[insert_f].num)<SERVOMIN?SERVOMIN:servo[insert_f].num;
          key[1].lastStatus=1;
          screen_update = 1;
          Serial.println("hello1");
          delay(200);
        }
        else if(key[1].lastStatus==1)
        {
          Serial.println("hello2");
          servo[insert_f].num--;
          servo[insert_f].num = (servo[insert_f].num)<SERVOMIN?SERVOMIN:servo[insert_f].num;
          delay(60);
          screen_update = 1;
        }
      }
    }
    if(digitalRead(key[1].pin)==0)
    {
      delayMicroseconds(10);
      if(digitalRead(key[1].pin)==0)
      {
        if(key[1].lastStatus==1)
        {
          key[1].lastStatus=0;
        }
      }
    }
    //key3：向上翻页
    if(digitalRead(key[2].pin)==1)
    {
      delayMicroseconds(10);
      if(digitalRead(key[2].pin)==1)
      {
        if(key[2].lastStatus==0)
        {
          if(insert_f==0)
          {
            insert_f=31;          
          }
          else
            insert_f--;

          screen_update = 1;
          key[2].lastStatus=1;
        }
      }
    }
    if(digitalRead(key[2].pin)==0)
    {
      delayMicroseconds(10);
      if(digitalRead(key[2].pin)==0)
      {
        if(key[2].lastStatus==1)
        {
          key[2].lastStatus=0;
        }
      }
    }
    //key4：向下翻页
    if(digitalRead(key[3].pin)==1)
    {
      delayMicroseconds(10);
      if(digitalRead(key[3].pin)==1)
      {
        if(key[3].lastStatus==0)
        {
          if(insert_f==31)
          {
            insert_f=0;            
          }
          else
            insert_f++;
 
          key[3].lastStatus=1;
          screen_update = 1;
        }
      }
    }
    if(digitalRead(key[3].pin)==0)
    {
      delayMicroseconds(10);
      if(digitalRead(key[3].pin)==0)
      {
        if(key[3].lastStatus==1)
        {
          key[3].lastStatus=0;
        }
      }
    }
  if(screen_update)
  {
    TFT.fillScreen(TFT_BLACK);
    for(int i=0;i<4;i++)
    {
      TFT.setCursor(10, 30*(i), 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
      TFT.setTextColor(TFT_WHITE, TFT_BLACK);
      TFT.println(servo[insert_f/4*4+i].name);
      TFT.drawNumber(servo[insert_f/4*4+i].num, 120, 30*(i));               // Draw float using current font 
    }
    TFT.setCursor(200, 30*(insert_f%4), 4);//前俩参数是位置(横纵坐标),第三个参数是字体大小
    TFT.setTextColor(TFT_WHITE, TFT_BLACK);
    TFT.println("<--");    
    screen_update = 0;
  }
  for(int servoi=0;servoi<16;servoi++)
    pwm.setPWM(servoi, 0, servo[servoi].num);
  for(int servoi=16;servoi<31;servoi++)
    pwm1.setPWM(servoi%16, 0, servo[servoi].num);
  delay(10);
  
}
