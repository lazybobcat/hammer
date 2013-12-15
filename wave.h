#ifndef WAVE_H
#define WAVE_H

#include "entities/creature.h"

class World;

class Wave
{
public:
    Wave(World& world, unsigned int number);
    Wave& operator=(const Wave&cpy);

    void launch();
    bool isFinished() const;

    unsigned int number() const;
    void next();

private:
    World&  mWorld;
    unsigned int mWaveNumber;
};

#endif // WAVE_H
