#include "application.h"
#include "utils.h"
#include "states/titlestate.h"
#include "states/gamestate.h"
#include "states/pausestate.h"
#include "states/gameoverstate.h"
#include "states/introstate.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application(unsigned int width, unsigned int height, const std::string &title) :
    mWindow(sf::VideoMode(width,height), title.c_str(), sf::Style::Close),
    mTextures(),
    mFonts(),
    mSounds(),
    mMusic(),
    mScripts(),
    mPlayer(),
    mStateStack(State::Context(mWindow, mTextures, mFonts, mSounds, mMusic, mScripts, mPlayer)),
    mStatisticsText(),
    mStatisticsUpdateTime(),
    mStatisticsNumFrames(0)
{
    mWindow.setKeyRepeatEnabled(false);

    // Resources
    mFonts.load(Fonts::Main, "assets/fonts/HandTIMES.ttf");
    mFonts.load(Fonts::Grinched, "assets/fonts/grinched.ttf");

    mTextures.load(Textures::Particle, "assets/textures/particle.png");
    mTextures.load(Textures::Title, "assets/textures/hammer-title.png");
    mTextures.load(Textures::Background, "assets/textures/bg.png");
    mTextures.load(Textures::Ground, "assets/textures/ground.png");
    mTextures.load(Textures::PlayerStanding, "assets/textures/player-standing.png");
    mTextures.load(Textures::PlayerWalkingLeft, "assets/textures/player-walking-left.png");
    mTextures.load(Textures::PlayerWalkingRight, "assets/textures/player-walking-right.png");
    mTextures.load(Textures::PlayerAttackingLeft, "assets/textures/player-attacking-left.png");
    mTextures.load(Textures::PlayerAttackingRight, "assets/textures/player-attacking-right.png");
    mTextures.load(Textures::RabbitLeft, "assets/textures/rabbit-left.png");
    mTextures.load(Textures::RabbitRight, "assets/textures/rabbit-right.png");
    mTextures.load(Textures::TentacleLeft, "assets/textures/tentacle-left.png");
    mTextures.load(Textures::TentacleRight, "assets/textures/tentacle-right.png");
    mTextures.load(Textures::CrawlerLeft, "assets/textures/crawler-left.png");
    mTextures.load(Textures::CrawlerRight, "assets/textures/crawler-right.png");
    mTextures.load(Textures::Knocked, "assets/textures/knocked.png");
    mTextures.load(Textures::Objects, "assets/textures/objects.png");
    mTextures.load(Textures::Pvbar, "assets/textures/pvbar.png");
    mTextures.load(Textures::Help, "assets/textures/help.png");
    mTextures.load(Textures::Pausemenu, "assets/textures/pausemenu.png");
    mTextures.load(Textures::Gameovermenu, "assets/textures/gameovermenu.png");
    mTextures.load(Textures::Intro, "assets/textures/intro.png");

    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f,5.f);
    mStatisticsText.setCharacterSize(10);

    registerStates();
    exposeToLua();

    // Scripts
    mScripts.registerFile(Scripts::Loading, "assets/scripts/loading.lua");
    mScripts.registerFile(Scripts::Level1, "assets/scripts/level1.lua");
    mScripts.registerFile(Scripts::Level2, "assets/scripts/level2.lua");
    mScripts.registerFile(Scripts::Level3, "assets/scripts/level3.lua");
    mScripts.registerFile(Scripts::Level4, "assets/scripts/level4.lua");
    mScripts.registerFile(Scripts::Level5, "assets/scripts/level5.lua");
    mScripts.registerFile(Scripts::Level6, "assets/scripts/level6.lua");
    mScripts.registerFile(Scripts::Level7, "assets/scripts/level7.lua");
    mScripts.registerFile(Scripts::Level8, "assets/scripts/level8.lua");
    mScripts.registerFile(Scripts::Level9, "assets/scripts/level9.lua");
    mScripts.registerFile(Scripts::Level10, "assets/scripts/level10.lua");
    mScripts.registerFile(Scripts::Level11, "assets/scripts/level11.lua");
    mScripts.registerFile(Scripts::Level12, "assets/scripts/level12.lua");
    mScripts.registerFile(Scripts::Level13, "assets/scripts/level13.lua");
    mScripts.registerFile(Scripts::Level14, "assets/scripts/level14.lua");
    mScripts.registerFile(Scripts::Level15, "assets/scripts/level15.lua");
    mScripts.registerFile(Scripts::LevelInfinite, "assets/scripts/levelinfinite.lua");


    mStateStack.pushState(States::Intro);
}



void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            update(TimePerFrame);

            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }

        updateStatistics(elapsedTime);
        render();
    }
}

void Application::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);
        if(event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();
    mStateStack.draw();

    mWindow.setView(mWindow.getDefaultView());
    //mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Application::registerStates()
{
    mStateStack.registerState<IntroState>(States::Intro);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<GameoverState>(States::GameOver);
}

void Application::updateStatistics(sf::Time elapsedTime)
{
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;

    if(mStatisticsUpdateTime >= sf::seconds(1.f))
    {
        mStatisticsText.setString(
                    "Frames/sec = " + toString(mStatisticsNumFrames) + "\n" +
                    "Time/update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us"
        );

        mStatisticsNumFrames = 0;
        mStatisticsUpdateTime -= sf::seconds(1.f);
    }
}
