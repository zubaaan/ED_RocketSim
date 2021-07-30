#include "linal.h"


QPointF LinAl::vectNorm(QPointF vect)
{
    QPointF nVect;
    nVect.setY(1.);
    nVect.setX( - (vect.y() * nVect.y()) / vect.x() );
    return nVect;
}

qreal LinAl::vectAbs(QPointF vect)
{
    return sqrtf(qPow( vect.x(), 2) +
                 qPow( vect.y(), 2) );
}
