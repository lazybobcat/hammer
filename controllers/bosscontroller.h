#ifndef BOSSCONTROLLER_H
#define BOSSCONTROLLER_H

#include "aicontroller.h"

class BossController : public AIController
{
public:
    BossController();

    virtual void update(CommandQueue& commands, Creature& creature);
};

#endif // BOSSCONTROLLER_H
