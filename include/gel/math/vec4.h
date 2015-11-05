// vec4.h
#ifndef GEL_VEC4_H
#define GEL_VEC4_H
#include <assert.h>
#include <gel/gellib.h>
#include <gel/gelfloat.h>
#include <type_traits>
#include "gelmath.h"

/**
 * This protects against template issues where U could also be one of the undesired types thereby
 * hiding another function.
 */
#define VALIDATE( T, U, R ) \
typename std::enable_if<!std::is_same<TVec4<T>,   U>::value && \
                        !std::is_same<TMat4x4<T>, U>::value, R>::type

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

template <typename T>
class TVec4
{
  public:
    typedef T ValueType;

    union
    {
        struct
        {
            ValueType x, y, z, w;
        };
        struct
        {
            ValueType r, g, b, a;
        };
        struct
        {
            ValueType s, t, p, q;
        };
        struct
        {
            ValueType i, j, k, l;
        };
        struct
        {
            ValueType hue, lum, sat, alpha;
        };
    };

    // IMPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector.
     */
    TVec4();

    /**
     * Constructs this vector as a copy of the other.
     *
     * @param v The vector to copy.
     */
    TVec4( const TVec4<T>& v );

    /**
     * Destructs the vector.
     */
    ~TVec4();

    // EXPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector and initializes its components to v.
     *
     * @param v The component value.
     * @tparam U The component value type.
     */
    template <typename U>
    explicit TVec4( const U& s );

    /**
     * Constructs a new vector.
     *
     * @param s1 The first component value.
     * @param s2 The second component value
     * @param s3 The third component value.
     * @param s4 The fourth component value.
     * @tparam U The first component value type.
     * @tparam V The second component value type.
     * @tparam W The third component value type.
     * @tparam X The fourth component value type.
     */
    template <typename U, typename V, typename W, typename X>
    explicit TVec4( const U& s1, const V& s2, const W& s3, const X& s4 );

    /**
     * Constructs a copy of the vector with the given last component value.
     *
     * @param v The vector to copy.
     * @parma s3 The third component value.
     * @param s4 The fourth component value.
     * @tparam U The vector type.
     * @tparam V The third component type.
     * @tparam W The fourth component type.
     */
    template <typename U, typename V, typename W>
    explicit TVec4( const TVec2 <U>& v, const V& s3, const W& s4 );

    /**
     * Constructs a copy of the vector with the given last component value.
     *
     * @param s1 The first component value.
     * @param v The vector to copy.
     * @param s4 The fourth component value.
     * @parma s The last component value.
     * @tparam U The first component type.
     * @tparam V The vector type.
     * @tparam W The fourth component type.
     */
    template <typename U, typename V, typename W>
    explicit TVec4( const U& s1, const TVec2 <V>& v, const W& s4 );

    /**
     * Constructs a copy of the vector with the given last component value.
     *
     * @parma s1 The first component value.
     * @param s2 The second component value.
     * @param v The vector to copy.
     * @tparam U The first component type.
     * @tparam V The second component type.
     * @tparm W The vector type.
     */
    template <typename U, typename V, typename W>
    explicit TVec4( const U& s1, const V& s2, const TVec2 <W>& v );

    /**
     * Constructs a composition of the two given vectors.
     *
     * @param v1 The first vector to copy.
     * @param v2 The second vector to copy.
     * @tparam U The first vector type.
     * @tparam V The second vector type.
     */
    template <typename U, typename V>
    explicit TVec4( const TVec2 <U> v1, const TVec2 <V>& v2 );

    /**
     * Constructs a copy of the vector with the given first component value.
     *
     * @param s The first component value.
     * @param v The vector to copy.
     * @tparam U The first component type.
     * @tparam V The vector type.
     */
    template <typename U, typename V>
    explicit TVec4( const U& s, const TVec3 <V>& v );

    /**
     * Constructs a copy of the vector with the given first component value.
     *
     * @param v The vector to copy.
     * @param s The fourth component value.
     * @tparam U The vector type.
     * @tparam V The fourth component type.
     */
    template <typename U, typename V>
    explicit TVec4( const TVec3 <U>& v, const V& s );

    /**
     * Constructs a copy of the vector.
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec4( const TVec4<U>& v );

    // SWIZZLE CONSTRUCTORS
    /**
     * Construct from a reference vector.
     *
     * @param r The reference vector.
     */
    TVec4( const TRef4 <T>& r );

    // UNARY OPERATORS
    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     */
    TVec4<T>& operator=( const TVec4<T>& v );

    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     * @tparam U The component value type..
     */
    template <typename U>
    TVec4<T>& operator=( const TVec4<U>& v );

    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar value to add.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator+=( const U& s );

    /**
     * Adds another vector to this.
     *
     * @param v The vector to add.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator+=( const TVec4<U>& v );

    /**
     * Subtracts a scale from the components.
     *
     * @param s The scalar to subtract.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator-=( const U& s );

    /**
     * Subtracts another vector from this.
     *
     * @param v The vector to subtract.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator-=( const TVec4<U>& v );

    /**
     * Multiplies the this by a scalar.
     *
     * @param s The scalar to multiply by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator*=( const U& s );

    /**
     * Multiplies this vector by another.
     *
     * @param v The vector to multiply by.
     * @tparam The component value type.
     */
    template <typename U>
    TVec4<T>& operator*=( const TVec4<U>& v );

    /**
     * Divides this vector by a scalar.
     *
     * @param v The scalar to divide by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator/=( const U& s );

    /**
     * Divides this vector by another.
     *
     * @param v THe vector to divide by.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator/=( const TVec4<U>& v );

    /**
     * Adds one to the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec4<T>& operator++();

    /**
     * Subtracts one from the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec4<T>& operator--();

    /**
     * Adds one to the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec4<T>& operator++( int );

    /**
     * Subtracts one from the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec4<T>& operator--( int );

    /**
     * Multiplies the vector by negative one.
     *
     * @return The negative vector.
     */
    TVec4<T> operator-() const;

    // UNARY BIT OPERATORS
    /**
     * Performs modulo on each of the components.
     *
     * @param s The scalar to perform modulo with.
     * @tparam The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator%=( const U& s );

    /**
     * Performs a component-wise modulus.
     *
     * @param v The vector to perform modulo with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator%=( const TVec4<U>& v );

    /**
     * Performs the bitwise-and operation with each of the components.
     *
     * @param s The scalar to perform and with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator&=( const U& s );

    /**
     * Performs a component-wise bitwise-and operation.
     *
     * @param v The vector to perform and with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator&=( const TVec4<U>& v );

    /**
     * Performs the bitwise-or operation with each of the components.
     *
     * @param s The scalar to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator|=( const U& s );

    /**
     * Performs a component-wise bitwise-or operation.
     *
     * @param s The vector to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator|=( const TVec4<U>& v );

    /**
     * Performs the bitwise-xor operation with each of the components.
     *
     * @param s The scalar to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator^=( const U& s );

    /**
     * Performs a component-wise bitwise-xor operation.
     *
     * @param v The vector to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator^=( const TVec4<U>& v );

    /**
     * Performs the shift-left operation with each of the components.
     *
     * @param s The scalar to perform shift left with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator<<=( const U& s );

    /**
     * Performs a component-wise bitwise-shift left operation.
     *
     * @param The vector to perform shift left with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator<<=( const TVec4<U>& v );

    /**
     * Performs the shift-right operation with each of the components.
     *
     * @param s The scalar to perform shift right with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec4<T>& operator>>=( const U& s );

    /**
     * Performs a component-wise bitwise-shift right operation.
     *
     * @param The vector to perform shift right with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec4<T>& operator>>=( const TVec4<U>& v );

    /**
     * Gets the bitwise inverse vector.
     *
     * @return The bitwise inverse vector.
     */
    TVec4<T> operator~() const;

    // ACCESSOR OPERATORS
    /**
     * Sets the vector component value at the given index.
     */
    ValueType& operator[]( Size index );

    /**
     * Gets the vector component value at the given index.
     */
    const ValueType& operator[]( Size index ) const;
};

template <typename T>
class TRef4
{
  public:
    T& x;
    T& y;
    T& z;
    T& w;

    // CONSTRUCTORS
    /**
     * Constructs reference vector for the reference components.
     * @param s1 The first reference component.
     * @param s2 The second reference component.
     * @param s3 The third reference component.
     * @param s3 The fourth reference component.
     */
    TRef4( T& s1, T& s2, T& s3, T& s4 );

    /**
     * Constructs a new reference vector for an existing reference vector.
     * @param r The reference vector.
     */
    TRef4( TRef4<T>& r );

    /**
     * Constructs a new reference vector for the given vector.
     * @param v The vector to reference.
     */
    TRef4( TVec4<T>& v );

    /**
     * Destructs the reference vector.
     */
    ~TRef4();
};


// ARITHMETIC BINARY OPERATOR DECLARATIONS
/**
 * Adds a scalar value to the components of a vector.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator+( const TVec4<T>& v, const U& s );

/**
 * Adds the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator+( const TVec4<T>& u, const TVec4<T>& v );

/**
 * Subtracts a scalar value from the components of a vector.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator-( const TVec4<T>& v, const U& s );

/**
 * Subtracts the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator-( const TVec4<T>& u, const TVec4<T>& v );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
VALIDATE( T, U, TVec4<T> ) operator*( const TVec4<T>& v, const U& s );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
VALIDATE( U, T, TVec4<U> ) operator*( const T& s, const TVec4<U>& v );

/**
 * Multiplies the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator*( const TVec4<T>& u, const TVec4<T>& v );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator/( const TVec4<T>& v, const U& s );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<U> operator/( const T& s, const TVec4<U>& v );

/**
 * Divides the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator/( const TVec4<T>& u, const TVec4<T>& v );

/**
 * Performs modulus on a vector and a scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator%( const TVec4<T>& v, const U& s );

/**
 * Performs modulus on a vector and a scalar.
 *
 * @param s The scalar.
 * @param v The vector.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<U> operator%( const T& s, const TVec4<U>& v );

/**
 * Performs modulus on the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator%( const TVec4<T>& u, const TVec4<T>& v );

// BINARY BITWISE OPERATOR DECLARATIONS
/**
 * Performs bitwise AND on the components with the scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator&( const TVec4<T>& v, const U& s );

/**
 * Performs bitwise AND on the components from the two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator&( const TVec4<T>& u, const TVec4<T>& v );

/**
 * Performs bitwise OR on the components with the scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator|( const TVec4<T>& v, const U& s );

/**
 * Performs bitwise OR on the components from the two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator|( const TVec4<T>& u, const TVec4<T>& v );


/**
 * Performs bitwise XOR on the components with the scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T, typename U>
TVec4<T> operator^( const TVec4<T>& v, const U& s );

/**
 * Performs bitwise XOR on the components from the two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator^( const TVec4<T>& u, const TVec4<T>& v );

/**
 * Shifts the bits of the components left.
 *
 * @param v The vector.
 * @param shift How many bits to shift.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator<<( const TVec4<T>& v, uint32 shift );

/**
 * Shifts the bits of the components right.
 *
 * @param v The vector.
 * @param shift How many bits to shift.
 * @return The resultant vector.
 */
template <typename T>
TVec4<T> operator>>( const TVec4<T>& u, uint32 shift );

// COMPARISON OPERATOR DECLARATIONS
/**
 * Checks if the components of two vectors are equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator==( const TVec4<T>& u, const TVec4<U>& v );

/**
 * Checks if the components of two vectors are equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator==( const TVec4<T>& u, const TRef4<U>& v );

/**
 * Checks if the components of two vectors are equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator==( const TRef4<T>& u, const TVec4<U>& v );

/**
 * Checks if the components of two vectors are equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator==( const TRef4<T>& u, const TRef4<U>& v );

/**
 * Checks if the components of two vectors are not equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are not equal.
 */
template <typename T, typename U>
bool operator!=( const TVec4<T>& u, const TVec4<U>& v );

/**
 * Checks if the components of two vectors are not equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are not equal.
 */
template <typename T, typename U>
bool operator!=( const TVec4<T>& u, const TRef4<U>& v );

/**
 * Checks if the components of two vectors are not equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are not equal.
 */
template <typename T, typename U>
bool operator!=( const TRef4<T>& u, const TVec4<U>& v );

/**
 * Checks if the components of two vectors are not equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are not equal.
 */
template <typename T, typename U>
bool operator!=( const TRef4<T>& u, const TRef4<U>& v );

// IMPLEMENTATION

// IMPLICIT CONSTRUCTORS
template <typename T>
inline
TVec4<T>::TVec4() : x( 0 ), y( 0 ), z( 0 ), w( 0 )
{
}

template <typename T>
inline
TVec4<T>::TVec4( const TVec4<T>& v ) : x( v.x ), y( v.y ), z( v.z ), w( v.w )
{
}

template <typename T>
inline
TVec4<T>::~TVec4()
{
}

// EXPLICIT CONSTRUCTORS
template <typename T>
template <typename U>
inline
TVec4<T>::TVec4( const U& s ) : x( static_cast<T>( s )),
                                y( static_cast<T>( s )),
                                z( static_cast<T>( s )),
                                w( static_cast<T>( s ))
{
}

template <typename T>
template <typename U, typename V, typename W, typename X>
inline
TVec4<T>::TVec4( const U& s1, const V& s2, const W& s3, const X& s4 )
    : x( static_cast<T>( s1 )), y( static_cast<T>( s2 )),
      z( static_cast<T>( s3 )), w( static_cast<T>( s4 ))
{
}

template <typename T>
template <typename U, typename V, typename W>
inline
TVec4<T>::TVec4( const TVec2 <U>& v, const V& s3, const W& s4 )
    : x( static_cast<T>( v.x )), y( static_cast<T>( v.y )),
      z( static_cast<T>( s3 )), w( static_cast<T>( s4 ))
{
}

template <typename T>
template <typename U, typename V, typename W>
inline
TVec4<T>::TVec4( const U& s1, const TVec2 <V>& v, const W& s4 )
    : x( static_cast<T>( s1 )), y( static_cast<T>( v.x )),
      z( static_cast<T>( v.y )), w( static_cast<T>( s4 ))
{
}

template <typename T>
template <typename U, typename V, typename W>
inline
TVec4<T>::TVec4( const U& s1, const V& s2, const TVec2 <W>& v )
    : x( static_cast<T>( s1 )), y( static_cast<T>( s2 )),
      z( static_cast<T>( v.x )), w( static_cast<T>( v.y ))
{
}

template <typename T>
template <typename U, typename V>
inline
TVec4<T>::TVec4( const TVec2 <U> v1, const TVec2 <V>& v2 )
    : x( static_cast<T>( v1.x )), y( static_cast<T>( v1.y )),
      z( static_cast<T>( v2.x )), w( static_cast<T>( v2.y ))
{
}

template <typename T>
template <typename U, typename V>
inline
TVec4<T>::TVec4( const TVec3 <U>& v, const V& s )
    : x( static_cast<T>( v.x )), y( static_cast<T>( v.y )),
      z( static_cast<T>( v.z )), w( static_cast<T>( s ))
{
}

template <typename T>
template <typename U, typename V>
inline
TVec4<T>::TVec4( const U& s, const TVec3 <V>& v )
    : x( static_cast<T>( s )), y( static_cast<T>( v.x )),
      z( static_cast<T>( v.y )), w( static_cast<T>( v.z ))
{
}

template <typename T>
template <typename U>
inline
TVec4<T>::TVec4( const TVec4<U>& v )
    : x( static_cast<T>( v.x )), y( static_cast<T>( v.y )),
      z( static_cast<T>( v.z )), w( static_cast<T>( v.w ))
{
}

// SWIZZLE CONSTRUCTORS
template <typename T>
inline
TVec4<T>::TVec4( const TRef4<T>& r ) : x( r.x ), y( r.y ), z( r.z ), w( r.w )
{
}

// UNARY OPERATORS
template <typename T>
inline
TVec4<T>& TVec4<T>::operator=( const TVec4<T>& v )
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator=( const TVec4<U>& v )
{
    x = static_cast<T>( v.x );
    y = static_cast<T>( v.y );
    z = static_cast<T>( v.z );
    w = static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator+=( const U& s )
{
    x += static_cast<T>( s );
    y += static_cast<T>( s );
    z += static_cast<T>( s );
    w += static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator+=( const TVec4<U>& v )
{
    x += static_cast<T>( v.x );
    y += static_cast<T>( v.y );
    z += static_cast<T>( v.z );
    w += static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator-=( const U& s )
{
    x -= static_cast<T>( s );
    y -= static_cast<T>( s );
    z -= static_cast<T>( s );
    w -= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator-=( const TVec4<U>& v )
{
    x -= static_cast<T>( v.x );
    y -= static_cast<T>( v.y );
    z -= static_cast<T>( v.z );
    w -= static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator*=( const U& s )
{
    x *= static_cast<T>( s );
    y *= static_cast<T>( s );
    z *= static_cast<T>( s );
    w *= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator*=( const TVec4<U>& v )
{
    x *= static_cast<T>( v.x );
    y *= static_cast<T>( v.y );
    z *= static_cast<T>( v.z );
    w *= static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator/=( const U& s )
{
    assert( s != 0 );
    x /= static_cast<T>( s );
    y /= static_cast<T>( s );
    z /= static_cast<T>( s );
    w /= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator/=( const TVec4<U>& v )
{
    assert( v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0 );
    x /= static_cast<T>( v.x );
    y /= static_cast<T>( v.y );
    z /= static_cast<T>( v.z );
    w /= static_cast<T>( v.w );
    return *this;
}

template <typename T>
inline
TVec4<T>& TVec4<T>::operator++()
{
    ++x;
    ++y;
    ++z;
    ++w;
    return *this;
}

template <typename T>
inline
TVec4<T>& TVec4<T>::operator--()
{
    --x;
    --y;
    --z;
    --w;
    return *this;
}

template <typename T>
inline
TVec4<T>& TVec4<T>::operator++( int )
{
    ++x;
    ++y;
    ++z;
    ++w;
    return *this;
}

template <typename T>
inline
TVec4<T>& TVec4<T>::operator--( int )
{
    --x;
    --y;
    --z;
    --w;
    return *this;
}

template <typename T>
inline
TVec4<T> TVec4<T>::operator-() const
{
    return TVec4<T>( -x, -y, -z, -w );
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator%=( const U& s )
{
    assert( s != 0 );
    x %= static_cast<T>( s );
    y %= static_cast<T>( s );
    z %= static_cast<T>( s );
    w %= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator%=( const TVec4<U>& v )
{
    assert( v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0 );
    x %= static_cast<T>( v.x );
    y %= static_cast<T>( v.y );
    z %= static_cast<T>( v.z );
    w %= static_cast<T>( v.w );
    return *this;
}

// UNARY BITWISE OPERATORS
template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator&=( const U& s )
{
    x &= static_cast<T>( s );
    y &= static_cast<T>( s );
    z &= static_cast<T>( s );
    w &= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator&=( const TVec4<U>& v )
{
    x &= static_cast<T>( v.x );
    y &= static_cast<T>( v.y );
    z &= static_cast<T>( v.z );
    w &= static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator|=( const U& s )
{
    x |= static_cast<T>( s );
    y |= static_cast<T>( s );
    z |= static_cast<T>( s );
    w |= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator|=( const TVec4<U>& v )
{
    x |= static_cast<T>( v.x );
    y |= static_cast<T>( v.y );
    z |= static_cast<T>( v.z );
    w |= static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator^=( const U& s )
{
    x ^= static_cast<T>( s );
    y ^= static_cast<T>( s );
    z ^= static_cast<T>( s );
    w ^= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator^=( const TVec4<U>& v )
{
    x ^= static_cast<T>( v.x );
    y ^= static_cast<T>( v.y );
    z ^= static_cast<T>( v.z );
    w ^= static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator<<=( const U& s )
{
    x <<= static_cast<T>( s );
    y <<= static_cast<T>( s );
    z <<= static_cast<T>( s );
    w <<= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator<<=( const TVec4<U>& v )
{
    x <<= static_cast<T>( v.x );
    y <<= static_cast<T>( v.y );
    z <<= static_cast<T>( v.z );
    w <<= static_cast<T>( v.w );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator>>=( const U& s )
{
    x >>= static_cast<T>( s );
    y >>= static_cast<T>( s );
    z >>= static_cast<T>( s );
    w >>= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec4<T>& TVec4<T>::operator>>=( const TVec4<U>& v )
{
    x >>= static_cast<T>( v.x );
    y >>= static_cast<T>( v.y );
    z >>= static_cast<T>( v.z );
    w >>= static_cast<T>( v.w );
    return *this;
}

template <typename T>
inline
TVec4<T> TVec4<T>::operator~() const
{
    return TVec4<T>( ~x, ~y, ~z, ~w );
}

// ACCESSOR OPERATORS
template <typename T>
inline
const T& TVec4<T>::operator[]( Size index ) const
{
    assert( index >= 0 && index < 4 );
    return ( &x )[index];
}

template <typename T>
inline
T& TVec4<T>::operator[]( Size index )
{
    assert( index >= 0 && index < 4 );
    return ( &x )[index];
}

// BINARY ARITHMETIC OPERATORS
template <typename T>
inline
TVec4<T> operator+( const TVec4<T>& v, const T& s )
{
    return TVec4<T>( v.x + s, v.y + s, v.z + s, v.w + s );
}

template <typename T, typename U>
inline
TVec4<T> operator+( const TVec4<T>& v, const U& s )
{
    return ( v + static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator+( const TVec4<T>& u, const TVec4<T>& v )
{
    return TVec4<T>( u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w );
}

template <typename T>
inline
TVec4<T> operator-( const TVec4<T>& v, const T& s )
{
    return TVec4<T>( v.x - s, v.y - s, v.z - s, v.w - s );
}

template <typename T, typename U>
inline
TVec4<T> operator-( const TVec4<T>& v, const U& s )
{
    return ( v - static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator-( const TVec4<T>& u, const TVec4<T>& v )
{
    return TVec4<T>( u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w );
}

template <typename T>
inline
VALIDATE( T, T, TVec4<T> ) operator*( const TVec4<T>& v, const T& s )
{
    return TVec4<T>( v.x * s, v.y * s, v.z * s, v.w * s );
}

template <typename T, typename U>
inline
VALIDATE( T, U, TVec4<T> ) operator*( const TVec4<T>& v, const U& s )
{
    return ( v * static_cast<T>( s ));
}

template <typename T>
inline
VALIDATE( T, T, TVec4<T> ) operator*( const T& s, const TVec4<T>& v )
{
    return TVec4 < T > ( s * v.x, s * v.y, s * v.z, s * v.w );
}

template <typename T, typename U>
inline
VALIDATE( U, T, TVec4<U> ) operator*( const T& s, const TVec4<U>& v )
{
    return ( static_cast<U>( s ) * v );
}

template <typename T>
inline
TVec4<T> operator*( const TVec4<T>& u, const TVec4<T>& v )
{
    return TVec4 < T > ( u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w );
}

template <typename T>
inline
TVec4<T> operator/( const TVec4<T>& v, const T& s )
{
    assert( s != T( 0 ));
    return TVec4 < T > ( v.x / s, v.y / s, v.z / s, v.w / s );
}

template <typename T, typename U>
inline
TVec4<T> operator/( const TVec4<T>& v, const U& s )
{
    return ( v / static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator/( const T& s, const TVec4<T>& v )
{
    assert( v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0 );
    return TVec4 < T > ( s / v.x, s / v.y, s / v.z, s / v.w );
}

template <typename T, typename U>
inline
TVec4<U> operator/( const T& s, const TVec4<U>& v )
{
    return ( static_cast<U>( s ) / v );
}

template <typename T>
inline
TVec4<T> operator/( const TVec4<T>& u, const TVec4<T>& v )
{
    assert ( v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0 );
    return TVec4 < T > ( u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w );
}

template <typename T>
inline
TVec4<T> operator%( const TVec4<T>& v, const T& s )
{
    assert( s != 0 );
    return TVec4 < T > ( v.x % s, v.y % s, v.z % s, v.w % s );
}

template <typename T, typename U>
inline
TVec4<T> operator%( const TVec4<T>& v, const U& s )
{
    return ( v % static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator%( const T& s, const TVec4<T>& v )
{
    assert( v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0 );
    return TVec4 < T > ( s % v.x, s % v.y, s % v.z, s % v.w );
}

template <typename T, typename U>
inline
TVec4<U> operator%( const T& s, const TVec4<U>& v )
{
    return ( static_cast<U>( s ) % v );
}

template <typename T>
inline
TVec4<T> operator%( const TVec4<T>& u, const TVec4<T>& v )
{
    assert ( v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0 );
    return TVec4 < T > ( u.x % v.x, u.y % v.y, u.z % v.z, u.w % v.w );
}

// BINARY BITWISE OPERATORS
template <typename T>
inline
TVec4<T> operator&( const TVec4<T>& v, const T& s )
{
    return TVec4 < T > ( v.x & s, v.y & s, v.z & s, v.w & s );
}

template <typename T, typename U>
inline
TVec4<T> operator&( const TVec4<T>& v, const U& s )
{
    return ( v & static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator&( const TVec4<T>& u, const TVec4<T>& v )
{
    return TVec4 < T > ( u.x & v.x, u.y & v.y, u.z & v.z, u.w & v.w );
}

template <typename T>
inline
TVec4<T> operator|( const TVec4<T>& v, const T& s )
{
    return TVec4 < T > ( v.x | s, v.y | s, v.z | s, v.w | s );
}

template <typename T, typename U>
inline
TVec4<T> operator|( const TVec4<T>& v, const U& s )
{
    return ( v | static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator|( const TVec4<T>& u, const TVec4<T>& v )
{
    return TVec4 < T > ( u.x | v.x, u.y | v.y, u.z | v.z, u.w | v.w );
}

template <typename T>
inline
TVec4<T> operator^( const TVec4<T>& v, const T& s )
{
    return TVec4 < T > ( v.x ^ s, v.y ^ s, v.z ^ s, v.w ^ s );
}

template <typename T, typename U>
inline
TVec4<T> operator^( const TVec4<T>& v, const U& s )
{
    return ( v ^ static_cast<T>( s ));
}

template <typename T>
inline
TVec4<T> operator^( const TVec4<T>& u, const TVec4<T>& v )
{
    return TVec4 < T > ( u.x ^ v.x, u.y ^ v.y, u.z ^ v.z, u.w ^ v.w );
}

template <typename T>
inline
TVec4<T> operator<<( const TVec4<T>& v, uint32 shift )
{
    return TVec4 < T > ( v.x << shift, v.y << shift, v.z << shift, v.w << shift );
}

template <typename T>
inline
TVec4<T> operator>>( const TVec4<T>& u, uint32 shift )
{
    return TVec4 < T > ( u.x >> shift, u.y >> shift, u.z >> shift, u.w >> shift );
}

template <>
inline
bool operator==( const TVec4<float>& u, const TVec4<float>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <>
inline
bool operator==( const TVec4<double>& u, const TVec4<double>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator==( const TVec4<T>& u, const TVec4<U>& v )
{
    return u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w;
}

template <>
inline
bool operator==( const TVec4<float>& u, const TRef4<float>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <>
inline
bool operator==( const TVec4<double>& u, const TRef4<double>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator==( const TVec4<T>& u, const TRef4<U>& v )
{
    return u.x == v.x || u.y == v.y || u.z == v.z || u.w == v.w;
}

template <>
inline
bool operator==( const TRef4<float>& u, const TVec4<float>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <>
inline
bool operator==( const TRef4<double>& u, const TVec4<double>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator==( const TRef4<T>& u, const TVec4<U>& v )
{
    return u.x == v.x || u.y == v.y || u.z == v.z || u.w == v.w;
}

template <>
inline
bool operator==( const TRef4<float>& u, const TRef4<float>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <>
inline
bool operator==( const TRef4<double>& u, const TRef4<double>& v )
{
    return Math::eq( u.x, v.x ) && Math::eq( u.y, v.y ) &&
        Math::eq( u.z, v.z ) && Math::eq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator==( const TRef4<T>& u, const TRef4<U>& v )
{
    return u.x == v.x || u.y == v.y || u.z == v.z || u.w == v.w;
}

template <>
inline
bool operator!=( const TVec4<float>& u, const TVec4<float>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <>
inline
bool operator!=( const TVec4<double>& u, const TVec4<double>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator!=( const TVec4<T>& u, const TVec4<U>& v )
{
    return u.x != v.x || u.y != v.y || u.z != v.z || u.w != v.w;
}

template <>
inline
bool operator!=( const TVec4<float>& u, const TRef4<float>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <>
inline
bool operator!=( const TVec4<double>& u, const TRef4<double>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator!=( const TVec4<T>& u, const TRef4<U>& v )
{
    return u.x != v.x || u.y != v.y || u.z != v.z || u.w != v.w;
}


template <>
inline
bool operator!=( const TRef4<float>& u, const TVec4<float>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <>
inline
bool operator!=( const TRef4<double>& u, const TVec4<double>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator!=( const TRef4<T>& u, const TVec4<U>& v )
{
    return u.x != v.x || u.y != v.y || u.z != v.z || u.w != v.w;
}

template <>
inline
bool operator!=( const TRef4<float>& u, const TRef4<float>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <>
inline
bool operator!=( const TRef4<double>& u, const TRef4<double>& v )
{
    return Math::neq( u.x, v.x ) && Math::neq( u.y, v.y ) &&
        Math::neq( u.z, v.z ) && Math::neq( u.w, v.w );
}

template <typename T, typename U>
inline
bool operator!=( const TRef4<T>& u, const TRef4<U>& v )
{
    return u.x != v.x || u.y != v.y || u.z != v.z || u.w != v.w;
}

// 4D REFERENCE VECTOR

// CONSTRUCTORS
template <typename T>
inline
TRef4<T>::TRef4( T& s1, T& s2, T& s3, T& s4 ) : x( s1 ), y( s2 ), z( s3 ),
                                                w( s4 )
{
}

template <typename T>
inline
TRef4<T>::TRef4( TRef4<T>& r ) : x( r.x ), y( r.y ), z( r.z ), w( r.w )
{
}

template <typename T>
inline
TRef4<T>::TRef4( TVec4<T>& v ) : x( v.x ), y( v.y ), z( v.z ), w( v.w )
{
}

template <typename T>
inline
TRef4<T>::~TRef4()
{
}

} // End nspc math

} // End nspc gel

#undef VALIDATE

#endif //GEL_VEC4_H
