#include "combattextnode.h"
#include "../utils.h"

CombatTextNode::CombatTextNode(const std::string& text, const FontHolder& fonts) :
    mText(text, fonts.get(Fonts::Grinched), 20),
    mSize(20),
    mElapsedTime(sf::Time::Zero),
    mTotalElapsedTime(sf::Time::Zero)
{
    centerOrigin(mText);
    mText.setColor(sf::Color::White);
}

void CombatTextNode::setText(const std::string &text)
{
    mText.setString(text);
    centerOrigin(mText);
}

void CombatTextNode::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    const sf::Time interval = sf::seconds(1.f) / 24.f;

    mElapsedTime += dt;
    mTotalElapsedTime += dt;

    while(mElapsedTime > interval)
    {
        mElapsedTime -= interval;
        mSize+=1;
        if(mTotalElapsedTime.asSeconds() > 1.f && mSize <= 51)
        {
            mText.setColor(sf::Color(255,255,255, 255-mSize*5));
        }
        else if(mTotalElapsedTime.asSeconds() > 1.f && mSize > 51)
        {
            Command command;
            command.category = Category::UILayer;
            command.action = derivedAction<SceneNode>([this] (SceneNode& node, sf::Time) {
                node.detachChild(*this);
            });
            commands.push(command);
        }
        mText.setCharacterSize(mSize);
        //centerOrigin(mText);
    }
}

void CombatTextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mText, states);
}
