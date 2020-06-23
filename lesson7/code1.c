#include <MsTimer2.h>     //定时器库的头文件
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S 8
#define LT 6
#define BT 7
int num=0;
int a=0;
//中断服务程序
void onTimer()
{
  num=num++;
  if(num>9)
  {
    num=0;
  }
  a=num-'0';
  digitalWrite(S,LOW);
  digitalWrite(2,a&0x1);
  digitalWrite(3,(a>>1)&0x1);
  digitalWrite(4,(a>>2)&0x1);
  digitalWrite(5,(a>>3)&0x1);
  digitalWrite(S,HIGH);
  Serial.print("num");
  Serial.println(num++);
  
}
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S, OUTPUT);//片选1
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  Serial.begin(9600);
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S,HIGH);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
}

void loop()
{
    
}