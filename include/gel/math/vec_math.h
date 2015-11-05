// vec_math.h
#ifndef GEL_VEC_MATH_H
#define GEL_VEC_MATH_H

#include <gel/math/gelmath.h>

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

struct Vec
{
    /**
     * Calculates the magnitude of the vector.
     *
     * @param v The vector.
     * @return The length.
     */
    template <typename T>
    static T length( const TVec2<T>& v );

    /**
     * Calculates the magnitude of the vector.
     *
     * @param v The vector.
     * @return The length.
     */
    template <typename T>
    static T length( const TVec3<T>& v );

    /**
     * Calculates the magnitude of the vector.
     *
     * @param v The vector.
     * @return The length.
     */
    template <typename T>
    static T length( const TVec4<T>& v );

    /**
     * Normalizes the vector.
     * 
     * @param v The vector.
     * @return The unit vector.
     */
    template <typename T>
    static TVec2<T> normalize( const TVec2<T>& v );

    /**
     * Normalizes the vector.
     *
     * @param v The vector.
     * @return The unit vector.
     */
    template <typename T>
    static TVec3<T> normalize( const TVec3<T>& v );

    /**
     * Normalizes the vector.
     *
     * @param v The vector.
     * @return The unit vector.
     */
    template <typename T>
    static TVec4<T> normalize( const TVec4<T>& v );

    /**
     * Calculates the scalar product of the two vectors.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return The scalar product.
     */
    template <typename T>
    static T dot( const TVec2<T>& a, const TVec2<T>& b );

    /**
     * Calculates the scalar product of the two vectors.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return The scalar product.
     */
    template <typename T>
    static T dot( const TVec3<T>& a, const TVec3<T>& b );

    /**
     * Calculates the scalar product of the two vectors.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return The scalar product.
     */
    template <typename T>
    static T dot( const TVec4<T>& a, const TVec4<T>& b );

    /**
     * Calculates the cross product of two 3D vectors.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return The cross product.
     */
    template <typename T>
    static TVec3<T> cross( const TVec3<T>& a, const TVec3<T>& b );

    /**
     * Projects vector a onto vector b.
     *
     * @param a The vector to project.
     * @param b The vector to project onto.
     * @return The projection.
     */
    template <typename T>
    static TVec2<T> project( const TVec2<T>& a, const TVec2<T>& b );

    /**
     * Projects vector a onto vector b.
     *
     * @param a The vector to project.
     * @param b The vector to project onto.
     * @return The projection.
     */
    template <typename T>
    static TVec3<T> project( const TVec3<T>& a, const TVec3<T>& b );


    /**
     * Projects vector a onto vector b.
     *
     * @param a The vector to project.
     * @param b The vector to project onto.
     * @return The projection.
     */
    template <typename T>
    static TVec4<T> project( const TVec4<T>& a, const TVec4<T>& b );
};

template <typename T>
inline
T Vec::length( const TVec2<T>& v )
{
    return Math::sqrt( Math::pow( v.x, 2 ) + Math::pow( v.y, 2 ) );
}

template <typename T>
inline
T Vec::length( const TVec3<T>& v )
{
    return Math::sqrt( Math::pow( v.x, 2 ) + Math::pow( v.y, 2 ) + Math::pow( v.z, 2 ) );
}

template <typename T>
inline
T Vec::length( const TVec4<T>& v )
{
    return Math::sqrt( Math::pow( v.x, 2 ) + Math::pow( v.y, 2 ) + Math::pow( v.z, 2 ) +
        Math::pow( v.w, 2 ) );
}

template <typename T>
inline
TVec2<T> Vec::normalize( const TVec2<T>& v )
{
    return v / length( v );
}

template <typename T>
inline
TVec3<T> Vec::normalize( const TVec3<T>& v )
{
    return v / length( v );
}

template <typename T>
inline
TVec4<T> Vec::normalize( const TVec4<T>& v )
{
    return v / length( v );
}

template <typename T>
inline
T Vec::dot( const TVec2<T>& a, const TVec2<T>& b )
{
    return a.x * b.x + a.y * b.y;
}

template <typename T>
inline
T Vec::dot( const TVec3<T>& a, const TVec3<T>& b )
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T>
inline
T Vec::dot( const TVec4<T>& a, const TVec4<T>& b )
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

template <typename T>
inline
TVec3<T> Vec::cross( const TVec3<T>& a, const TVec3<T>& b )
{

}

template <typename T>
inline
TVec2<T> Vec::project( const TVec2<T>& a, const TVec2<T>& b )
{

}

template <typename T>
inline
TVec3<T> Vec::project( const TVec3<T>& a, const TVec3<T>& b )
{

}

template <typename T>
inline
TVec4<T> Vec::project( const TVec4<T>& a, const TVec4<T>& b )
{

}

} // End nspc math

} // End nspc gel

#endif //GEL_VEC_MATH_H
