// mat.h
#ifndef GEL_MAT_H
#define GEL_MAT_H
#include <gel/math/mat2x2.h>
#include <gel/math/mat3x3.h>
#include <gel/math/mat4x4.h>
#include <gel/math/mat_math.h>
#include <gel/math/vec.h>

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

template <typename T>
class TMat2x2;

template <typename T>
class TMat3x3;

template <typename T>
class TMat4x4;

/**
 * Defines a default 2x2 matrix.
 */
typedef TMat2x2<float> Mat2;

/**
 * Defines a double 2x2 matrix.
 */
typedef TMat2x2<double> DMat2;

/**
 * Defines an integer 2x2 matrix.
 */
typedef TMat2x2<int32> IMat2;

/**
 * Defines a long integer 2x2 matrix.
 */
typedef TMat2x2<int64> LMat2;

/**
 * Defines a default 3x3 matrix.
 */
typedef TMat3x3<float> Mat3;

/**
 * Defines a double 3x3 matrix.
 */
typedef TMat3x3<double> DMat3;

/**
 * Defines an integer 3x3 matrix.
 */
typedef TMat3x3<int32> IMat3;

/**
 * Defines an integer 3x3 matrix.
 */
typedef TMat3x3<int64> LMat3;

/**
 * Defines a default 4x4 matrix.
 */
typedef TMat4x4<float> Mat4;

/**
 * Defines a double 4x4 matrix.
 */
typedef TMat4x4<double> DMat4;

/**
 * Defines an integer 4x4 matrix.
 */
typedef TMat4x4<int32> IMat4;

/**
 * Defines an integer 4x4 matrix.
 */
typedef TMat4x4<int64> LMat4;

} // End nspc math

} // End nspc gel

#endif //GEL_MAT_H
