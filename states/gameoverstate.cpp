#include "gameoverstate.h"
#include "../utils.h"

GameoverState::GameoverState(StateStack &stack, Context context) :
    State(stack, context),
    mSprite(context.textures->get(Textures::Gameovermenu))
{
    centerOrigin(mSprite);
    mSprite.setPosition(context.window->getSize().x / 2.f, context.window->getSize().y / 2.f);
}

void GameoverState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    sf::RectangleShape back;
    back.setFillColor(sf::Color(0,0,0, 200));
    back.setSize(window.getView().getSize());

    window.draw(back);

    window.draw(mSprite);
}


bool GameoverState::update(sf::Time /*dt*/)
{
    return false;
}


bool GameoverState::handleEvent(const sf::Event &event)
{
    //CommandQueue& commands = mWorld.getCommandQueue();

    // If ESC/Q key is pressed : leave
    if (event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::R:
                requestStackPop();
                break;

            case sf::Keyboard::Escape:
            case sf::Keyboard::Q:
                requestStackClear();
                break;

            default:break;
        }
    }

    return false;
}
