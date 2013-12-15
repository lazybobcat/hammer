#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "../events/commandqueue.h"

class Creature;

class AIController
{
public:
    AIController();

    virtual void update(CommandQueue& commands, Creature& creature);
};

#endif // AICONTROLLER_H
