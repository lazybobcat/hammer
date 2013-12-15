#include "gamestate.h"

GameState::GameState(StateStack &stack, Context context) :
    State(stack, context),
    mWorld(*context.window, *context.textures, *context.fonts, *context.sounds, *context.music, *context.scripts, mPlayer),
    mHelp(context.textures->get(Textures::Help), sf::IntRect(0,0,1024,100)),
    mHelpTime(sf::Time::Zero),
    mHelpState(0)
{
    context.music->play(Musics::MainTheme);
    context.music->setVolume(20.f);

    mHelp.setPosition(sf::Vector2f(0, context.window->getSize().y - 100));
    mHelpTimes[0] = sf::seconds(5.f);
    mHelpTimes[1] = sf::seconds(0.5f);
    mHelpTimes[2] = sf::seconds(5.f);
    mHelpTimes[3] = sf::seconds(0.5f);
    mHelpTimes[4] = sf::seconds(3.f);
}


void GameState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    mWorld.draw();

    if(mHelpTime.asSeconds() <= 5.f)
    {
        window.draw(mHelp);
    }
}


bool GameState::update(sf::Time dt)
{
    mWorld.update(dt);
    mHelpTime += dt;

    if(mHelpState < 5 && mHelpTime > mHelpTimes[mHelpState])
    {
        mHelpState += 1;
        switch(mHelpState)
        {
            case 1:
                mHelp.setTextureRect(sf::IntRect(0,0,0,0));
                mHelpTime = sf::Time::Zero;
                break;

            case 2:
                mHelp.setTextureRect(sf::IntRect(0,100,1024,100));
                mHelpTime = sf::Time::Zero;
                break;

            case 3:
                mHelp.setTextureRect(sf::IntRect(0,0,0,0));
                mHelpTime = sf::Time::Zero;
                break;

            case 4:
                mHelp.setTextureRect(sf::IntRect(0,200,1024,100));
                mHelpTime = sf::Time::Zero;
                break;

            default:
                break;
        }
    }

    // Mission status check
    if(!mWorld.hasPlayerAlive())
    {
        requestStackPush(States::GameOver);
        mWorld.retry();
    }

    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleRealtimeInput(commands);

    // If time, updte some scripted events

    return true;
}


bool GameState::handleEvent(const sf::Event &event)
{
    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleEvent(event, commands);

    // If ESC key is pressed, we leave
    if (event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                requestStackPush(States::Pause);
                break;

            default:break;
        }
    }

    return true;
}

void GameState::onPause()
{
    getContext().music->pause();
}

void GameState::onResume()
{
    getContext().music->pause(false);
}
