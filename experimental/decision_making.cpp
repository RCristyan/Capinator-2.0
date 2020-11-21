#include "utils.h"
#include <iostream>

using namespace std;

/*
    Chama a função getCameraData e retorna o valor obtido
*/
int getObstacleDirection(){

    int obstacle_direction = getCameraData();

    return obstacle_direction;
}

/*
    Chama a função ultrassonic_distance e retorna o valor lido
*/
float getObstacleDistance(){

    float obstacle_distance = ultrassonic_distance();

    return obstacle_distance;
}

/*
    Calcula a taxa de movimento que o robô deverá realizar
    e retorna este valor
        retorna um valor < 0 se deve desviar para a esquerda
        retorna um valor > 0 se deve desviar para a direita
*/
float movimentRate(){

    float obstacle_distance = getObstacleDistance();
    float obstacle_direction = -1 * getObstacleDirection();

    float moviment_rate = 0;
    const int c = 20;
    float normalization_weight = 1 / (0.1 * c);

    if (obstacle_distance < 1){
        moviment_rate = 1 / (obstacle_distance * c * normalization_weight);
        moviment_rate *= obstacle_direction;
    } 

    return moviment_rate;
}

/*
    Retorna a direção que o robô deverá tomar
        retorna 1 se for para seguir em frente
        retorna -1 se for para reverso
*/
int getMovimentDirection(){
    int moviment_direction;
    float obstacle_distance = getObstacleDistance();

    if (obstacle_distance < 15){
        return -1;
    }
    return 1;
}

/*
    Função principal do módulo
*/
void forward(){
    float moviment_rate = movimentRate();
    int moviment_direction = getMovimentDirection();

    /*
    Em seguida deverá chamar uma função externa para controlar os motores

    movimentEngine(moviment_rate, moviment_direction)
    */ 

    move_engine(moviment_rate);
}

int main(){

    /*
    A execução principal consiste em chamar constantemente
    a função forward(), que irá então determinar o movimento
    dos motores

    while(1){
        forward();
    }
    */

    int obstacle_direcion = getObstacleDirection();

    if (obstacle_direcion == 1){
        cout << "Obstáculo a direita!\n";
    }
    else if (obstacle_direcion == -1){
        cout << "Obstáculo a esquerda!\n";
    }

    float obstacle_distance = getObstacleDistance();

    cout << "Distancia para obstáculo = " << obstacle_distance << "\n";

    float moviment_rate = movimentRate();

    cout << "Taxa de movimento = " << moviment_rate << "\n";

    Sonar sonar;

    cout << sonar.distance(1) << "\n"; 

    return 0;
}