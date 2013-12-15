#include "object.h"

Object::Object(TextureHolder &textures, Textures::ID text, sf::IntRect rect) :
    SceneNode(Category::Object),
    mSprite(textures.get(text), rect),
    mIsDestroyed(false),
    mTimer(sf::Time::Zero)
{
}

void Object::setEffect(Effect e)
{
    mEffect = e;
}

void Object::apply(Entity &target)
{
    mEffect(target);
    destroy();
}

void Object::updateCurrent(sf::Time dt, CommandQueue &/*commands*/)
{
    mTimer += dt;
    if(mTimer >= sf::seconds(6.f))
        destroy();
}

void Object::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

bool Object::isCollidable()
{
    return !isDestroyed();
}

void Object::destroy()
{
    mIsDestroyed = true;
}

bool Object::isDestroyed() const
{
    return mIsDestroyed;
}
