#include "titlestate.h"
#include "../utils.h"

TitleState::TitleState(StateStack &stack, Context context) :
    State(stack, context),
    mText(),
    mShowText(true),
    mTextEffectTime(sf::Time::Zero),
    mTitle(),
    mBackground(),
    mGround()
{
    mText.setFont(context.fonts->get(Fonts::Main));
    mText.setString("Press any key to continue !");
    centerOrigin(mText);
    mText.setPosition(context.window->getView().getSize().x / 2.f, context.window->getView().getSize().y-mText.getGlobalBounds().height-20);

    mTitle.setTexture(context.textures->get(Textures::Title));
    centerOrigin(mTitle);
    mTitle.setPosition(context.window->getView().getSize() / 2.f);

    mBackground.setTexture(context.textures->get(Textures::Background));
    mBackground.setPosition(sf::Vector2f(0,0));

    mGround.setTexture(context.textures->get(Textures::Ground));
    mGround.setPosition(sf::Vector2f(0,context.window->getView().getSize().y-context.textures->get(Textures::Ground).getSize().y));

    context.music->play(Musics::MainMenu);
    context.music->setVolume(20.f);
}


void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.draw(mBackground);
    window.draw(mGround);
    window.draw(mTitle);
    if (mShowText)
        window.draw(mText);
}

bool TitleState::update(sf::Time dt)
{
    mTextEffectTime += dt;

    if (mTextEffectTime >= sf::seconds(0.5f))
    {
        mShowText = !mShowText;
        mTextEffectTime = sf::Time::Zero;
    }

    return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
    // If any key is pressed, we leave
    if (event.type == sf::Event::KeyReleased)
    {
        requestStackPop();
        requestStackPush(States::Game);
    }

    return true;
}
