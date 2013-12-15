#include "aicontroller.h"
#include "../entities/creature.h"

AIController::AIController()
{
}

void AIController::update(CommandQueue &/*commands*/, Creature &creature)
{
    if(!creature.isDestroyed())
    {
        creature.move(creature.getDirection());
    }
}
