#ifndef SOLIDENGINE_H
#define SOLIDENGINE_H

#include <QObject>
#include <QDebug>

class SolidEngine : public QObject
{
    Q_OBJECT
public:
    explicit SolidEngine(double fuelMass_, double specificImpulse_,
                         double elapsedTime_, QObject *parent = nullptr);
    ~SolidEngine();

    double burn(double dT);

private:
    double fuelMass;
    double specificImpulse;
    double elapsedTime;
};

#endif // SOLIDENGINE_H
