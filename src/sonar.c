#include <iostream>
#include <wiringPi.h>
#include "libSonar.h"

using namespace std;

#define TRIGGER 1
#define ECHO 0

double ultrassonic_distance()
{
    if (wiringPiSetup() == -1) // verifica se o pino pode ser usado
        return -1;

    Sonar sonar;               // declara uma variável do tipo sonar
    sonar.init(TRIGGER, ECHO); // inicializa os pinos
    return sonar.distance();   // retorna a distância em cm
}
