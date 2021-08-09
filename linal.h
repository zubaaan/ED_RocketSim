#ifndef LINAL_H
#define LINAL_H

#include <QPointF>
#include <QPolygonF>
#include <qmath.h>

#define GRAVITY 9.81

class LinAl
{
public:
    static QPolygonF setVect(QPointF startPoint, QPointF endPoint); // генерация вектора (зад-го 2-мя точками)
    static QPointF toBasis(QPolygonF vect);                         // приведение vect к базису
    static qreal scalarMultVect(QPointF vect1, QPointF vect2);      // скалярное произведение (vect1, vect2)
    static QPointF vectNorm(QPointF vect);                          // нормаль vect
    static qreal vectAbs(QPointF vect);                             // модуль базисного vect
    static qreal vectAbs(QPolygonF vect);                           // модуль vect (зад-го 2-мя точками)

    static QVector<QPolygonF> guidanceTriangle(QPointF target_coords,
                                               QPointF interc_coords,
                                               QPointF target_speed,
                                               qreal interc_speed);
};

#endif // LINAL_H
