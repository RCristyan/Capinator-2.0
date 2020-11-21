#include "utils.h"
#include <iostream>
#include <wiringPi.h>
#include <pigpio.h>
 
#define PWMSTEP 512
#define frequency_pwm 40 //[khz]
#define LEFT 27
#define RIGHT 25
#define TRIGGER 1
#define ECHO 0

using namespace std;

/*
    Retorna a posição de um obstáculo
        retorna 1 se obstáculo está a direita
        retorna -1 se obstáculo está a esquerda
*/
int getCameraData(){
    int camera_value = -1;

    return camera_value;
}

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

double ultrassonic_distance()
{
    if (wiringPiSetup() == -1) // verifica se o pino pode ser usado
        return -1;

    Sonar sonar;               // declara uma variável do tipo sonar
    sonar.init(TRIGGER, ECHO); // inicializa os pinos
    return sonar.distance();   // retorna a distância em cm

    return 1;
}

Sonar::Sonar(){}

void Sonar::init(int trigger, int echo)
{
    this->trigger=trigger;
    this->echo=echo;
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trigger, LOW);
    delay(500);
}

double Sonar::distance(int timeout)
{
    delay(10);

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    now=micros();

    while (digitalRead(echo) == LOW && micros()-now<timeout);
        recordPulseLength();

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distanceMeters = 100*((travelTimeUsec/1000000.0)*340.29)/2;

    return distanceMeters;
}

void Sonar::recordPulseLength(){}