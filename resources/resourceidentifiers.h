#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

// Forward declarations
namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class Music;
    class SoundBuffer;
}

template <typename Resource, typename Identifier>
class ResourceHolder;



// Textures
namespace Textures
{
    enum ID
    {
        Particle,
        Title,
        Background,
        Ground,
        PlayerStanding,
        PlayerWalkingLeft,
        PlayerWalkingRight,
        PlayerAttackingLeft,
        PlayerAttackingRight,
        RabbitLeft,
        RabbitRight,
        TentacleLeft,
        TentacleRight,
        CrawlerLeft,
        CrawlerRight,
        Knocked,
        Objects,
        Pvbar,
        Help,
        Pausemenu,
        Gameovermenu,
        Intro
    };
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;


// Fonts
namespace Fonts
{
    enum ID
    {
        Main,
        Grinched
    };
}

typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;


// Shaders
namespace Shaders
{
    enum ID
    {

    };
}
typedef ResourceHolder<sf::Shader, Shaders::ID> ShaderHolder;


// Musics
namespace Musics
{
    enum ID
    {
        MainTheme,
        MainMenu
    };
}


// Sounds
namespace Sounds
{
    enum ID
    {
        BossStep,
        BossCrush,
        EnemyDie,
        HammerStrike,
        PlayerHit,
        PlayerHeal
    };
}
typedef ResourceHolder<sf::SoundBuffer, Sounds::ID> SoundHolder;


// Scripts
namespace Scripts
{
    enum ID
    {
        Loading,
        Level1 = 1,
        Level2,
        Level3,
        Level4,
        Level5,
        Level6,
        Level7,
        Level8,
        Level9,
        Level10,
        Level11,
        Level12,
        Level13,
        Level14,
        Level15,
        LevelInfinite
    };
}



#endif // RESOURCE_IDENTIFIERS_H
