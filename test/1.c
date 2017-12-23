
//file name=sg90.c
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <softPwm.h>

#define RANGE	200 //1 means 100 us , 200 means 20 ms 1等于100微妙，200等于20毫秒 


int main (int argc, char** argv)
{
  if( argc != 3){     //该程序带有两个参数
    printf("usage: ./command <pin> <degree>\n");  
    exit(0);  
    }
  
  int pin;     
  pin=atoi(argv[1]);  //第一个参数为所要控制的引脚wiringpi编号
  int i;
  float degree;
  if( !(pin>=0&&pin<=8)){     //第二个参数为需要控制舵机转动的角度
    printf("only setup pin 1 to 8\n");  
    exit(0);  
    }
  if( !(atoi(argv[2])>=-135&&atoi(argv[2])<=135)){  
    printf("degree is between -135 and 135\n");  
    exit(0);  
    }

  degree=15+atof(argv[2])/270.0*20.0;
  wiringPiSetup ()  ;  //wiringpi初始化
  softPwmCreate (pin, 15, RANGE) ;  //创建一个使舵机转到中心的pwm输出信号
  delay(1000);
  for (i = 0 ; i < 5 ; i++)
  {
   	softPwmWrite(pin,15);   //使舵机转到中心
	delayMicroseconds(1000000);
	printf("%f\n",degree);
	softPwmWrite(pin,degree);//转到预期角度
	delayMicroseconds(1000000);
  }
  //softPwmWrite (pin, 15) ;
  exit(0);

}
  
