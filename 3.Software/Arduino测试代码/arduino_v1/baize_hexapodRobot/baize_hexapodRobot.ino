
#define speed_s 50


#define TRIGGER A0
#define ECHO A1

#define dis_min 20        //超声波避障距离
#define dis_max 180       //超声波检测最大值

int dis_u=30;

//蓝牙指令   A-前进  B-后退  C-左转  D-右转  E-停止
char now_cmd='E';

//zuobiao[i][0]为z,zuobiao[i][1]为y，zuobiao[i][2]为x
float zuobiao[8][3]={-15.0,-72.83,119.21,
-7.5,-68.5,119.21,
0,-67.83,119.21,
7.5,-68.5,119.21,
15,-72.83,119.21,
7.5,-77.16,119.21,
0,-77.83,119.21,
-7.5,-77.16,119.21,
};

float angle[8][3]={11.84,64.44,5.68,
6.1,80.25,15.56,
0,83.25,17.45,
-6.1,80.25,15.56,
-11.84,64.44,5.68,
-6.1,51.16,-2.23,
0,49.12,-3.39,
6.1,51.16,-2.23
};

void tingzhi()
{
  String s="";
  for(int i=1;i<=32;i++)
  {
      s+="#";
      s+=i;
      s+="P";
      int angle_s=1500;
      s+=angle_s;
  }
    s+="T200";
    Serial1.println(s);
    delay(speed_s);
  
}

void qianjin(){
  
  for(int j=0;j<=3;j++)
  {
      String s="";
      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][0],0,180,500,2500);
      s+=angle_s;

      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j+4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
  
  for(int j=4;j<=7;j++)
  {
      String s="";
      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][0],0,180,500,2500);
      s+=angle_s;

      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j-4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      
      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
 
}

void houtui()
{
    for(int j=0;j<=3;j++)
  {
      String s="";

      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;
      
      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][0],0,180,500,2500);
      s+=angle_s;

      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j+4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      

      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
  
  for(int j=4;j<=7;j++)
  {
      String s="";

      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int  angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      
      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;
      
      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][0],0,180,500,2500);
      s+=angle_s;

      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j-4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      

      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
}

void zuozhuan()
{
    for(int j=0;j<=3;j++)
  {
      String s="";
      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][0],0,180,500,2500);
      s+=angle_s;

      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j+4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;


      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][0],0,180,500,2500);
      s+=angle_s;

      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j+4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j+4][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;


      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
  
  for(int j=4;j<=7;j++)
  {
      String s="";
      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][0],0,180,500,2500);
      s+=angle_s;

      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j-4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;


      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      

      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][0],0,180,500,2500);
      s+=angle_s;

      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j-4][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j-4][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;


      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
}

void youzhuan()
{
    for(int j=0;j<=3;j++)
  {
      String s="";

      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;


      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
  
  for(int j=4;j<=7;j++)
  {
      String s="";

      int i=4;
      s+="#";
      s+=i;
      s+="P";
      int  angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      
      i=5;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=6;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=7;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=8;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=9;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=10;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=11;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=12;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;


      i=21;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      
      i=22;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=23;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;

      i=24;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90+angle[j][0],0,180,500,2500);
      s+=angle_s;
      
      i=25;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[j][1]+90,0,180,500,2500);
      s+=angle_s;

      i=26;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[j][2],0,180,500,2500);
      s+=angle_s;

      i=27;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][0],0,180,500,2500);
      s+=angle_s;
      

      i=28;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(angle[7-j][1]+90,0,180,500,2500);
      s+=angle_s;
      
      i=29;
      s+="#";
      s+=i;
      s+="P";
      angle_s=map(90-angle[7-j][2],0,180,500,2500);
      s+=angle_s;


      
      s+="T200";
    Serial1.println(s);
    delay(speed_s);
  }
}


int dis(){
  Serial.println(millis());
  float dist=0;
  for(int i=0;i<3;i++)
  {
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(2);
    //将trigPin电平拉高10微秒
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    // 读取echoPin电平,以毫秒为单位返回声波往返时间
    // 计算距离
    float distance = pulseIn(ECHO,HIGH)/58.0; //算成厘米 
//    Serial.print("distance=");
//    Serial.println(distance);
    distance=(int(distance * 100.0))/100.0;//保留两位小数 
    
    dist+=distance;
  }
//  Serial.println(millis());
  return int(dist/3.0);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
//  int a=35;
//  String s="The angle is:";
//  Serial.println("#4P1500T100");
//  delay(1000);
//  Serial.println("#4P1000T100");
//  delay(1000);
//  Serial.println("#4P1500T100");
//  s+=a;
//  Serial.println(s);
//  qianjin();
  pinMode(TRIGGER,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  tingzhi();
  Serial.println("Init successful!");
}

void loop() {
  // put your main code here, to run repeatedly:
//  for(int s=0;s<=5;s++)
//  {
//    qianjin();
//  }
//  for(int s=0;s<=5;s++)
//  {
//    houtui();
//  }
//  zuozhuan();
//    youzhuan();
  dis_u=dis();
  if(Serial.available()>0)
  {
    now_cmd=Serial.read();
    Serial.println(now_cmd);
  }
  if(now_cmd=='A')
  {
    if((dis_u>=0)&&(dis_u<=dis_min))
    {
      for(int i=0;i<5;i++)
        houtui();
      for(int i=0;i<5;i++)
        youzhuan();
    }
    qianjin();
  }
  else if(now_cmd=='B')
  {
    houtui();
  }
  else if(now_cmd=='C')
  {
    zuozhuan();
  }
  else if(now_cmd=='D')
  {
    youzhuan();
  }
  else if(now_cmd=='E')
  {
    tingzhi();
  }
}
