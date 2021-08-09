#include "engine.h"

Engine::~Engine()
{
    for(auto obj : objects)
        obj->deleteLater();
}

void Engine::init(double missileSpd, double targetSpd,
                  double distance, double dT)
{
    auto target  = new Target(QPointF(distance, 0), QPointF(-targetSpd, 0), dT);
    auto missile = new Missile(QPointF(0,        0), QPointF(missileSpd, 0), dT, target);

//    objects.clear();

    objects.push_back(missile);
    objects.push_back(target);
}

void Engine::process()
{
//    for (int var = 0; var < 1500; ++var)
//    {


    while(true)
    {
        for(auto obj : objects)
        {
            obj->move();
            emit paintPointSignal(obj->metaObject()->className(), obj->getPos());
        }
    }



//    }
//    emit finished();
}

void Engine::stop()
{
    for(auto obj : objects)
        obj->deleteLater();
    objects.clear();
    emit finished();
}
