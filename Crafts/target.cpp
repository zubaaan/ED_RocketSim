#include "target.h"

Target::Target(QPointF pos, QPointF velo, double deltaT, QObject *parent)
    : AirVehicle(pos, velo, deltaT, parent)
{
    mersenne = std::mt19937(time(nullptr));
    maneuver_t = t + uid_t(mersenne);
}

void Target::move()
{
    if(t > maneuver_t)
    {
        maneuver_t = t + uid_t(mersenne);

        auto velo = getVelo();
        velo.setY(uid_dir(mersenne) == 0 ? -50 : 50);
        setVelo(velo);
    }

    AirVehicle::move();
    t += dt;
}
