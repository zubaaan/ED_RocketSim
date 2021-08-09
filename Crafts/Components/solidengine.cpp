#include "solidengine.h"

SolidEngine::SolidEngine(double fuelMass_, double specificImpulse_, double elapsedTime_, QObject *parent)
    : QObject(parent), fuelMass(fuelMass_), specificImpulse(specificImpulse_), elapsedTime(elapsedTime_)
{
    qDebug() << "SolidEngine()";
}

SolidEngine::~SolidEngine()
{
    qDebug() << "~SolidEngine()";
}

double SolidEngine::burn(double dT)
{
    if ( (elapsedTime - dT) > 0 )
    {
        elapsedTime -= dT;

    }

    return 0;
}
