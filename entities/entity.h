#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>

#include "scenenode.h"
#include "soundnode.h"
#include "../resources/animation.h"

#include <array>

class CommandQueue;

class Entity : public SceneNode
{
public:
    enum Direction {
        Left,
        Right
    };

    enum Type {
        Player,
        Allied,
        Rabbit,
        Tentacle,
        Crawler,
        Boss1,
        Boss2,
        Boss3,
        Object,
        TypeCount
    };

public:
    Entity(TextureHolder &textures, Entity::Type type = Tentacle);
    virtual ~Entity() {}

    void        damage(int points);
    void        heal(int points);
    virtual void        destroy();
    void        sacrifice();
    int         getHealthpoints() const;
    int         getMaxHealthpoints() const;
    virtual int getDamages() const;
    bool        isDestroyed() const;
    bool        hasBeenSacrificed() const;
    bool        isKnocked() const;
    bool        canBeHurt() const;
    void        setAcceleration(float a);

    virtual     sf::FloatRect getBoundingRect() const;

    void        playLocalSound(CommandQueue& commands, Sounds::ID sound);

    Direction   getDirection() const;
    virtual void setDirection(Direction dir);

    virtual void move(Direction dir);
    void         demove(); // Soooooo ugly ....
    void         stop();

    virtual bool isAllied() const;
    virtual bool isMarkedForRemoval() const;
    bool         isMoving() const;

    virtual unsigned int    getCategory() const;

    void            knock();
    void            unknock();
protected:
    virtual void    updateCurrent(sf::Time dt, CommandQueue &commands);

protected:
    int         mHealthpoints;
    int         mDamages;
    float       mAcceleration;
    bool        mSacrificed;
    bool        mJustGetHurt;
    sf::Time    mLastHurtTime;
    bool        mKnocked;

    Direction   mDirection;
    Type        mType;
    bool        mIsMoving;
    //bool        mIsFiring;
    //sf::Time    mFireCooldown;

    //Command     mFireCommand;
    sf::Vector2f mLastSafePosition;
};

#endif // ENTITY_H
