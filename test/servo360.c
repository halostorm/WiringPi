#include<stdio.h>
#include<wiringPi.h>

void init(int pin);
void servo_init(int pin);
void servo_turn(int pin, int angle);
int main()
{
        init(15);
	init(1);
	for(int i=0;i<3;i++)
	{	servo_init(15);
		delay(100);
		servo_init(1);
		delay(100);
		servo_turn(15,35);
		delay(100);
		servo_turn(1,35);
		delay(100);
		servo_turn(15,-35);
		delay(100);
		servo_turn(1,-35);
		delay(100);
	}

	servo_init(1);
	servo_init(15);
	delay(1000);
	int angle;
	scanf("%d",&angle);
	servo_turn(15,angle);
	delay(1000);
	scanf("%d",&angle);
	servo_turn(1,angle);
	return 0;
}


void init(int pin)
{
        wiringPiSetup();
        pinMode(pin,OUTPUT);
}

void servo_init(int pin)
{	//return to middle angle 0
	int k=2;
        while(k--)
        {
                digitalWrite(pin,HIGH);
                delayMicroseconds(1500);
                digitalWrite(pin,LOW);
                delayMicroseconds(18500);
	}
}

void servo_turn(int pin,int angle)
{
	int k=2;//
	int x=0;
	while(k--)
        {
                x=11.11*angle;
                digitalWrite(pin,HIGH);
                delayMicroseconds(1500+x);
                digitalWrite(pin,LOW);
                delayMicroseconds(18500-x);
        }
}