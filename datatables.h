#ifndef DATATABLES_H
#define DATATABLES_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <functional>

#include "resources/resourceidentifiers.h"
#include "entities/boss.h"

struct ParticleData
{
    sf::Color   color;
    sf::Time    lifetime;
};

struct EntityData
{
    unsigned int healthpoints;
    unsigned int damages;
    float        speed;
    sf::Time     fireInterval;
};

std::vector<ParticleData>	initializeParticleData();
std::vector<EntityData>     initializeEntityData();
std::vector<std::vector<Phase> > initializeBossPhases(World &world, Boss &boss);


#endif // DATATABLES_H
