#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <QObject>
#include <QPointF>
#include "linal.h"

class AirVehicle : public QObject
{
    Q_OBJECT
public:
    explicit AirVehicle(QPointF pos, QPointF velo, double deltaT, QObject *parent = nullptr)
        :QObject(parent), dt(deltaT), position(pos), velocity(velo) {}
    virtual ~AirVehicle() {printf("~AirVehicle()");}

    virtual void move()
    {
        position.setX(position.x() + velocity.x()*dt);
        position.setY(position.y() + velocity.y()*dt);
    }

    QPointF getPos()  const {return position;}
    QPointF getVelo() const {return velocity;}
    QPointF getAcc()  const {return acceleration;}

protected:
    void setVelo(QPointF velo) {velocity = velo;}

    double dt;              // delta T [s]

private:
    QPointF position;       // x, y    [m]
    QPointF velocity;       // Vx, Vy  [m/s]
    QPointF acceleration;   // At, An  [m/s^2]
};

#endif // AIRVEHICLE_H
