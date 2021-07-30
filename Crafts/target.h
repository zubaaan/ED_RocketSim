#ifndef TARGET_H
#define TARGET_H

#include <airvehicle.h>

#include <random>

class Target : public AirVehicle
{
    Q_OBJECT
public:
    explicit Target(QPointF pos, QPointF velo, double deltaT, QObject *parent = nullptr);
    ~Target() {printf("~Target()");}

    void move();

private:
    double t = 0;           // model T [s]
    double maneuver_t = 0;

    std::uniform_int_distribution<> uid_t   {0,20};
    std::uniform_int_distribution<> uid_dir {0,1};
    std::mt19937 mersenne;
};

#endif // TARGET_H
