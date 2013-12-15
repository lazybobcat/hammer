#include "emitternode.h"
#include "particlenode.h"

EmitterNode::EmitterNode(Particle::Type type) :
    SceneNode(),
    mAccumulatedTime(sf::seconds(1.f) / 5.f),
    mType(type),
    mParticleSystem(nullptr),
    mHasEmitted(0)
{
}

void EmitterNode::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    if(mParticleSystem && mHasEmitted < 3)
    {
        emitParticles(dt);
    }
    else
    {
        auto finder = [this](ParticleNode& container, sf::Time) {
            if(container.getParticleType() == mType)
                mParticleSystem = &container;
        };
        Command command;
        command.action = derivedAction<ParticleNode>(finder);
        command.category = Category::ParticleSystem;
        commands.push(command);
    }
}

void EmitterNode::emitParticles(sf::Time dt)
{
    const sf::Time interval = sf::seconds(1.f) / 5.f;
    mAccumulatedTime += dt;

    while(mAccumulatedTime > interval)
    {
        for(unsigned int i = 0; i < 20; ++i)
        {
            mParticleSystem->addParticle(getWorldPosition());
        }

        mHasEmitted+=1;
        mAccumulatedTime -= interval;
    }
}
