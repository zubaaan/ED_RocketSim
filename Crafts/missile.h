#ifndef MISSILE_H
#define MISSILE_H

#include "airvehicle.h"
#include "Components/solidengine.h"

class Missile : public AirVehicle
{
    Q_OBJECT
public:
    explicit Missile(QPointF pos, QPointF velo, double deltaT, AirVehicle *tgt, QObject *parent = nullptr)
        : AirVehicle(pos, velo, deltaT, parent), target_ptr(tgt)
    {
        qDebug() << "Missile()";
    }

    ~Missile()
    {
        qDebug() << "~Missile()";
    }

    void move();

private:
    void maneuver();

    AirVehicle *target_ptr  = nullptr;

    SolidEngine solidEngine = SolidEngine(60, 235, 6);
};

#endif // MISSILE_H
