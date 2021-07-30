#ifndef ROCKET_H
#define ROCKET_H

#include <airvehicle.h>

class Rocket : public AirVehicle
{
    Q_OBJECT
public:
    explicit Rocket(QPointF pos, QPointF velo, double deltaT, QObject *parent = nullptr);
    ~Rocket() {printf("~Rocket()");}
};

#endif // ROCKET_H
