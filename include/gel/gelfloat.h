// gelfloat.h
#ifndef GEL_GELFLOAT_H
#define GEL_GELFLOAT_H

namespace gel
{

struct Float
{
    /**
     * Floating point epsilon.
     * This is twice the standard epsilon value for floating point values.
     */
    static constexpr float GEL_FLT_EPSILON = 11.920929E-8f;

    /**
     * Double precision floating point epsilon.
     * This is twice the standard epsilon value for double precision floating point values.
     */
    static constexpr double GEL_DBL_EPSILON = 2.220446e-16;
};

} // End nspc gel

#endif //GEL_GELFLOAT_H
