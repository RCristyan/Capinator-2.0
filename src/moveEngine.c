#include <stdio.h>
#include <pigpio.h>
 
#define PWMSTEP 512
#define frequency_pwm 40 //[khz]
#define LEFT 27
#define RIGHT 25

void move_engine(float moviment_axis)
{
    int duty_left, duty_right = 0;
    duty_right = (int)(moviment_axis)*(PWMSTEP) + PWMSTEP;  //seta o duty cycle do motor da direita
    duty_left =  (int)(moviment_axis)*(PWMSTEP) + PWMSTEP;  //seta o duty cycle do motor da esquerda

    gpioPWM(LEFT, 0);  // configura o pino LEFT como saída PWM
    gpioPWM(RIGHT, 0); // configura o pino RIGHT como saída PWM

    gpioSetPWMfrequency(duty_right, frequency_pwm); 
    gpioSetPWMfrequency(duty_left, frequency_pwm);
  	           
}
