#pragma once

namespace Data
{
    struct SEntityCategory
    {
        enum ECategories
        {
            Character,
            Ground,
            Wall,
            Obstacle,
            Prop,
            Enemy,
            Bullet,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}