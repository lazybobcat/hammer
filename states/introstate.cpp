#include "introstate.h"
#include "../utils.h"

IntroState::IntroState(StateStack &stack, Context context) :
    State(stack, context),
    mSprite(context.textures->get(Textures::Intro), sf::IntRect(0,0,65,67)),
    mDialog(),
    mDialogTime(sf::Time::Zero),
    mDialogState(0)
{
    centerOrigin(mSprite);
    mSprite.setScale(sf::Vector2f(4.f, 4.f));
    mSprite.setPosition(context.window->getSize().x / 2.f, (context.window->getSize().y / 2.f) - 30.f);

    mDialog.setFont(context.fonts->get(Fonts::Grinched));
    mDialog.setCharacterSize(40);
    mDialog.setString(" ");
    centerOrigin(mDialog);
    mDialog.setPosition(context.window->getView().getSize().x / 2.f, context.window->getView().getSize().y-mDialog.getGlobalBounds().height-40);

    //

    mDialogs[0] = " ";
    mDialogs[1] = "I only got one gift for Christmas...";
    mDialogs[2] = "I got a HAMMER !";
    mDialogs[3] = "But a HUGE one !";
    mDialogs[4] = "I need to bash some stuff... Let's SMASH !";

    mDialogTimes[0] = sf::seconds(0.5f);
    mDialogTimes[1] = sf::seconds(3.4f);
    mDialogTimes[2] = sf::seconds(2.4f);
    mDialogTimes[3] = sf::seconds(2.4f);
    mDialogTimes[4] = sf::seconds(4.0f);
}

void IntroState::draw()
{
    sf::RenderWindow& window = *getContext().window;


    window.draw(mSprite);
    window.draw(mDialog);
}


bool IntroState::update(sf::Time dt)
{
    mDialogTime += dt;

    if(mDialogTime >= mDialogTimes[mDialogState])
    {
        mDialogTime = sf::Time::Zero;
        mDialogState += 1;

        if(mDialogState >= mDialogs.size())
        {
            requestStackPop();
            requestStackPush(States::Title);
        }
        else
        {
            mDialog.setString(mDialogs[mDialogState]);
            centerOrigin(mDialog);

            if(mDialogState == 2)
            {
                mSprite.setTextureRect(sf::IntRect(65,0,65,67));
            }
        }
    }

    return false;
}


bool IntroState::handleEvent(const sf::Event &event)
{
    //CommandQueue& commands = mWorld.getCommandQueue();

    if (event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                requestStackPop();
                requestStackPush(States::Title);
                break;

            default:break;
        }
    }

    return false;
}

