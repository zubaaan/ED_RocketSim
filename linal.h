#ifndef LINAL_H
#define LINAL_H

#include <QPointF>
#include <qmath.h>

class LinAl
{
public:
    static QPointF vectNorm(QPointF vect);
    static qreal vectAbs(QPointF vect);
};

#endif // LINAL_H
