int pos = 0;//定义整型变量pos，使其初始值为0

void setup()//初始化设置Arduino
{
  pinMode(A0, INPUT);//设置引脚A0为输入
  pinMode(8, OUTPUT);//设置引脚8为输出
  pinMode(A1, INPUT);//设置引脚A1为输入
  pinMode(A2, INPUT);//设置引脚A2为输入
}

void loop()//循环体结构，一直执行
{
  //如果检测到A0上的按钮按下
  if (digitalRead(A0) == HIGH) {
    tone(8, 440, 100); //播放音调57（A4=440赫兹）
  }
  //如果检测到A1上的按钮按下
  if (digitalRead(A1) == HIGH) {
    tone(8, 494, 100); //播放音调59（B4=494赫兹）
  }
  //如果检测到A2上的按钮按下
  if (digitalRead(A2) == HIGH) {
    tone(8, 523, 100); //播放音调60（C5=523赫兹）
  }
  delay(10); //稍微延迟10ms以提高仿真性能
}