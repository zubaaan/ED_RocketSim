#include "linal.h"


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
