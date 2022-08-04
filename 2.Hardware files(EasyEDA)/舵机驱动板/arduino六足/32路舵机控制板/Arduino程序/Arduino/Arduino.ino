void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  while(1)
  {
    Serial.print("#1P800T1000\r\n");  // S1号舵机旋转到脉宽为800的位置，使用时间1000ms
    delay(1000);  // 延时1000ms，舵机刚好执行完上一条命令
    Serial.print("#1P1800T1000\r\n");  // S1号舵机旋转到脉宽为1800的位置，使用时间1000ms
    delay(1000);  // 延时1000ms，舵机刚好执行完上一条命令
  }
}
