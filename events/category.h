#ifndef CATEGORY_H
#define CATEGORY_H

namespace Category
{
    enum Type
    {
        None            = 0,
        SoundEffect     = 1 << 0,
        ParticleSystem  = 1 << 1,
        Player          = 1 << 2,
        Enemy           = 1 << 3,
        Ally            = 1 << 4,
        UILayer         = 1 << 5,
        UI              = 1 << 6,
        Camera          = 1 << 7,
        Object          = 1 << 8
        // ...
        //MixedCategory        = Category1 | Category2,

    };
}

#endif // CATEGORY_H
