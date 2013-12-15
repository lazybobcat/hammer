#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <SFML/Graphics.hpp>

#include "state.h"
#include "../world.h"
#include "../controllers/playercontroller.h"

class PauseState : public State
{
public:
    PauseState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

private:
    sf::Sprite      mSprite;
};

#endif // PAUSESTATE_H
