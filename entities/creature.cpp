#include "creature.h"
#include "../controllers/aicontroller.h"
#include "../utils.h"

#include <iostream>

////////////////////////////////////////////////

namespace
{
    std::array<std::string, 6> initSrings()
    {
        std::array<std::string, 6> table;
        table[0] = "SMASHED";
        table[1] = "KNOCKED DOWN TO THE GROUND";
        table[2] = "SHATTERED";
        table[3] = "CRUSHED";
        table[4] = "YOU FUCKER";
        table[5] = "WIPED OUT";

        return table;
    }

    std::array<std::string, 6> StringTable = initSrings();
}

////////////////////////////////////////////////

Creature::Creature(TextureHolder &textures, FontHolder& fonts, Type type, AIController& ctrl) :
    Entity(textures, type),
    mFonts(fonts),
    mAIController(ctrl),
    mEmitter(nullptr),
    mDestroyedSince(sf::Time::Zero)
{
    mSprite.setOrigin(sf::Vector2f(16.f, 32.f));

    mKnockedAnimation.setTexture(textures.get(Textures::Knocked));
    mKnockedAnimation.setFrameSize(sf::Vector2i(32,32));
    mKnockedAnimation.setNumFrames(4);
    mKnockedAnimation.setDuration(sf::seconds(0.5f));
    mKnockedAnimation.setRepeating(true);
    mKnockedAnimation.setOrigin(sf::Vector2f(16.f, 32.f));

    switch(type)
    {
        case Rabbit:
        {
            sf::Vector2f scale = sf::Vector2f(2.f, 2.f);
            textures.get(Textures::RabbitLeft).setSmooth(false);
            mKnockedAnimation.setPosition(sf::Vector2f(0, -32.f*(scale.y+0.5f)));
            mSprite.setTexture(textures.get(Textures::RabbitLeft));
            mSprite.setTextureRect(sf::IntRect(0,0,32,32));
            mSprite.setScale(scale);
            mAnimations[Left].setTexture(textures.get(Textures::RabbitLeft));
            mAnimations[Left].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Left].setNumFrames(4);
            mAnimations[Left].setDuration(sf::seconds(0.7f));
            mAnimations[Left].setRepeating(true);
            mAnimations[Left].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Left].setScale(scale);

            textures.get(Textures::RabbitRight).setSmooth(false);
            mAnimations[Right].setTexture(textures.get(Textures::RabbitRight));
            mAnimations[Right].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Right].setNumFrames(4);
            mAnimations[Right].setDuration(sf::seconds(0.7f));
            mAnimations[Right].setRepeating(true);
            mAnimations[Right].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Right].setScale(scale);
            break;
        }

        case Tentacle:
        {
            sf::Vector2f scale = sf::Vector2f(2.f, 2.f);
            textures.get(Textures::TentacleLeft).setSmooth(false);
            mKnockedAnimation.setPosition(sf::Vector2f(0, -32.f*(scale.y+0.5f)));
            mSprite.setTexture(textures.get(Textures::TentacleLeft));
            mSprite.setTextureRect(sf::IntRect(0,0,32,32));
            mSprite.setScale(scale);
            mAnimations[Left].setTexture(textures.get(Textures::TentacleLeft));
            mAnimations[Left].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Left].setNumFrames(3);
            mAnimations[Left].setDuration(sf::seconds(0.7f));
            mAnimations[Left].setRepeating(true);
            mAnimations[Left].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Left].setScale(scale);

            textures.get(Textures::TentacleRight).setSmooth(false);
            mAnimations[Right].setTexture(textures.get(Textures::TentacleRight));
            mAnimations[Right].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Right].setNumFrames(3);
            mAnimations[Right].setDuration(sf::seconds(0.7f));
            mAnimations[Right].setRepeating(true);
            mAnimations[Right].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Right].setScale(scale);
            break;
        }

        case Crawler:
        {
            sf::Vector2f scale = sf::Vector2f(4.f, 4.f);
            textures.get(Textures::CrawlerLeft).setSmooth(false);
            mKnockedAnimation.setPosition(sf::Vector2f(0, -32.f*(scale.y+0.5f)));
            mSprite.setTexture(textures.get(Textures::CrawlerLeft));
            mSprite.setTextureRect(sf::IntRect(0,0,32,32));
            mSprite.setScale(scale);
            mAnimations[Left].setTexture(textures.get(Textures::CrawlerLeft));
            mAnimations[Left].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Left].setNumFrames(4);
            mAnimations[Left].setDuration(sf::seconds(0.7f));
            mAnimations[Left].setRepeating(true);
            mAnimations[Left].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Left].setScale(scale);

            textures.get(Textures::CrawlerRight).setSmooth(false);
            mAnimations[Right].setTexture(textures.get(Textures::CrawlerRight));
            mAnimations[Right].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Right].setNumFrames(4);
            mAnimations[Right].setDuration(sf::seconds(0.7f));
            mAnimations[Right].setRepeating(true);
            mAnimations[Right].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Right].setScale(scale);
            break;
        }

        case Boss1:
        case Boss3:
        {
            sf::Vector2f scale = sf::Vector2f(10.f, 10.f);
            textures.get(Textures::CrawlerLeft).setSmooth(false);
            mKnockedAnimation.setPosition(sf::Vector2f(0, -32.f*(scale.y+0.5f)));
            mSprite.setTexture(textures.get(Textures::CrawlerLeft));
            mSprite.setTextureRect(sf::IntRect(0,0,32,32));
            mSprite.setScale(scale);
            mAnimations[Left].setTexture(textures.get(Textures::CrawlerLeft));
            mAnimations[Left].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Left].setNumFrames(4);
            mAnimations[Left].setDuration(sf::seconds(0.7f));
            mAnimations[Left].setRepeating(true);
            mAnimations[Left].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Left].setScale(scale);

            textures.get(Textures::CrawlerRight).setSmooth(false);
            mAnimations[Right].setTexture(textures.get(Textures::CrawlerRight));
            mAnimations[Right].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Right].setNumFrames(4);
            mAnimations[Right].setDuration(sf::seconds(0.7f));
            mAnimations[Right].setRepeating(true);
            mAnimations[Right].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Right].setScale(scale);
            break;
        }

        case Boss2:
        {
            sf::Vector2f scale = sf::Vector2f(10.f, 10.f);
            textures.get(Textures::TentacleLeft).setSmooth(false);
            mKnockedAnimation.setPosition(sf::Vector2f(0, -32.f*(scale.y+0.5f)));
            mSprite.setTexture(textures.get(Textures::TentacleLeft));
            mSprite.setTextureRect(sf::IntRect(0,0,32,32));
            mSprite.setScale(scale);
            mAnimations[Left].setTexture(textures.get(Textures::TentacleLeft));
            mAnimations[Left].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Left].setNumFrames(3);
            mAnimations[Left].setDuration(sf::seconds(0.7f));
            mAnimations[Left].setRepeating(true);
            mAnimations[Left].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Left].setScale(scale);

            textures.get(Textures::TentacleRight).setSmooth(false);
            mAnimations[Right].setTexture(textures.get(Textures::TentacleRight));
            mAnimations[Right].setFrameSize(sf::Vector2i(32,32));
            mAnimations[Right].setNumFrames(3);
            mAnimations[Right].setDuration(sf::seconds(0.7f));
            mAnimations[Right].setRepeating(true);
            mAnimations[Right].setOrigin(sf::Vector2f(16.f, 32.f));
            mAnimations[Right].setScale(scale);
            break;
        }

        default:break;
    }
}

void Creature::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    updateAnimation(dt);

    if(isDestroyed() && !hasBeenSacrificed())
    {
        if(mEmitter)
        {
            mEmitter->update(dt, commands);
            mDestroyedSince += dt;
        }
        else
        {
            // blood
            std::unique_ptr<EmitterNode> e(new EmitterNode(Particle::Default));
            e->setPosition(sf::Vector2f(0.f, -32.f));
            mEmitter = e.get();
            attachChild(std::move(e));

            // text
            if(randomInt(4) == 0)
            {
                Command command;
                command.category = Category::UILayer;
                command.action = derivedAction<SceneNode>([this] (SceneNode& node, sf::Time) {
                    std::string str = StringTable[randomInt(StringTable.size())];
                    std::unique_ptr<CombatTextNode> tn(new CombatTextNode(str, mFonts));
                    tn->setPosition(sf::Vector2f(getPosition().x, getPosition().y-getBoundingRect().height/2));
                    node.attachChild(std::move(tn));
                });
                commands.push(command);
            }
        }
    }

    mAIController.update(commands, *this);
    Entity::updateCurrent(dt, commands);
}

void Creature::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(isDestroyed()) return;

    /*sf::FloatRect rect = getBoundingRect();
    sf::RectangleShape shape;
    shape.setPosition(sf::Vector2f(rect.left, rect.top));
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(1.f);
    target.draw(shape);*/

    target.draw(mAnimations[getDirection()], states);
    if(isKnocked() && !isDestroyed())
    {
        target.draw(mKnockedAnimation, states);
    }
}

void Creature::updateAnimation(sf::Time dt)
{
    if(isDestroyed())
    {

    }
    else if(isKnocked())
    {
        mKnockedAnimation.update(dt);
    }
    else
    {
        mAnimations[getDirection()].update(dt);
    }
}

sf::FloatRect Creature::getBoundingRect() const
{
    return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

bool Creature::isCollidable() const { return true; }
bool Creature::isMarkedForRemoval() const { return isDestroyed() && mDestroyedSince.asSeconds() > 2.5f; }
