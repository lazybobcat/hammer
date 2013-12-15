#include "playerentity.h"
#include "cameranode.h"

#include <iostream>

PlayerEntity::PlayerEntity(TextureHolder &textures) :
    Entity(textures, Entity::Player),
    mSprite(textures.get(Textures::PlayerStanding), sf::IntRect(0,0,64,64)),
    mMovingAnimation(false),
    mIsFiring(false),
    mSpawnFiringSound(false)
{
    textures.get(Textures::PlayerStanding).setSmooth(false);
    textures.get(Textures::PlayerWalkingLeft).setSmooth(false);
    textures.get(Textures::PlayerWalkingRight).setSmooth(false);
    textures.get(Textures::PlayerAttackingLeft).setSmooth(false);
    textures.get(Textures::PlayerAttackingRight).setSmooth(false);

    mSprite.setOrigin(sf::Vector2f(32.f, 64.f));
    mSprite.setScale(sf::Vector2f(4.f, 4.f));

    mAnimations[WalkingLeft].setTexture(textures.get(Textures::PlayerWalkingLeft));
    mAnimations[WalkingLeft].setFrameSize(sf::Vector2i(64,64));
    mAnimations[WalkingLeft].setNumFrames(4);
    mAnimations[WalkingLeft].setDuration(sf::seconds(0.7f));
    mAnimations[WalkingLeft].setRepeating(true);
    mAnimations[WalkingLeft].setOrigin(sf::Vector2f(32.f, 64.f));
    mAnimations[WalkingLeft].setScale(sf::Vector2f(4.f, 4.f));

    mAnimations[WalkingRight].setTexture(textures.get(Textures::PlayerWalkingRight));
    mAnimations[WalkingRight].setFrameSize(sf::Vector2i(64,64));
    mAnimations[WalkingRight].setNumFrames(4);
    mAnimations[WalkingRight].setDuration(sf::seconds(0.7f));
    mAnimations[WalkingRight].setRepeating(true);
    mAnimations[WalkingRight].setOrigin(sf::Vector2f(32.f, 64.f));
    mAnimations[WalkingRight].setScale(sf::Vector2f(4.f, 4.f));

    mAnimations[AttackingLeft].setTexture(textures.get(Textures::PlayerAttackingLeft));
    mAnimations[AttackingLeft].setFrameSize(sf::Vector2i(64,64));
    mAnimations[AttackingLeft].setNumFrames(5);
    mAnimations[AttackingLeft].setDuration(sf::seconds(0.4f));
    mAnimations[AttackingLeft].setRepeating(false);
    mAnimations[AttackingLeft].setOrigin(sf::Vector2f(32.f, 64.f));
    mAnimations[AttackingLeft].setScale(sf::Vector2f(4.f, 4.f));

    mAnimations[AttackingRight].setTexture(textures.get(Textures::PlayerAttackingRight));
    mAnimations[AttackingRight].setFrameSize(sf::Vector2i(64,64));
    mAnimations[AttackingRight].setNumFrames(5);
    mAnimations[AttackingRight].setDuration(sf::seconds(0.4f));
    mAnimations[AttackingRight].setRepeating(false);
    mAnimations[AttackingRight].setOrigin(sf::Vector2f(32.f, 64.f));
    mAnimations[AttackingRight].setScale(sf::Vector2f(4.f, 4.f));
}


void PlayerEntity::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    if(isDestroyed())
    {
        return;
    }

    updateDirection();
    updateAnimation(dt);

    if(mIsFiring)
    {
        Animations dir = getDirection() == Entity::Left ? AttackingLeft : AttackingRight;
        if(mAnimations[dir].isFinished())
        {
            mIsFiring = false;
            mAnimations[dir].restart();
        }

        if(mSpawnFiringSound)
        {
            mSpawnFiringSound = false;
            playLocalSound(commands, Sounds::HammerStrike);
            Command command;
            command.category = Category::Camera;
            command.action = derivedAction<CameraNode>([&](CameraNode& c, sf::Time) {
                c.shake(sf::seconds(0.05f));
            });
            commands.push(command);
        }
    }



    //mHealthbar->setPercentage(getHealthpoints() / 100.f);

    /*if(!mUIKey)
    {
        commands.push(mAddUiCommand);
    }*/

    Entity::updateCurrent(dt, commands);
}


void PlayerEntity::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    /*if(isDestroyed())
    {
        target.draw(mDieAnimation, states);
        return;
    }*/

    /*sf::FloatRect rect = getBoundingRect();
    sf::RectangleShape shape;
    shape.setPosition(sf::Vector2f(rect.left, rect.top));
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(1.f);
    target.draw(shape);*/

    if(mIsFiring)
    {
        Animations dir = getDirection() == Entity::Left ? AttackingLeft : AttackingRight;
        target.draw(mAnimations[dir], states);
    }
    else if(mMovingAnimation)
    {
        Animations dir = getDirection() == Entity::Left ? WalkingLeft : WalkingRight;
        target.draw(mAnimations[dir], states);
    }
    else
    {
        target.draw(mSprite, states);
    }
}

void PlayerEntity::updateAnimation(sf::Time dt)
{
    if(isDestroyed())
    {
        mDieAnimation.update(dt);
    }
    else
    {
        if(mIsFiring)
        {
            Animations dir = getDirection() == Entity::Left ? AttackingLeft : AttackingRight;
            mAnimations[dir].update(dt);
        }
        else
        {
            Animations dir = getDirection() == Entity::Left ? WalkingLeft : WalkingRight;
            mAnimations[dir].update(dt);
        }
    }

    mMovingAnimation = isMoving();
}

void PlayerEntity::updateDirection()
{
    switch(getDirection())
    {
        case Entity::Right:
            mSprite.setTextureRect(sf::IntRect(64,0,64,64));
            break;

        case Entity::Left:
            mSprite.setTextureRect(sf::IntRect(0,0,64,64));
            break;
    }
}

void PlayerEntity::move(Direction dir)
{
    if(mIsFiring) return;

    Entity::move(dir);
}

void PlayerEntity::attack()
{
    if(!mIsFiring)
    {
        mIsFiring = true;
        mSpawnFiringSound = true;
    }
}

bool PlayerEntity::isAttacking() const
{
    return mIsFiring;
}


unsigned int PlayerEntity::getCategory() const
{
    return Category::Player;
}

sf::FloatRect PlayerEntity::getBoundingRect() const
{
    //return getWorldTransform().transformRect(sf::FloatRect(-16.f*4,-32.f*4,128.f,128.f));
    return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

bool PlayerEntity::isCollidable() const
{
    return true;
}

bool PlayerEntity::isAllied() const
{
    return true;
}

bool PlayerEntity::isMarkedForRemoval() const
{
    return isDestroyed(); //&& mAnimation[getDirection()].isFinished();
}
