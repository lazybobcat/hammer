#include "wave.h"
#include "world.h"
#include "utils.h"

Wave::Wave(World &world, unsigned int number) :
    mWorld(world),
    mWaveNumber(number)
{
}

void Wave::launch()
{
    if(mWaveNumber <= 15)
    {
        //std::string level = "assets/scripts/level" + toString(mWaveNumber) + ".lua";
        mWorld.mScripts.play((Scripts::ID)mWaveNumber);
    }
    else
    {
        //Wave infinie ou fin du jeu
        mWorld.mScripts.play(Scripts::LevelInfinite);
    }
}

bool Wave::isFinished() const
{
    return mWorld.creatureCount() == 0;
}

void Wave::next()
{
    mWaveNumber += 1;
}

unsigned int Wave::number() const
{
    return mWaveNumber;
}
