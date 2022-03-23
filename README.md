# PhotoresistancePiano
灯光竖琴，基于arduino，两个光敏电阻控制音量和音调
制作器件：
Arduino开发板
100nF无极性电容
100μF/16V电解电容
10kΩ 0.5W金属膜电阻
4.7kΩ 0.5W金属膜电阻
1MΩ 0.5W金属膜电阻
100kΩ 0.5W金属膜电阻
光敏电阻
TDA7052 1W 音频运算放大器
8Ω扬声器

硬件原理：
TDA7052音频运算放大器芯片的4号引脚可以用来控制输出音频信号的幅值(即音量),大小取决于输入到4号引脚上PWM波形的占空比，我们用Arduino的数字引脚6来产生该PWM信号。为了消除该PWM信号中的部分低频干扰波，这里使用了一个由1MΩ电阻和100μF/16V电解电容构成的RC低通滤波器,将信号中的低频干扰去除。

电路原理：

![image](https://user-images.githubusercontent.com/57294382/159695958-feb368ad-f07e-4e99-85b0-150b115b7821.png)

预期实现效果：
分别用两个光敏电阻来控制音乐的音调和音量。

相关照片：

![image](https://user-images.githubusercontent.com/57294382/159696020-9fc0f6c5-a9bc-4db9-9818-581c8ec647ec.png)
![image](https://user-images.githubusercontent.com/57294382/159696037-f0ebb31a-da0a-4a28-adf1-374ee5a3d617.png)
![image](https://user-images.githubusercontent.com/57294382/159696064-121ba2ec-5520-4756-94de-c172cd21e537.png)
