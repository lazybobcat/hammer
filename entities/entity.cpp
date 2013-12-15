#include "entity.h"
#include "scenenode.h"
#include "../events/commandqueue.h"
#include "../datatables.h"

#include <iostream>

namespace
{
    std::vector<EntityData> Table = initializeEntityData();
}

Entity::Entity(TextureHolder &textures, Entity::Type type) :
    SceneNode(Category::Enemy),
    mHealthpoints(1),
    mDamages(0),
    mAcceleration(1.f),
    mSacrificed(false),
    mJustGetHurt(false),
    mLastHurtTime(sf::Time::Zero),
    mKnocked(false),
    mDirection(Left),
    mType(type),
    mIsMoving(false)
{
    mHealthpoints = Table[mType].healthpoints;
    mDamages = Table[mType].damages;
}

void Entity::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    if(isDestroyed())
        return;

    if(mJustGetHurt)
    {
        mLastHurtTime += dt;
        if(mLastHurtTime > sf::seconds(0.8f))
        {
            mJustGetHurt = false;
            mLastHurtTime = sf::Time::Zero;
            mKnocked = false;
        }
    }

    if(mIsMoving)
    {
        mLastSafePosition = getWorldPosition();
        switch(mDirection)
        {
            case Left:
                SceneNode::move(sf::Vector2f(-Table[mType].speed*mAcceleration*dt.asSeconds(), 0.f));
                break;

            case Right:
                SceneNode::move(sf::Vector2f(Table[mType].speed*mAcceleration*dt.asSeconds(), 0.f));
                break;
        }
        mIsMoving = false;
    }
}

void Entity::demove()
{
    setPosition(mLastSafePosition);
}

void Entity::stop()
{
    mIsMoving = false;
}

int Entity::getDamages() const
{
    return mDamages;
}

void Entity::move(Direction dir)
{
    if(isKnocked()) return;

    setDirection(dir);
    mIsMoving = true;
}

bool Entity::isMoving() const
{
    return mIsMoving;
}

void Entity::damage(int points)
{
    if(mJustGetHurt) return;

    mHealthpoints -= points;
    mJustGetHurt = true;
    knock();
    std::cout << "Entity recieved " << points << " damages" << std::endl;
}

void Entity::knock()
{
    if(mType != Entity::Player)
    {
        mKnocked = true;
    }
}

void Entity::unknock()
{
    mKnocked = false;
}

void Entity::heal(int points)
{
    mHealthpoints += points;
    if(mHealthpoints > Table[mType].healthpoints)
    {
        mHealthpoints = Table[mType].healthpoints;
    }
    std::cout << "Entity recieved " << points << " heal" << std::endl;
}

void Entity::destroy()
{
    mHealthpoints = 0;
    std::cout << "Entity destroyed" << std::endl;
}

void Entity::sacrifice()
{
    destroy();
    mSacrificed = true;
}

int Entity::getHealthpoints() const
{
    return mHealthpoints;
}

int Entity::getMaxHealthpoints() const
{
    return Table[mType].healthpoints;
}

bool Entity::isDestroyed() const
{
    return (mHealthpoints <= 0);
}

bool Entity::hasBeenSacrificed() const
{
    return mSacrificed;
}

bool Entity::isKnocked() const
{
    return mKnocked;
}

bool Entity::canBeHurt() const
{
    return !mJustGetHurt;
}

void Entity::playLocalSound(CommandQueue &commands, Sounds::ID sound)
{
    Command command;
    command.category = Category::SoundEffect;
    command.action = derivedAction<SoundNode>(std::bind(&SoundNode::playSound, std::placeholders::_1, sound, getWorldPosition()));

    commands.push(command);
}

Entity::Direction Entity::getDirection() const
{
    return mDirection;
}

sf::FloatRect Entity::getBoundingRect() const
{
    return sf::FloatRect();
}

void Entity::setDirection(Direction dir)
{
    mDirection = dir;
}

unsigned int Entity::getCategory() const
{
    switch(mType)
    {
        case Rabbit:
            return Category::Ally;
        case Player:
            return Category::Player;

        case Tentacle:
        case Crawler:
        default:
            return Category::Enemy;
    }
}

void Entity::setAcceleration(float a)
{
    mAcceleration = a;
}

bool Entity::isAllied() const { return (mType == Player || mType == Rabbit); }
bool Entity::isMarkedForRemoval() const { return isDestroyed(); }
