#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>

#include "state.h"
#include "../world.h"
#include "../controllers/playercontroller.h"

class GameoverState : public State
{
public:
    GameoverState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

private:
    sf::Sprite      mSprite;
};

#endif // GAMEOVERSTATE_H
