#include <iostream>

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

/*
    Retorna a distância para um obstáculo, em metros
*/
float getSensorData(){
    float sensor_value = 0.85;

    return sensor_value;
}

/*
    Chama a função getCameraData e retorna o valor obtido
*/
int getObstacleDirection(){

    int obstacle_direction = getCameraData();

    return obstacle_direction;
}

/*
    Chama a função getSensorData e retorna o valor lido
*/
float getObstacleDistance(){

    float obstacle_distance = getSensorData();

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

int main(){

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

    return 0;
}