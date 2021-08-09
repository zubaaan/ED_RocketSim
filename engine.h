#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "Crafts/missile.h"
#include "Crafts/target.h"

class Engine : public QObject
{
    Q_OBJECT
public:
    ~Engine();

    void init(double missileSpd, double targetSpd,
              double distance, double dT);

public slots:
    void process();
    void stop();

signals:
    void paintPointSignal(QString name, QPointF pos);
    void finished();

private:
    QVector<AirVehicle*> objects;
};

#endif // ENGINE_H
