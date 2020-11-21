#ifndef UTILS_H
#define UTILS_H

int getCameraData();
double ultrassonic_distance();
void move_engine(float moviment_rate);

class Sonar
{
  public:
    Sonar();
    void init(int trigger, int echo);
    double distance(int timeout);

  private:
    void recordPulseLength();
    int trigger;
    int echo;
    volatile long startTimeUsec;
    volatile long endTimeUsec;
    double distanceMeters;
    long travelTimeUsec;
    long now;
};

#endif