#ifndef WORLD_H
#define WORLD_H

#include <array>
#include <set>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "entities/textnode.h"
#include "resources/resourceholder.h"
#include "resources/resourceidentifiers.h"
#include "resources/scriptplayer.h"
#include "resources/musicplayer.h"
#include "events/category.h"
#include "events/commandqueue.h"
#include "entities/spritenode.h"
#include "entities/playerentity.h"
#include "entities/creature.h"
#include "entities/particlenode.h"
#include "entities/uihealthpoints.h"
#include "entities/cameranode.h"
#include "controllers/playercontroller.h"
#include "controllers/aicontroller.h"
#include "controllers/bosscontroller.h"
#include "wave.h"

class Boss;

class World : public sf::NonCopyable
{
public:
    friend class Wave;

public:
    World(sf::RenderWindow& window, TextureHolder &textures, FontHolder &fonts, SoundPlayer& sounds, MusicPlayer& music, ScriptPlayer& scripts, PlayerController& player);

    static World*   instance();

    void        update(sf::Time dt);
    void        draw();

    CommandQueue&   getCommandQueue();

    void        addCreature(int type, float posx);
    void        addBoss(int type, float posx);
    void        shakeCamera();
    void        shakeCameraFor(float sec);

    PlayerEntity* player();
    bool        hasPlayerAlive() const;

    void        retry();

private:
    void        loadTextures();
    void        buildScene();
    void        handleCollisions();
    void        destroyEntitiesOutsideView();

    void        nextWave();
    std::size_t creatureCount() const;

private:
    enum Layer
    {
        Background,
        Foreground,
        Player,
        UI,
        LayerCount
    };

private:
    static World*                       mInstance;

    sf::RenderWindow&                   mWindow;
    //sf::RenderTexture                   mSceneTexture; // Use RenderTexture instead of window to drawto apply some shaders or pre-redering...
    sf::View                            mWorldView;
    TextureHolder&                      mTextures;
    FontHolder&                         mFonts;
    SoundPlayer&                        mSounds;
    MusicPlayer&                        mMusic;
    ScriptPlayer&                       mScripts;

    SceneNode                           mSceneGraph;
    std::array<SceneNode*,LayerCount>   mSceneLayers;
    CommandQueue                        mCommandQueue;

    // Player
    PlayerEntity*                       mPlayer;

    // Enemies
    std::set<Creature*>                 mCreatures;
    std::set<Creature*>                 mWaitingCreations;

    // Controllers
    Wave                                mWave;
    sf::Time                            mTimer;
    AIController                        mAIController;
    BossController                      mBossController;
    unsigned int                        mPoints;
    TextNode*                           mPointsText;
};

#endif // WORLD_H
