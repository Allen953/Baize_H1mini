#include <ESP8266WiFi.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <robot_msg/hexapodrobot_jointstate.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define LED_BUILTIN 2 //led test

//#define SERVOMIN  102               //0.5/20 * 4096 = 102
//#define SERVOMID  307               //1.5/20 * 4096 = 307
//#define SERVOMAX  512               //2.5/20 * 4096 = 512
//实际测试
#define SERVOMIN  102               
#define SERVOMID  327               
#define SERVOMAX  552

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();               //驱动1~16或(0~15)号舵机
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);   

int rec[18] = {
  320,320,327,
  327,345,310,
  350,327,310,
  350,327,337,
  327,327,350,
  350,340,320
};
int direct[18] = {1,-1,1,
1,-1,1,
1,-1,1,
1,-1,1,
1,-1,1,
1,-1,1
};

const char* ssid     = "Zhitong";
const char* password = "95359897";
 
IPAddress server(192,168,191,3); //设置ros server的IP地址，ros master主机地址
const uint16_t serverPort = 11411;

//定义/command_led这个话题消息的回调函数
void control_led(const std_msgs::UInt16 &msg){
  switch(msg.data)
  {
    case 0:digitalWrite(LED_BUILTIN,HIGH);break;  //LOW为亮灯，HIGH为灭灯
    case 1:digitalWrite(LED_BUILTIN,LOW);break;
    default:digitalWrite(LED_BUILTIN,HIGH);
  }
}
//定义/command_led这个话题消息的回调函数
void JointStateCallback(const robot_msg::hexapodrobot_jointstate& jointstate) {

  for(int i=0;i<16;i++)
  {
    pwm.setPWM(i, 0, map(jointstate.position[i]*direct[i],-90,90,-225,225)+rec[i]);
    }
   pwm1.setPWM(16-16, 0, map(jointstate.position[16]*direct[16],-90,90,-225,225)+rec[16]);
   pwm1.setPWM(17-16, 0, map(jointstate.position[17]*direct[17],-90,90,-225,225)+rec[17]);

  delay(1);
}

//设置ros节点句柄，发布者和发布的话题消息数据
ros::NodeHandle nh;
std_msgs::String str_msg;
std_msgs::UInt16 command_led;    //the topic which can allowed you to control the led
ros::Publisher chatter("chatter", &str_msg);
 
char hello[13] = "zhitong come";  //话题消息字符数组
ros::Subscriber<std_msgs::UInt16> sub("/command_led", &control_led);
ros::Subscriber<robot_msg::hexapodrobot_jointstate> subjoint("/hexapod_joint", JointStateCallback);

void setup()
{
  //通过serial串口日志查看运行状态
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  //将esp8266连入wifi热点
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  //接入rosserial socket服务器
  nh.getHardware()->setConnection(server, serverPort);
  pinMode(LED_BUILTIN,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(subjoint);
  nh.advertise(chatter);

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
 
void loop()
{
 
  if (nh.connected()) {
    Serial.println("Connected");
    // Say hello
    str_msg.data = hello;
    chatter.publish( &str_msg );
  } else {
    Serial.println("Not Connected");
  }
  nh.spinOnce();
  // Loop exproximativly at 1Hz
  delay(1);
}
