#ifndef OBJECT_H
#define OBJECT_H

#include "scenenode.h"
#include "entity.h"
#include "../events/commandqueue.h"
#include "../resources/resourceidentifiers.h"
#include "../resources/resourceholder.h"

#include <functional>

class Object : public SceneNode
{
public:
    typedef std::function<void(Entity&)> Effect;

public:
    Object(TextureHolder& textures, Textures::ID text, sf::IntRect rect = sf::IntRect());

    void            setEffect(Effect e);
    virtual void    apply(Entity& target);

    virtual bool    isCollidable();
    void            destroy();
    virtual bool    isDestroyed() const;

protected:
    virtual void    updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    Effect      mEffect;
    sf::Sprite  mSprite;
    bool        mIsDestroyed;
    sf::Time    mTimer;
};

#endif // OBJECT_H
