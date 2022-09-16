#include "WiFi.h"
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <rosserial_arduino/Adc.h>
#include <robot_msg/hexapodrobot_jointstate.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI TFT = TFT_eSPI();  // Invoke custom library

//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();               //驱动1~16或(0~15)号舵机
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);          //驱动17~32或(16~31)号舵机

int rec[18] = {
  320,320,327,
  327,345,310,
  350,327,310,
  350,327,337,
  327,327,350,
  350,340,320
};
int direct[18] = {-1,1,1,
-1,1,1,
-1,1,1,
-1,1,1,
-1,1,1,
-1,1,1
};

//设置AP信息(SSID和PASSWORD)
const char* ssid = "Zhitong";
const char* password = "95359897";

IPAddress server(192, 168, 191, 2); // ip of your ROS server
IPAddress ip_address;
int status = WL_IDLE_STATUS;

WiFiClient client;
 
class WiFiHardware {
 
  public:
  WiFiHardware() {};
 
  void init() {
    // do your initialization here. this probably includes TCP server/client setup
    client.connect(server, 11411);
  }
 
  // read a byte from the serial port. -1 = failure
  int read() {
    // implement this method so that it reads a byte from the TCP connection and returns it
    //  you may return -1 is there is an error; for example if the TCP connection is not open
    return client.read();         //will return -1 when it will works
  }
 
  // write data to the connection to ROS
  void write(uint8_t* data, int length) {
    // implement this so that it takes the arguments and writes or prints them to the TCP connection
    for(int i=0; i<length; i++)
      client.write(data[i]);
  }
 
  // returns milliseconds since start of program
  unsigned long time() {
     return millis(); // easy; did this one for you
  }
};
 
int i;

void JointStateCallback(const robot_msg::hexapodrobot_jointstate& jointstate) {

  for(int i=0;i<16;i++)
  {
    pwm.setPWM(i, 0, map(jointstate.position[i]*direct[i],-90,90,-225,225)+rec[i]);
    }
   pwm1.setPWM(16-16, 0, map(jointstate.position[16]*direct[16],-90,90,-225,225)+rec[16]);
   pwm1.setPWM(17-16, 0, map(jointstate.position[17]*direct[17],-90,90,-225,225)+rec[17]);
//  TFT.fillScreen(TFT_BLACK);
  TFT.setCursor(0, 30, 4);
  // Set the font colour to be white with a black background
  TFT.setTextColor(TFT_WHITE, TFT_BLACK);

  // We can now plot text on screen using the "print" class
  TFT.println(jointstate.position[0]); 
  delay(1);
}
 
 
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
ros::Subscriber<robot_msg::hexapodrobot_jointstate> subjoint("/hexapod_joint", JointStateCallback);

ros::NodeHandle_<WiFiHardware> nh;
char hello[20] = "ESP32 wifi alive!";
 
 
void setupWiFi()
{
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
    while(1) delay(500);
  }
  Serial.print("Ready! Use ");
  Serial.print(WiFi.localIP());
  Serial.println(" to access client");
}

void setup() {
  Serial.begin(115200);
  setupWiFi();
  delay(2000);
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(subjoint);
  

  TFT.init();
  TFT.setRotation(3);
  TFT.fillScreen(TFT_BLACK);
  TFT.initDMA();

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
  delay(100);
}
 
void loop() {
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(5);
}
