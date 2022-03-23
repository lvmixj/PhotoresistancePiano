int pitchInputPin = 0; //音调输入控制，接光敏电阻
int volumeInputPin = 1; //音量输入控制，接光敏电阻
int volumeOutputPin = 6; //音量输出控制，接到TDA7052音频运放的pin4，PWM占空比控制音量。RC低通滤波

int dacPins[] = {2, 4, 7, 8}; //输出端，进入到TD7052音频运放的输入端2
int sin16[] = {7,8,10,11,12,13,14,14,15,14,14,13,12,11,10,8,7,6,4,3,2,1,0,0,0,0,0,1,2,3,4,6};//粗糙模拟正弦函数，32个数

int count = 0; 

//定义模拟正弦输出端和音量输出端
void setup() 
{
  // put your setup code here, to run once:
  for (int i = 0; i<4; i++)
  {
    pinMode(dacPins[i], OUTPUT);
  }
  pinMode(volumeOutputPin, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int pitchDelay = map(analogRead(pitchInputPin),0,1023,10,60); //音调模拟信号输入的0-1023映射到10-60
  int volume = map(analogRead(volumeInputPin),0,1023,10,70);  //音量模拟信号输入的0-1023映射到10-70
  for (int i = 0; i < 32; i++)
  {
    setOutput(sin16[i]);//函数定义在下面
    delayMicroseconds(pitchDelay);//控制正弦波的波长，延迟时间长频率低听起来音调低，延迟时间短频率高听起来音调高
  }
  if (count == 10) //每10个loop循环进入
  {
    analogWrite(volumeOutputPin, volume); //音量PWM信号输出
    count = 0;
  }
  count++;
}

void setOutput(byte value) //value为二进制
{
  digitalWrite(dacPins[3],((value & 8) > 0));//value & 1000 按位与 比如 0101 & 1000 = 0000
  digitalWrite(dacPins[2],((value & 4) > 0));//value & 100 digtialWrite(pin,high/low)
  digitalWrite(dacPins[1],((value & 2) > 0));//value & 10 值是零就低电平，不是零就高电平
  digitalWrite(dacPins[0],((value & 1) > 0));//value & 1 
}
//这里模拟正弦的32个参数逐一传递给value，用dacPin[]的四个引脚向TDA7052传递0~15，相当于4-16译码器
