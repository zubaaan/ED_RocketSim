#include "target.h"

void Target::move()
{
    if(t > maneuver_t)
        maneuver();

    AirVehicle::move();
    t += dt;
}

void Target::maneuver()
{
    if(maneuver_t_dur == 0)
    {
        maneuver_t_dur = t + uid_t_dur(mersenne);
        acc = uid_acc(mersenne) * GRAVITY;
    }
    else if (t > maneuver_t_dur)
    {
        maneuver_t_dur = 0;
        maneuver_t = t + uid_t(mersenne);
    }

    auto velo = getVelo();
    auto velo_n = LinAl::vectNorm(velo);      // нормаль к вектору скорости
    velo_n = velo_n / LinAl::vectAbs(velo_n); // единичный вектор из нормали
    velo_n = velo_n * acc;                    // боковое ускорение
    velo_n = velo_n * dt * dt / 2;

    setVelo(velo + velo_n);
}
