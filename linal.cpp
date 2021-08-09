#include "linal.h"


QPolygonF LinAl::setVect(QPointF startPoint, QPointF endPoint)
{
    QPolygonF res;

    res.push_back(startPoint);
    res.push_back(endPoint);

    return res;
}

QPointF LinAl::toBasis(QPolygonF vect)
{
    QPointF res(vect.at(1).x() - vect.at(0).x(), vect.at(1).y() - vect.at(0).y());
    return res;
}

qreal LinAl::scalarMultVect(QPointF vect1, QPointF vect2)
{
    return vect1.x()*vect2.x() + vect1.y()*vect2.y();
}

QPointF LinAl::vectNorm(QPointF vect)
{
    QPointF nVect;

    if(vect.x() > 0 && vect.y() > 0)
    {
        nVect.setY(-1.);
        nVect.setX( - (vect.y() * nVect.y()) / vect.x() );
    }
    else if(vect.x() < 0 && vect.y() > 0)
    {
        nVect.setX(1.);
        nVect.setY( - (vect.x() * nVect.x()) / vect.y() );
    }
    else if(vect.x() < 0 && vect.y() < 0)
    {
        nVect.setY(1.);
        nVect.setX( - (vect.y() * nVect.y()) / vect.x() );
    }
    else if(vect.x() > 0 && vect.y() < 0)
    {
        nVect.setX(-1.);
        nVect.setY( - (vect.x() * nVect.x()) / vect.y() );
    }
    else if(vect.x() == 0)
    {
        nVect.setX(1.);
        nVect.setY( - (vect.x() * nVect.x()) / vect.y() );
    } else if(vect.y() == 0)
    {
        nVect.setY(1.);
        nVect.setX( - (vect.y() * nVect.y()) / vect.x() );
    }

    return nVect;
}

qreal LinAl::vectAbs(QPointF vect)
{
    return sqrtf(qPow( vect.x(), 2) +
                 qPow( vect.y(), 2) );
}

qreal LinAl::vectAbs(QPolygonF vect)
{
    return sqrtf(qPow( toBasis(vect).x(), 2) +
                 qPow( toBasis(vect).y(), 2) );
}

QVector<QPolygonF> LinAl::guidanceTriangle(QPointF target_coords, QPointF interc_coords,
                                  QPointF target_speed, qreal interc_speed)
{
    QPolygonF rangeVect = setVect(interc_coords, target_coords);                // вектор дальности

    qreal absRangeVect = vectAbs(rangeVect);                                    // модуль вектора дальности

    QPointF unitVector(toBasis(rangeVect).x() / absRangeVect,                   // единичный вектор дальности
                       toBasis(rangeVect).y() / absRangeVect);

    qreal absTgtSpdVect_on_range = scalarMultVect(unitVector, target_speed);    // модуль проекции вектора скорости
                                                                                // цели на вектор дальности

    QPointF TgtSpdVect_on_range(unitVector.x() * absTgtSpdVect_on_range,        // проекция вектора скорости
                                unitVector.y() * absTgtSpdVect_on_range);       // цели на вектор дальности

    qreal absTgtSpdVect_norm_range;                                             // модуль нормали вектора скорости
                                                                                // цели к вектору дальности
    if( (qPow(target_speed.x(),2) +
         qPow(target_speed.y(),2) -
         qPow(absTgtSpdVect_on_range,2)) < 0)
        absTgtSpdVect_norm_range = 0.;
    else
        absTgtSpdVect_norm_range = qSqrt(qPow(target_speed.x(),2) +
                                         qPow(target_speed.y(),2) -
                                         qPow(absTgtSpdVect_on_range,2));

    qreal absIntrcVect_on_range = sqrtf(qPow(interc_speed, 2) -                 // модуль проекции вектора скорости
                                        qPow(absTgtSpdVect_norm_range,2));      // перехватчика  на вектор дальности

    QPointF IntrcVect_on_range(absIntrcVect_on_range*unitVector.x(),            // проекция вектора скорости
                               absIntrcVect_on_range*unitVector.y());           // перехватчика  на вектор дальности

    QPointF TgtSpdVect_norm_range(target_speed.x() - TgtSpdVect_on_range.x(),   // нормаль вектора скорости
                                  target_speed.y() - TgtSpdVect_on_range.y());  // цели к вектору дальности

    QPointF IntrcSpdVect(TgtSpdVect_norm_range.x() + IntrcVect_on_range.x(),    // вектор скорости
                         TgtSpdVect_norm_range.y() + IntrcVect_on_range.y());   // перехватчика

    QVector<QPolygonF> res;
    res.push_back(rangeVect);

    QPolygonF spd;
    spd.push_back(IntrcSpdVect);
    res.push_back(spd);
    return res;
}
