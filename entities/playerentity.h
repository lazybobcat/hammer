#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "entity.h"
#include "../resources/resourceholder.h"
#include "../resources/resourceidentifiers.h"
#include "../resources/animation.h"

#include <array>

class PlayerEntity : public Entity
{
public:
    typedef std::unique_ptr<PlayerEntity> Ptr;

    enum Animations {
        WalkingLeft,
        WalkingRight,
        AttackingLeft,
        AttackingRight
    };

public:
    PlayerEntity(TextureHolder& textures);

    virtual unsigned int        getCategory() const;
    virtual void                move(Direction dir);

    virtual bool    isAllied() const;

    virtual sf::FloatRect   getBoundingRect() const;
    virtual bool            isCollidable() const;
    virtual bool            isMarkedForRemoval() const;

    void                    attack();
    bool                    isAttacking() const;

private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands);
    void         updateAnimation(sf::Time dt);
    void         updateDirection();

private:
    sf::Sprite      mSprite;
    std::array<Animation, 4> mAnimations;
    Animation       mDieAnimation;
    bool            mMovingAnimation;

    //Command         mFireCommand;
    bool            mIsFiring;
    bool            mSpawnFiringSound;
    /*Healthbar*      mHealthbar;
    Command         mAddUiCommand;*/
};

#endif // PLAYERENTITY_H
