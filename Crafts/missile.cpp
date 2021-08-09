#include "missile.h"

void Missile::move()
{
    maneuver();
    AirVehicle::move();
}

void Missile::maneuver()
{
    if(target_ptr != nullptr)
    {


        QVector<QPolygonF> rngAndspd = LinAl::guidanceTriangle(target_ptr->getPos(),  this->getPos(),
                                                               target_ptr->getVelo(),  LinAl::vectAbs(this->getVelo()));
        QPointF IntrcSpdVect = rngAndspd.at(1).at(0);
        setVelo(IntrcSpdVect);

//        QPolygonF rangeVect_old = rngAndspd.at(0);
//        QPolygonF rangeVect;

    }
    else
    {
        qDebug() << "Target is nullptr";
        return;
    }
}
