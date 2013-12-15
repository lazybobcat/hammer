#ifndef COMBATTEXTNODE_H
#define COMBATTEXTNODE_H

#include <string>

#include "scenenode.h"
#include "../resources/resourceidentifiers.h"
#include "../resources/resourceholder.h"

class CombatTextNode : public SceneNode
{
public:
    CombatTextNode(const std::string& text, const FontHolder& fonts);

    void            setText(const std::string& text);

private:
    virtual void    updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Text        mText;
    unsigned int    mSize;
    sf::Time        mElapsedTime;
    sf::Time        mTotalElapsedTime;
};

#endif // COMBATTEXTNODE_H
