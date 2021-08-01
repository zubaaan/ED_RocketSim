#include "target.h"

Target::Target(QPointF pos, QPointF velo, double deltaT, QObject *parent)
    : AirVehicle(pos, velo, deltaT, parent)
{
    mersenne = std::mt19937(time(nullptr));
    maneuver_t = t + uid_t(mersenne);

    //qDebug() << "\n****************************************************";
    //qDebug() << "First maneuver" << maneuver_t;
    //qDebug() << "****************************************************\n";
}

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
//        dir = uid_dir(mersenne);

        //qDebug() << "TIME" << t << "M-DUR" << maneuver_t_dur << "ACC" << acc;// << "DIR" << dir;
    }
    else if (t > maneuver_t_dur)
    {
        maneuver_t_dur = 0;
        maneuver_t = t + uid_t(mersenne);

        //qDebug() << "\n****************************************************";
        //qDebug() << "Next maneuver" << maneuver_t;
        //qDebug() << "****************************************************\n";
    }

    auto velo = getVelo();
    //qDebug() << "\nSPD VECT" << velo;

    auto velo_n = LinAl::vectNorm(velo);      // нормаль к вектору скорости
    //qDebug() << "SPD NORMAL" << velo_n;

    velo_n = velo_n / LinAl::vectAbs(velo_n); // единичный вектор из нормали
    velo_n = velo_n * acc;             // боковое ускорение
    //qDebug() << "ACC VECT" << velo_n;
 velo_n = velo_n * dt * dt / 2;
    //qDebug() << "ACC DT" << velo_n;

    setVelo(velo + velo_n);
}
