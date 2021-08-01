#ifndef TARGET_H
#define TARGET_H

#include <airvehicle.h>

#include <random>
#include "common.h"

class Target : public AirVehicle
{
    Q_OBJECT
public:
    explicit Target(QPointF pos, QPointF velo, double deltaT, QObject *parent = nullptr);
    ~Target() {printf("~Target()");}

    void move();
    void maneuver();

private:
    double t = 0;           // model T [s]
    double maneuver_t = 0;
    double maneuver_t_dur = 0;
    double acc = 0;

    std::uniform_int_distribution<> uid_t     {1,  10};
    std::uniform_int_distribution<> uid_t_dur {15,  30};
    std::uniform_int_distribution<> uid_acc   {-9, 9};

    std::mt19937 mersenne;
};

#endif // TARGET_H
