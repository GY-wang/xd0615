#define IN1 2
#define IN2 6
#define IN3 4
#define IN4 5
#define S 8
#define LT 6
#define BT 7
int num=0;
int a=0;
int pinInterrupt = 2; //接中断信号的脚
//中断服务程序
void onChange()
{
  if ( digitalRead(pinInterrupt) == LOW )
      num=0;
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
  pinMode( pinInterrupt, INPUT);//设置管脚为输入
   //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  
}

void loop()
{
  
  num=num++;
  if(num>9)
  {
    num=0;
  }
  a=num-'0';
  digitalWrite(S,LOW);
  digitalWrite(6,a&0x1);
  digitalWrite(3,(a>>1)&0x1);
  digitalWrite(4,(a>>2)&0x1);
  digitalWrite(5,(a>>3)&0x1);
  digitalWrite(S,HIGH);
  Serial.print("num");
  Serial.println(num++);
  delay(1000);
}