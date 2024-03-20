#pragma once

namespace Core 
{
    bool FloatCompare(float a, float b);
}

namespace Core
{
    inline bool FloatCompare(float a, float b)
    {
        return fabs(a - b) < 0.0001f;
    }
}