#include <wiringPi.h>
#include <stdio.h>

#define red    8
#define yellow 9
#define green  7
#define sw     2
#define sw2     3


int flag = 1;

int mode = 0;
//int sw = digitalRead(2);
int intv = 0;  //0~9
int tim;       // delay time interval (ms)
int ps[40];  //pin number : 40, pin status :default 0

void toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin, ps[pin]);
}


void gpioisr()
{
		if(++intv > 8) intv = 0;
		printf("GPIO interrupt occured.... \n");
}

void gpioisr_2()
{
ps = [0];
flag = 0;
}


int main(void)
{
wiringPiSetup();  // Pin Number use case (wPi)
pinMode(8, OUTPUT); //8,9,7 : out  2 : IN
pinMode(9, OUTPUT);
pinMode(7, OUTPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
wiringPiISR(sw, INT_EDGE_FALLING,gpioisr);  //registration gpio isr
wiringPiISR_2(sw2, INT_EDGE_FALLING,gpioisr_2);


while(flag)
{
	tim = (9-intv)*100;
	if(mode)
	{
	toggle(8);  delay(tim);
	toggle(9);  delay(tim);
	toggle(7);  delay(tim);
	}
	else
	{
	toggle(7);  delay(tim);
	toggle(9);  delay(tim);
	toggle(8);  delay(tim);
	}
	
	
}
return 0;
}

