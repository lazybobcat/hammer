#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "../resources/resourceholder.h"
#include "../resources/resourceidentifiers.h"
#include "../resources/animation.h"
#include "emitternode.h"
#include "combattextnode.h"

#include <array>
#include <string>

class AIController;

class Creature : public Entity
{
public:
    typedef std::unique_ptr<Creature> Ptr;

public:
    Creature(TextureHolder& textures, FontHolder& fonts, Entity::Type type, AIController &ctrl);
    virtual ~Creature(){}

    virtual sf::FloatRect   getBoundingRect() const;
    virtual bool            isCollidable() const;
    virtual bool            isMarkedForRemoval() const;

protected:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands);
    void         updateAnimation(sf::Time dt);

private:
    FontHolder&              mFonts;
    sf::Sprite               mSprite;
    std::array<Animation, 2> mAnimations;
    Animation                mKnockedAnimation;
    AIController&            mAIController;
    EmitterNode*             mEmitter;
    sf::Time                 mDestroyedSince;
};

#endif // CREATURE_H
