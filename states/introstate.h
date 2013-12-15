#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SFML/Graphics.hpp>

#include "state.h"
#include "../world.h"
#include "../controllers/playercontroller.h"

#include <array>
#include <string>

class IntroState : public State
{
public:
    IntroState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

private:
    sf::Sprite      mSprite;
    sf::Text        mDialog;
    sf::Time        mDialogTime;
    int             mDialogState;
    std::array<std::string, 5> mDialogs;
    std::array<sf::Time, 5> mDialogTimes;
};

#endif // INTROSTATE_H
