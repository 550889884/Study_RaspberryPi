#include <wiringPi.h>
#include <stdio.h>



char PWMpin = 24;

void setup();

int main()
{
	setup();
	int val = 0;
	int step = 2;
	while (true)
	{
		if (val > 1024)
		{
			step = -step;
			val = 1024;
		}
		else if (val < 0)
		{
			step = -step;
			val = 0;
		}

		pwmWrite(PWMpin, val);
		printf("setup PWMpin %d \n", val);
		val += step;
		delay(10);
	}

	return 0;
}

void setup()
{
	if (-1 == wiringPiSetup())
	{
		printf("setup error\n");
		return;
	}
	pinMode(PWMpin, PWM_OUTPUT);
}
