#include<stdio.h>
#include<wiringPi.h>

void init();
int main()
{
        init();
        int angle1=0;
	int angle2=0;
	printf("Input angle1 angle2 \n");
        scanf("%d",&angle1);
	scanf("%d",&angle2);
	int x;
        int k=20;//180次循环的时间够了
        while(k--)
        {
                digitalWrite(1,HIGH);
                delayMicroseconds(1500);
                digitalWrite(1,LOW);
                delayMicroseconds(18500);
	}
	k=20;//180次循环的时间够了
        delay(1000);
	while(k--)
        {
                x=11.11*angle1;
                digitalWrite(1,HIGH);
                delayMicroseconds(1500+x);
                digitalWrite(1,LOW);
                delayMicroseconds(18500-x);
        }
        k = 20;
	delay(1000);        
	while(k--)
        {
                x=11.11*angle2;
                digitalWrite(1,HIGH);
                delayMicroseconds(1500+x);
                digitalWrite(1,LOW);
                delayMicroseconds(18500-x);
        }
        return 0;
}


void init()
{
        wiringPiSetup();
        pinMode(1,OUTPUT);
}

