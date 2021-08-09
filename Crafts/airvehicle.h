#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <QObject>
#include <QPointF>
#include "linal.h"

#include <QDebug>

class AirVehicle : public QObject
{
    Q_OBJECT
public:
    explicit AirVehicle(QPointF pos, QPointF velo, double deltaT, QObject *parent = nullptr)
        :QObject(parent), dt(deltaT), position(pos), velocity(velo)
    {
        qDebug() << "AirVehicle()";
    }

    virtual ~AirVehicle()
    {
        qDebug() << "~AirVehicle()";
    }

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
    double weight;          // [kg]

private:
    QPointF position;       // x, y    [m]
    QPointF velocity;       // Vx, Vy  [m/s]
    QPointF acceleration;   // At, An  [m/s^2]

};

#endif // AIRVEHICLE_H
