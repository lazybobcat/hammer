#include "lua/luaexposal.h"
#include <SFML/System/Vector2.hpp>
#include "../entities/creature.h"
#include "../world.h"


void exposeVector()
{
    SLB::Class<sf::Vector2f>("Vector2f")
            .constructor<float, float>()
            .property("x", &sf::Vector2f::x)
            .property("y", &sf::Vector2f::y);
}

void exposeSceneNode()
{
    SLB::Class<SceneNode, SLB::Instance::NoCopy>("SceneNode")
            .constructor<Category::Type>()
            .set("getWorldPosition", &SceneNode::getWorldPosition);
}

void exposeEntity()
{
    /*SLB::Class<Creature, SLB::Instance::NoCopy>("Creature")
            .set("LuaUpdate", &Creature::luaUpdate);*/
}

void exposeWorld()
{
    SLB::Class<World, SLB::Instance::NoCopyNoDestroy>("World")
            .set("AddCreature", &World::addCreature)
            .set("AddBoss", &World::addBoss)
            .set("ShakeCamera", &World::shakeCamera)
            .set("ShakeCameraFor", &World::shakeCameraFor)
            .set("Instance", World::instance);
}


void exposeToLua()
{
    exposeVector();
    exposeSceneNode();
    exposeEntity();
    exposeWorld();
}
