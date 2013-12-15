#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "state.h"
#include "../world.h"
#include "../controllers/playercontroller.h"

#include <array>

class GameState : public State
{
public:
    friend class StateStack;

public:
    GameState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

protected:
    virtual void onPause();
    virtual void onResume();

private:
    World           mWorld;
    PlayerController mPlayer;
    sf::Sprite      mHelp;
    sf::Time        mHelpTime;
    int             mHelpState;
    std::array<sf::Time, 5> mHelpTimes;
};

#endif // GAMESTATE_H
