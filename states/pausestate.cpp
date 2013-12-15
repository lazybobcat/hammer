#include "pausestate.h"
#include "../utils.h"

PauseState::PauseState(StateStack &stack, Context context) :
    State(stack, context),
    mSprite(context.textures->get(Textures::Pausemenu))
{
    centerOrigin(mSprite);
    mSprite.setPosition(context.window->getSize().x / 2.f, context.window->getSize().y / 2.f);
}

void PauseState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    sf::RectangleShape back;
    back.setFillColor(sf::Color(0,0,0, 200));
    back.setSize(window.getView().getSize());

    window.draw(back);

    window.draw(mSprite);
}


bool PauseState::update(sf::Time /*dt*/)
{
    return false;
}


bool PauseState::handleEvent(const sf::Event &event)
{
    //CommandQueue& commands = mWorld.getCommandQueue();

    // If ESC key is pressed, we leave
    if (event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                requestStackPop();
                break;

            case sf::Keyboard::Q:
                requestStackClear();
                break;

            default:break;
        }
    }

    return false;
}
