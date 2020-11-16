#include <stdio.h>
#include <pigpio.h>

#define frequency_pwm 50 //[khz]
#define PAN 17
#define TILT 18

void move_pantilt(int i_pan, int i_tilt)
{
    int duty_pan, duty_tilt = 0;
    angle_pan

    duty_pan = i_pan / (20);
    duty_tilt = i_tilt / (20);

    gpioPWM(PAN, 0);  // configura o pino PAN como saída PWM
    gpioPWM(TILT, 0); // configura o pino 2 como saída PWM
    
    /*
    configura o pino PAN para receber a frequencia correta
    com o duty_cicle correto definido por duty_pan e duty_tilt
	  */
    gpioSetPWMfrequency(PAN, frequency_pwm);
    gpioSetPWMfrequency(TILT, frequency_pwm);

}
