// vec.h
#ifndef GEL_VEC_H
#define GEL_VEC_H
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace gel
{

namespace math
{

template <typename T>
class TRef2;

template <typename T>
class TRef3;

template <typename T>
class TRef4;

template <typename T>
class TVec2;

template <typename T>
class TVec3;

template <typename T>
class TVec4;

/**
 * Defines a default 2D vector.
 */
typedef TVec2<float> Vec2;

/**
 * Defines a double 2D vector.
 */
typedef TVec2<double> DVec2;

/**
 * Defines a default 3D vector.
 */
typedef TVec3<float> Vec3;

/**
 * Defines a double 3D vector.
 */
typedef TVec3<double> DVec3;

/**
 * Defines a default 4D vector.
 */
typedef TVec4<float> Vec4;

/**
 * Defines a double 4D vector.
 */
typedef TVec4<double> DVec4;

} // End nspc math

} // End nspc gel

#endif
