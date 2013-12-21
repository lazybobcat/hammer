#include "world.h"
#include "utils.h"
#include "entities/textnode.h"
#include "entities/boss.h"
#include <algorithm>

#include <iostream>

////////////////////////////////////////////////////

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
    unsigned int category1 = colliders.first->getCategory();
    unsigned int category2 = colliders.second->getCategory();

    if(type1 & category1 && type2 & category2)
    {
        return true;
    }
    else if(type1 & category2 && type2 & category1)
    {
        std::swap(colliders.first, colliders.second);
        return true;
    }

    return false;
}

////////////////////////////////////////////////////

World* World::mInstance = nullptr;

World* World::instance()
{
    return World::mInstance;
}

////////////////////////////////////////////////////

World::World(sf::RenderWindow &window, TextureHolder &textures, FontHolder &fonts, SoundPlayer &sounds, MusicPlayer &music, ScriptPlayer &scripts, PlayerController& player) :
    mWindow(window),
    mWorldView(window.getDefaultView()),
    mTextures(textures),
    mFonts(fonts),
    mSounds(sounds),
    mMusic(music),
    mScripts(scripts),
    mSceneGraph(),
    mSceneLayers(),
    mPlayer(nullptr),
    mWave(*this, 1),
    mTimer(sf::Time::Zero),
    mPoints(0),
    mTmpPoints(0),
    mPointsText(nullptr)
{
    //mSceneTexture.create(mWindow.getSize().x, mWindow.getSize().y);

    //
    World::mInstance = this;
    //

    loadTextures();
    buildScene();

    // Other things here, like setting the view center on the player, scores, etc...
    std::unique_ptr<SoundNode> sound(new SoundNode(sounds));
    mSceneGraph.attachChild(std::move(sound));

    std::unique_ptr<CameraNode> camera(new CameraNode(mWorldView));
    mSceneGraph.attachChild(std::move(camera));
}


void World::loadTextures()
{
    //mTextures.load(Textures::MyTextureIDHere, "assets/textures/whatever.png");
}

void World::retry()
{
    mPlayer->heal(mPlayer->getMaxHealthpoints());
    mCreatures.clear();
    mWaitingCreations.clear();
    while(!mCommandQueue.isEmpty())
        mCommandQueue.pop();

    mSceneGraph.detachAllChildren();

    mTmpPoints = 0;

    buildScene();

    // Other things here, like setting the view center on the player, scores, etc...
    std::unique_ptr<SoundNode> sound(new SoundNode(mSounds));
    mSceneGraph.attachChild(std::move(sound));

    std::unique_ptr<CameraNode> camera(new CameraNode(mWorldView));
    mSceneGraph.attachChild(std::move(camera));
}

void World::buildScene()
{
    // Initialize layers
    for(std::size_t i = 0; i < LayerCount; ++i)
    {
        Category::Type cat = ((i == UI) ? Category::UILayer :  Category::None);
        SceneNode::Ptr layer(new SceneNode(cat));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Background
    std::unique_ptr<SpriteNode> bg(new SpriteNode(mTextures.get(Textures::Background)));
    mSceneLayers[Background]->attachChild(std::move(bg));

    std::unique_ptr<SpriteNode> ground(new SpriteNode(mTextures.get(Textures::Ground)));
    ground->setPosition(sf::Vector2f(0,mWindow.getView().getSize().y-mTextures.get(Textures::Ground).getSize().y));
    mSceneLayers[Background]->attachChild(std::move(ground));

    // Add particle node to the scene
    std::unique_ptr<ParticleNode> pnode(new ParticleNode(Particle::Default, mTextures));
    pnode->addAffector([](Particle &p, sf::Time dt) {p.position.y+=30.f*dt.asSeconds();});
    mSceneLayers[Foreground]->attachChild(std::move(pnode));

    // Player
    std::unique_ptr<PlayerEntity> player(new PlayerEntity(mTextures));
    player->setPosition(sf::Vector2f(mWindow.getSize().x / 2.f, mWindow.getSize().y - 105));
    mPlayer = player.get();
    mSceneLayers[Player]->attachChild(std::move(player));

    // UI
    std::unique_ptr<Uihealthpoints> php(new Uihealthpoints(mTextures, *mPlayer));
    php->setPosition(sf::Vector2f(110.f, 10.f));
    mSceneLayers[UI]->attachChild(std::move(php));

    std::unique_ptr<TextNode> score(new TextNode("Score: " + toString(mPoints+mTmpPoints), mFonts));
    score->setPosition(1024-90, (int)mWindow.getSize().y - 40);
    score->setScale(sf::Vector2f(1.5f, 1.5f));
    mPointsText = score.get();
    mSceneLayers[UI]->attachChild(std::move(score));

    if(mWave.number() < 2) {
        mPointsText->hide();
    }

    // Launch lua scripts
    mScripts.play(Scripts::Loading);

    mWave.launch();
}

void World::addCreature(int type, float posx)
{
    std::cout << "Create creature type " << type << " at x=" << posx << std::endl;
    Creature* c;
    Entity::Direction dir;
    if(posx > 0)
    {
        posx = mWindow.getSize().x + posx;
        dir = Entity::Left;
    }
    else
    {
        dir = Entity::Right;
    }

    switch(type)
    {
        case 1:
            c=new Creature(mTextures, mFonts, Entity::Rabbit, mAIController);
            break;

        case 2:
            c=new Creature(mTextures, mFonts, Entity::Tentacle, mAIController);
            break;

        case 3:
            c=new Creature(mTextures, mFonts, Entity::Crawler, mAIController);
            break;


        default:return;
    }

    c->setPosition(sf::Vector2f(posx, mWindow.getSize().y - 105));
    c->move(dir);
    c->setAcceleration(1.f + 0.01*mWave.number());
    mWaitingCreations.insert(c);
}

void World::addBoss(int type, float posx)
{
    std::cout << "Create boss type " << type << " at x=" << posx << std::endl;
    std::unique_ptr<Boss> c;
    Entity::Direction dir;
    if(posx > 0)
    {
        posx = mWindow.getSize().x + posx;
        dir = Entity::Left;
    }
    else
    {
        dir = Entity::Right;
    }

    switch(type)
    {
        case 1:
            c.reset(new Boss(*this, mTextures, mFonts, Entity::Boss1, mBossController));
            break;

        case 2:
            c.reset(new Boss(*this, mTextures, mFonts, Entity::Boss2, mBossController));
            break;

        case 3:
            c.reset(new Boss(*this, mTextures, mFonts, Entity::Boss3, mBossController));
            break;


        default:return;
    }

    c->setPosition(sf::Vector2f(posx, mWindow.getSize().y - 105));
    c->move(dir);
    mCreatures.insert(c.get());
    mSceneLayers[Foreground]->attachChild(std::move(c));
}

void World::nextWave()
{
    mWave.next();
    mWave.launch();

    mMusic.setPitch(1.f + 0.01*mWave.number());

    // Scores
    mPoints += 50;
    mPoints += mTmpPoints;
    mTmpPoints = 0;

    if(mWave.number() >= 2 && mPointsText)
    {
        // UI
        mPointsText->show();
    }

    // Screenshot
    sf::Image img = mWindow.capture();
    img.saveToFile("screenshots/wave" + toString(mWave.number()-1) + ".jpg");
}

void World::update(sf::Time dt)
{
    // Game logic here
    mTimer += dt;

    // Creations
    for(auto c : mWaitingCreations)
    {
        mCreatures.insert(c);
        std::unique_ptr<Creature> cp(c);
        mSceneLayers[Foreground]->attachChild(std::move(cp));
    }
    mWaitingCreations.clear();

    if(mPlayer)
    {
        // Player replacement
        if((mPlayer->getPosition().x-32.f) < 0)
        {
            mPlayer->setPosition(sf::Vector2f(32.f, mPlayer->getPosition().y));
        }
        else if((mPlayer->getPosition().x+32.f) > mWindow.getSize().x)
        {
            mPlayer->setPosition(sf::Vector2f(mWindow.getSize().x-32.f, mPlayer->getPosition().y));
        }
    }

    // Forward commands to scene
    while(!mCommandQueue.isEmpty())
    {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }

    // Handle collisions
    handleCollisions();

    // End game conditions
    if(mWave.isFinished())
    {
        std::cout << "Wave " << mWave.number() << " finished ! Gratz" << std::endl;
        nextWave();
    }

    if(mPlayer->isDestroyed())
    {
        return;
    }

    // Score
    if(mPointsText)
    {
        mPointsText->setText("Score: " + toString(mPoints+mTmpPoints));
    }

    // Remove useless entities
    destroyEntitiesOutsideView();
    mSceneGraph.removeWrecks();


    // Set the listener position
    mSounds.setListenerPosition(mPlayer->getWorldPosition());
    mSounds.removeStoppedSounds();

    mSceneGraph.update(dt, mCommandQueue);
}

void World::handleCollisions()
{
    std::set<SceneNode::Pair> collisionPairs;
    mSceneGraph.checkSceneCollision(mSceneGraph, collisionPairs);

    for(SceneNode::Pair pair : collisionPairs)
    {
        if (matchesCategories(pair, Category::Player, Category::Enemy))
        {
            auto& player = static_cast<PlayerEntity&>(*pair.first);
            auto& enemy = static_cast<Creature&>(*pair.second);

            // Si le joueur attaque, on blesse l'adversaire, sinon on regarde la distance et on blesse le joueur s'il y a lieu
            if(player.isAttacking() && ((player.getDirection() == Entity::Left && (player.getPosition().x - enemy.getPosition().x) > 0) || (player.getDirection() == Entity::Right && (player.getPosition().x - enemy.getPosition().x) < 0)))
            {
                enemy.damage(player.getDamages());
                if(enemy.isDestroyed())
                {
                    // SCores
                    mTmpPoints += enemy.getMaxHealthpoints();
                    std::cout << "Enemy killed !" << std::endl;

                    mCreatures.erase(&enemy);
                    mSounds.play(Sounds::EnemyDie, player.getWorldPosition());
                }
            }
            else
            {
                if(fabs(player.getPosition().x - enemy.getPosition().x) <= 32.f && !player.isKnocked())
                {
                    if(player.canBeHurt())
                    {
                        mSounds.play(Sounds::PlayerHit, player.getWorldPosition());
                    }
                    player.damage(enemy.getDamages());
                }
            }
        }
        else if (matchesCategories(pair, Category::Player, Category::Ally))
        {
            auto& player = static_cast<PlayerEntity&>(*pair.first);
            auto& ally = static_cast<Creature&>(*pair.second);

            // Si le joueur attaque, le lapin se fait smasher ! Sinon le joueur est soigné
            if(player.isAttacking() && ((player.getDirection() == Entity::Left && (player.getPosition().x - ally.getPosition().x) > 0) || (player.getDirection() == Entity::Right && (player.getPosition().x - ally.getPosition().x) < 0)))
            {
                ally.damage(player.getDamages());
                if(ally.isDestroyed())
                {
                    mCreatures.erase(&ally);
                    mSounds.play(Sounds::EnemyDie, player.getWorldPosition());
                }
            }
            else
            {
                if(fabs(player.getPosition().x - ally.getPosition().x) <= 32.f)
                {
                    player.heal(ally.getDamages());
                    ally.sacrifice();
                    mCreatures.erase(&ally);
                    mSounds.play(Sounds::PlayerHeal, player.getWorldPosition());
                }
            }
        }
    }
}

void World::destroyEntitiesOutsideView()
{
    Command command;
    command.category = Category::Ally | Category::Enemy;
    command.action = derivedAction<Entity>([this] (Entity& e, sf::Time) {
            if(!e.isDestroyed() && ((e.getDirection() == Entity::Left && e.getPosition().x < (-100.f - e.getBoundingRect().width/2)) || (e.getDirection() == Entity::Right && e.getPosition().x > (mWindow.getSize().x+100.f + e.getBoundingRect().width/2))))
        {
            e.sacrifice();
            mCreatures.erase(static_cast<Creature*>(&e));
        }
    });
    mCommandQueue.push(command);
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}

void World::shakeCamera()
{
    Command command;
    command.category = Category::Camera;
    command.action = derivedAction<CameraNode>([&](CameraNode& c, sf::Time) {
        c.shake(sf::seconds(0.6f));
    });
    mCommandQueue.push(command);
}

void World::shakeCameraFor(float time)
{
    Command command;
    command.category = Category::Camera;
    command.action = derivedAction<CameraNode>([=](CameraNode& c, sf::Time) {
        c.shake(sf::seconds(time));
    });
    mCommandQueue.push(command);
}

PlayerEntity* World::player() { return mPlayer; }
bool World::hasPlayerAlive() const { return !mPlayer->isDestroyed(); }

std::size_t World::creatureCount() const { return mCreatures.size(); }
