// mat4x4.h
#ifndef GEL_MAT4X4_H
#define GEL_MAT4X4_H

#include <assert.h>
#include <gel/gellib.h>
#include <gel/math/vec4.h>
#include <gel/math/mat_math.h>
#include <iostream>

/**
 * This protects against template issues where U could also be one of the undesired types thereby
 * hiding another function.
 */
#define VALIDATE( T, U, R ) \
typename std::enable_if<!std::is_same<typename TMat4x4<T>::Column, U>::value && \
                        !std::is_same<typename TMat4x4<T>::Row,    U>::value, R>::type

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
class TMat4x4
{
  public:
    // TYPES
    typedef T Value;
    typedef TVec4<T> Column;
    typedef TVec4<T> Row;

  private:
    /**
     * The columns.
     */
    Column _value[4];

  public:
    // CONSTANTS
    static const int COLUMNS = 4;
    static const int ROWS = 4;

    static const TMat4x4<T> IDENTITY;
    static const TMat4x4<T> ZERO;

    // CONSTRUCTORS
    /**
     * Constructs a new identity matrix.
     */
    TMat4x4();

    /**
     * Constructs a copy of the given matrix.
     *
     * @param m The matrix to copy.
     */
    TMat4x4( const TMat4x4<T>& m );

    // CONVERSION CONSTRUCTORS
    /**
     * Constructs a new diagonal matrix.
     *
     * @param s The diagonal value.
     */
    template <typename U>
    explicit TMat4x4( const U& s );

    /**
     * Constructs a new matrix.
     *
     * @param x1 The C1R1 value
     * @param x2 The C2R1 value.
     * @param x3 The C3R1 value.
     * @param y1 The C1R2 value.
     * @param y2 The C2R2 value.
     * @param y3 The C3R2 value.
     * @param z1 The C1R3 value.
     * @param z2 The C2R3 value.
     * @param z3 The C3R3 value.
     */
    template <typename X1, typename X2, typename X3, typename X4,
              typename Y1, typename Y2, typename Y3, typename Y4,
              typename Z1, typename Z2, typename Z3, typename Z4,
              typename W1, typename W2, typename W3, typename W4>
    explicit TMat4x4( const X1& x1, const X2& x2, const X3& x3, const X4& x4,
                      const Y1& y1, const Y2& y2, const Y3& y3, const Y4& y4,
                      const Z1& z1, const Z2& z2, const Z3& z3, const Z4& z4,
                      const W1& w1, const W2& w2, const W3& w3, const W4& w4 );

    /**
     * Constructs a new matrix.
     *
     * @param c1 The first column.
     * @param c2 The second column.
     * @param c3 The third column.
     * @param c4 The fourth column.
     */
    template <typename I, typename J, typename K, typename L>
    explicit TMat4x4( const TVec4<I>& c1, const TVec4<J>& c2,
                      const TVec4<K>& c3, const TVec4<L>& c4 );

    /**
     * Constructs a 4x4 copy of the give matrix.
     *
     * @param m The matrix to copy.
     */
    template <typename U>
    explicit TMat4x4( const TMat2x2<U>& m );

    /**
     * Constructs a 4x4 copy of the give matrix.
     *
     * @param m The matrix to copy.
     */
    template <typename U>
    explicit TMat4x4( const TMat3x3<U>& m );

    /**
     * Constructs a 4x4 copy of the give matrix.
     *
     * @param m The matrix to copy.
     */
    template <typename U>
    explicit TMat4x4( const TMat4x4<U>& m );

    /**
     * Destructs a matrix.
     */
    ~TMat4x4();

    // ACCESSOR FUNCTIONS
    /**
     * Gets the ith column in the matrix.
     *
     * @param i The index.
     * @return The column.
     */
    const Column& operator[]( Size i ) const;

    /**
     * Gets the ith column in the matrix.
     *
     * @param i The index.
     * @return The column.
     */
    Column& operator[]( Size i );

    // ASSIGNMENT OPERATORS
    /**
     * Makes this a copy of the other matrix.
     *
     * @param m The matrix to copy.
     * @return The copy.
     */
    template <typename U>
    TMat4x4<T>& operator=( const TMat4x4<U>& m );

    // ARITHMETIC UNARY OPERATORS
    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar to add.
     */
    template <typename U>
    TMat4x4<T>& operator+=( const U& s );

    /**
     * Adds another matrix to this.
     *
     * @param The matrix to add.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator+=( const TMat4x4<U>& m );

    /**
     * Subtracts a scalar value from the components.
     *
     * @param s The scalar to subtract.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator-=( const U& s );

    /**
     * Subtracts another matrix from this.
     *
     * @param m The matrix to subtract.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator-=( const TMat4x4<U>& m );

    /**
     * Multiplies the components by a scalar value.
     *
     * @param s The scalar to multiply by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator*=( const U& s );

    /**
     * Multiplies this with another matrix.
     *
     * @param m The matrix to multiply by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator*=( const TMat4x4<U>& m );

    /**
     * Divides the components by a scalar value.
     *
     * @param s The scalar to divide by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator/=( const U& s );

    /**
     * Divides this by another matrix.
     *
     * @param m The matrix to divide by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator/=( const TMat4x4<U>& m );

    /**
     * Gets the modulus of the components with a scalar value.
     *
     * @param s The scalar to modulo with.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator%=( const U& s );

    /**
     * Performs modulo with the components of the other matrix.
     *
     * @param m The matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator%=( const TMat4x4<U>& m );

    /**
     * Pre-increments the components..
     *
     * @return The resulting matrix.
     */
    TMat4x4<T>& operator++();

    /**
     * Pre-decrements the components.
     *
     * @return The resulting matrix.
     */
    TMat4x4<T>& operator--();

    /**
     * Post-increments the components.
     *
     * @return The resulting matrix.
     */
    TMat4x4<T>& operator++( int );

    /**
     * Post-increments the components.
     *
     * @return The resulting matrix.
     */
    TMat4x4<T>& operator--( int );

    /**
     * Gets the negative matrix.
     *
     * @return The negative matrix.
     */
    TMat4x4<T> operator-() const;

    // BITWISE UNARY OPERATORS
    /**
     * Performs bitwise AND with the components and a scalar.
     *
     * @param s The scalar.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator&=( const U& s );

    /**
     * Performs a component-wise AND operation.
     *
     * @param m The other matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator&=( const TMat4x4<U>& m );

    /**
     * Performs bitwise OR with the components and a scalar.
     *
     * @param s The scalar.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator|=( const U& s );

    /**
     * Performs a component-wise OR operation.
     *
     * @param m The other matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator|=( const TMat4x4<U>& s );

    /**
     * Performs bitwise XOR with the components and a scalar.
     *
     * @param s The scalar.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator^=( const U& s );

    /**
     * Performs a component-wise XOR operation.
     *
     * @param m The other matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat4x4<T>& operator^=( const TMat4x4<U>& s );

    /**
     * Shifts left each component by the specified number of bits.
     *
     * @param shift The number of bits to shift.
     * @return The resulting matrix.
     */
    TMat4x4<T>& operator<<=( uint32 shift );

    /**
     * Shifts right each component by the specified number of bits.
     *
     * @param shift The number of bits to shift.
     * @return The resulting matrix.
     */
    TMat4x4<T>& operator>>=( uint32 shift );

    /**
     * Gets the bitwise inverse of the components.
     *
     * @return The resulting matrix.
     */
    TMat4x4<T> operator~() const;
};

// ARITHMETIC BINARY OPERATOR DECLARATIONS
/**
 * Adds a scalar to the components of a matrix.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<T> operator+( const TMat4x4<T>& m, const U& s );

/**
 * Adds two matrices together.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator+( const TMat4x4<T>& m1, const TMat4x4<T>& m2 );

/**
 * Subtracts a scalar from the components of a matrix.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<T> operator-( const TMat4x4<T>& m, const U& s );

/**
 * Subtracts a matrix from another.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator-( const TMat4x4<T>& m1, const TMat4x4<T>& m2 );

/**
 * Multiplies the components of a matrix by a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( T, U, TMat4x4<T> ) operator*( const TMat4x4<T>& m, const U& s );

/**
 * Multiplies the components of a matrix by a scalar.
 *
 * @param s The scalar.
 * @param m The matrix.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( U, T, TMat4x4<U> ) operator*( const T& s, const TMat4x4<U>& m );

/**
 * Multiplies the matrix by a vector.
 *
 * @param m The matrix.
 * @param v The vector.
 * @return The resulting vector.
 */
template <typename T>
typename TMat4x4<T>::Column operator*( const TMat4x4<T>& m, const typename TMat4x4<T>::Row& v );

/**
 * Multiplies the vector by a matrix.
 *
 * @param v The vector.
 * @param m The matrix.
 * @return The resulting vector.
 */
template <typename T>
typename TMat4x4<T>::Row operator*( const typename TMat4x4<T>::Column& v, const TMat4x4<T>& m );

/**
 * Multiplies two matrices together.
 *
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator*( const TMat4x4<T>& a, const TMat4x4<T>& b );

/**
 * Divides the components of a matrix by a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( T, U, TMat4x4<T> ) operator/( const TMat4x4<T>& m, const U& s );

/**
 * Divides the components of a matrix by a scalar.
 *
 * @param s The scalar.
 * @param m The matrix.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( U, T, TMat4x4<U> ) operator/( const T& s, const TMat4x4<U>& m );

/**
 * Multiplies the row vector by a matrix.
 *
 * @param m The matrix.
 * @param r The row vector.
 * @return The resulting column vector.
 */
template <typename T>
typename TMat4x4<T>::Column operator/( const TMat4x4<T>& m, const typename TMat4x4<T>::Row& v );

/**
 * Divides the matrix by a column vector.
 *
 * @param c The column vector.
 * @param m The matrix.
 * @return The resulting row vector.
 */
template <typename T>
typename TMat4x4<T>::Row operator/( const typename TMat4x4<T>::Column& v, const TMat4x4<T>& m );

/**
 * Divides the first matrix by the second.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator/( const TMat4x4<T>& m1, const TMat4x4<T>& m2 );

/**
 * Gets the modulus of the components with a scalar value.
 *
 * @param m The matrix.
 * @param s The scalar to modulo with.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<T> operator%( const TMat4x4<T> m, const U& s );

/**
 * Gets the modulus of the components with a scalar value.
 *
 * @param m The matrix.
 * @param s The scalar to modulo with.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<U> operator%( const T& s, const TMat4x4<U> m );

/**
 * Performs modulo between the components of two matrices.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix..
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator%( const TMat4x4<T>& m1, const TMat4x4<T>& m2 );

// BITWISE BINARY OPERATOR DECLARATIONS
/**
 * Performs bitwise AND with the components and a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<T> operator&( const TMat4x4<T>& m, const U& s );

/**
 * Performs a component-wise AND operation.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator&( const TMat4x4<T>& m1, const TMat4x4<T> m2 );

/**
 * Performs bitwise OR the components and a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<T> operator|( const TMat4x4<T>& m, const U& s );

/**
 * Performs a component-wise OR operation.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator|( const TMat4x4<T>& m1, const TMat4x4<T> m2 );

/**
 * Performs bitwise XOR with the components and a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat4x4<T> operator^( const TMat4x4<T>& m, const U& s );

/**
 * Performs a component-wise XOR operation.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator^( const TMat4x4<T>& m1, const TMat4x4<T> m2 );

/**
 * Shifts the components of the matrix left x bits.
 *
 * @param shift The number of bits to shift.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator<<( const TMat4x4<T>& m, uint32 shift );

/**
 * Shifts the components of the matrix right x bits.
 *
 * @param shift The number of bits to shift.
 * @return The resulting matrix.
 */
template <typename T>
TMat4x4<T> operator>>( const TMat4x4<T>& m, uint32 shift );

// COMPARISON BINARY OPERATOR DECLARATIONS
/**
 * Checks if two matrices are equal.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator==( const TMat4x4<T>& m1, const TMat4x4<T>& m2 );

/**
 * Checks if two matrices are not equal.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator!=( const TMat4x4<T>& m1, const TMat4x4<T>& m2 );

// DEFINITIONS

// CONSTANTS
template <typename T>
const TMat4x4<T> TMat4x4<T>::IDENTITY = TMat4x4<T>( 1 );

template <typename T>
const TMat4x4<T> TMat4x4<T>::ZERO = TMat4x4<T>( 0 );

// CONSTRUCTORS
template <typename T>
inline
TMat4x4<T>::TMat4x4() : _value( { Column( 1, 0, 0, 0 ),
                                  Column( 0, 1, 0, 0 ),
                                  Column( 0, 0, 1, 0 ),
                                  Column( 0, 0, 0, 1 ) } )
{
}

template <typename T>
inline
TMat4x4<T>::TMat4x4( const TMat4x4<T>& m ) : _value( { m[0], m[1], m[2], m[3] } )
{
}

template <typename T>
template <typename U>
inline
TMat4x4<T>::TMat4x4( const U& s ) : _value( { Column( s, 0, 0, 0 ),
                                              Column( 0, s, 0, 0 ),
                                              Column( 0, 0, s, 0 ),
                                              Column( 0, 0, 0, s ) } )
{
}

template <typename T>
template <typename X1, typename X2, typename X3, typename X4,
          typename Y1, typename Y2, typename Y3, typename Y4,
          typename Z1, typename Z2, typename Z3, typename Z4,
          typename W1, typename W2, typename W3, typename W4>
inline
TMat4x4<T>::TMat4x4( const X1& x1, const X2& x2, const X3& x3, const X4& x4,
                     const Y1& y1, const Y2& y2, const Y3& y3, const Y4& y4,
                     const Z1& z1, const Z2& z2, const Z3& z3, const Z4& z4,
                     const W1& w1, const W2& w2, const W3& w3, const W4& w4 )
    : _value( { Column( T( x1 ), T( y1 ), T( z1 ), T( w1 ) ),
                Column( T( x2 ), T( y2 ), T( z2 ), T( w2 ) ),
                Column( T( x3 ), T( y3 ), T( z3 ), T( w3 ) ),
                Column( T( x4 ), T( y4 ), T( z4 ), T( w4 ) ) } )
{
}

template <typename T>
template <typename I, typename J, typename K, typename L>
inline
TMat4x4<T>::TMat4x4( const TVec4<I>& c1, const TVec4<J>& c2,
                     const TVec4<K>& c3, const TVec4<L>& c4 )
    : _value( { c1, c2, c3, c4 } )
{
}

template <typename T>
template <typename U>
inline
TMat4x4<T>::TMat4x4( const TMat2x2<U>& m )
    : _value( { Column( TVec2<T>( m[0] ), 0, 0 ),
                Column( TVec2<T>( m[1] ), 0, 0 ),
                Column( 0, 0, 1, 0 ),
                Column( 0, 0, 0, 1 ) } )
{
}

template <typename T>
template <typename U>
inline
TMat4x4<T>::TMat4x4( const TMat3x3<U>& m )
    : _value( { Column( TVec3<T>( m[0] ), 0 ),
                Column( TVec3<T>( m[1] ), 0 ),
                Column( TVec3<T>( m[2] ), 0 ),
                Column( 0, 0, 0, 1 ) } )
{
}

template <typename T>
template <typename U>
inline
TMat4x4<T>::TMat4x4( const TMat4x4<U>& m )
    : _value( { Column( m[0] ),
                Column( m[1] ),
                Column( m[2] ),
                Column( m[3] ) } )
{
}

template <typename T>
inline
TMat4x4<T>::~TMat4x4()
{
}

// ACCESSOR FUNCTIONS
template <typename T>
inline
const typename TMat4x4<T>::Column& TMat4x4<T>::operator[]( Size i ) const
{
    assert( i < TMat4x4<T>::COLUMNS );
    return _value[i];
}

template <typename T>
inline
typename TMat4x4<T>::Column& TMat4x4<T>::operator[]( Size i )
{
    assert( i < TMat4x4<T>::COLUMNS );
    return _value[i];
}

// ASSIGNMENT OPERATORS
template <typename T>
template <typename U>
TMat4x4<T>& TMat4x4<T>::operator=( const TMat4x4<U>& m )
{
    _value[0] = Column( m[0] );
    _value[1] = Column( m[1] );
    _value[2] = Column( m[2] );
    _value[3] = Column( m[3] );
    return *this;
}

// ARITHMETIC OPERATORS
template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator+=( const U& s )
{
    _value[0] += s;
    _value[1] += s;
    _value[2] += s;
    _value[3] += s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator+=( const TMat4x4<U>& m )
{
    _value[0] += m[0];
    _value[1] += m[1];
    _value[2] += m[2];
    _value[3] += m[3];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator-=( const U& s )
{
    _value[0] -= s;
    _value[1] -= s;
    _value[2] -= s;
    _value[3] -= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator-=( const TMat4x4<U>& m )
{
    _value[0] -= m[0];
    _value[1] -= m[1];
    _value[2] -= m[2];
    _value[3] -= m[3];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator*=( const U& s )
{
    _value[0] *= s;
    _value[1] *= s;
    _value[2] *= s;
    _value[3] *= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator*=( const TMat4x4<U>& m )
{
    // todo: do here if necessary
    return ( *this = *this * m );
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator/=( const U& s )
{
    _value[0] /= s;
    _value[1] /= s;
    _value[2] /= s;
    _value[3] /= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator/=( const TMat4x4<U>& m )
{
    return ( *this = *this / m );
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator%=( const U& s )
{
    _value[0] %= s;
    _value[1] %= s;
    _value[2] %= s;
    _value[3] %= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator%=( const TMat4x4<U>& m )
{
    _value[0] %= m[0];
    _value[1] %= m[1];
    _value[2] %= m[2];
    _value[3] %= m[3];
    return *this;
}

template <typename T>
inline
TMat4x4<T>& TMat4x4<T>::operator++()
{
    ++_value[0];
    ++_value[1];
    ++_value[2];
    ++_value[3];
    return *this;
}

template <typename T>
inline
TMat4x4<T>& TMat4x4<T>::operator--()
{
    --_value[0];
    --_value[1];
    --_value[2];
    --_value[3];
    return *this;
}

template <typename T>
inline
TMat4x4<T>& TMat4x4<T>::operator++( int )
{
    ++_value[0];
    ++_value[1];
    ++_value[2];
    ++_value[3];
    return *this;
}

template <typename T>
inline
TMat4x4<T>& TMat4x4<T>::operator--( int )
{
    --_value[0];
    --_value[1];
    --_value[2];
    --_value[3];
    return *this;
}

template <typename T>
inline
TMat4x4<T> TMat4x4<T>::operator-() const
{
    return TMat4x4<T>( -_value[0], -_value[1], -_value[2], -_value[3] );
}

// BITWISE UNARY OPERATORS
template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator&=( const U& s )
{
    _value[0] &= s;
    _value[1] &= s;
    _value[2] &= s;
    _value[3] &= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator&=( const TMat4x4<U>& m )
{
    _value[0] &= m[0];
    _value[1] &= m[1];
    _value[2] &= m[2];
    _value[3] &= m[3];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator|=( const U& s )
{
    _value[0] |= s;
    _value[1] |= s;
    _value[2] |= s;
    _value[3] |= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator|=( const TMat4x4<U>& m )
{
    _value[0] |= m[0];
    _value[1] |= m[1];
    _value[2] |= m[2];
    _value[3] |= m[3];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator^=( const U& s )
{
    _value[0] ^= s;
    _value[1] ^= s;
    _value[2] ^= s;
    _value[3] ^= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat4x4<T>& TMat4x4<T>::operator^=( const TMat4x4<U>& m )
{
    _value[0] ^= m[0];
    _value[1] ^= m[1];
    _value[2] ^= m[2];
    _value[3] ^= m[3];
    return *this;
}

template <typename T>
inline
TMat4x4<T>& TMat4x4<T>::operator<<=( uint32 shift )
{
    _value[0] <<= shift;
    _value[1] <<= shift;
    _value[2] <<= shift;
    _value[3] <<= shift;
    return *this;
}

template <typename T>
inline
TMat4x4<T>& TMat4x4<T>::operator>>=( uint32 shift )
{
    _value[0] >>= shift;
    _value[1] >>= shift;
    _value[2] >>= shift;
    _value[3] >>= shift;
    return *this;
}

template <typename T>
inline
TMat4x4<T> TMat4x4<T>::operator~() const
{
    return TMat4x4<T>( ~_value[0], ~_value[1], ~_value[2], ~_value[3] );
}

// ARITHMETIC BINARY OPERATORS
template <typename T>
inline
TMat4x4<T> operator+( const TMat4x4<T>& m, const T& s )
{
    return TMat4x4<T>( m[0] + s, m[1] + s, m[2] + s, m[3] + s );
}

template <typename T, typename U>
inline
TMat4x4<T> operator+( const TMat4x4<T>& m, const U& s )
{
    return ( m + static_cast<T>( s ) );
}

template <typename T>
inline
TMat4x4<T> operator+( const TMat4x4<T>& m1, const TMat4x4<T>& m2 )
{
    return TMat4x4<T>( m1[0] + m2[0],
                       m1[1] + m2[1],
                       m1[2] + m2[2],
                       m1[3] + m2[3] );
}

template <typename T>
inline
TMat4x4<T> operator-( const TMat4x4<T>& m, const T& s )
{
    return TMat4x4<T>( m[0] - s,
                       m[1] - s,
                       m[2] - s,
                       m[3] - s );
}

template <typename T, typename U>
inline
TMat4x4<T> operator-( const TMat4x4<T>& m, const U& s )
{
    return ( m - static_cast<T>( s ) );
}

template <typename T>
inline
TMat4x4<T> operator-( const TMat4x4<T>& m1, const TMat4x4<T>& m2 )
{
    return TMat4x4<T>( m1[0] - m2[0],
                       m1[1] - m2[1],
                       m1[2] - m2[2],
                       m1[3] - m2[3] );
}

template <typename T>
inline
VALIDATE( T, T, TMat4x4<T> ) operator*( const TMat4x4<T>& m, const T& s )
{
    return TMat4x4<T>( m[0] * s,
                       m[1] * s,
                       m[2] * s,
                       m[3] * s );
}

template <typename T, typename U>
inline
VALIDATE( T, U, TMat4x4<T> ) operator*( const TMat4x4<T>& m, const U& s )
{
    return ( m * static_cast<T>( s ) );
}

template <typename T>
inline
VALIDATE( T, T, TMat4x4<T> ) operator*( const T& s, const TMat4x4<T>& m )
{
    return TMat4x4<T>( m[0] * s,
                       m[1] * s,
                       m[2] * s,
                       m[3] * s );
}

template <typename T, typename U>
inline
VALIDATE( U, T, TMat4x4<U> ) operator*( const T& s, const TMat4x4<U>& m )
{
    return ( static_cast<U>( s ) * m );
}

template <typename T>
inline
typename TMat4x4<T>::Column operator*( const TMat4x4<T>& m, const typename TMat4x4<T>::Row& v )
{
    return typename TMat4x4<T>::Column(
        m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
        m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
        m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
        m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3] );
}

template <typename T>
inline
typename TMat4x4<T>::Row operator*( const typename TMat4x4<T>::Column& v, const TMat4x4<T>& m )
{
    return typename TMat4x4<T>::Row(
        v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2] + v[3] * m[0][3],
        v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2] + v[3] * m[1][3],
        v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2] + v[3] * m[2][3],
        v[0] * m[3][0] + v[1] * m[3][1] + v[2] * m[3][2] + v[3] * m[3][3] );
}

template <typename T>
inline
TMat4x4<T> operator*( const TMat4x4<T>& a, const TMat4x4<T>& b )
{
    return TMat4x4<T>(
        a[0][0] * b[0][0] + a[1][0] * b[0][1] + a[2][0] * b[0][2] + a[3][0] * b[0][3],
        a[0][0] * b[1][0] + a[1][0] * b[1][1] + a[2][0] * b[1][2] + a[3][0] * b[1][3],
        a[0][0] * b[2][0] + a[1][0] * b[2][1] + a[2][0] * b[2][2] + a[3][0] * b[2][3],
        a[0][0] * b[3][0] + a[1][0] * b[3][1] + a[2][0] * b[3][2] + a[3][0] * b[3][3],

        a[0][1] * b[0][0] + a[1][1] * b[0][1] + a[2][1] * b[0][2] + a[3][1] * b[0][3],
        a[0][1] * b[1][0] + a[1][1] * b[1][1] + a[2][1] * b[1][2] + a[3][1] * b[1][3],
        a[0][1] * b[2][0] + a[1][1] * b[2][1] + a[2][1] * b[2][2] + a[3][1] * b[2][3],
        a[0][1] * b[3][0] + a[1][1] * b[3][1] + a[2][1] * b[3][2] + a[3][1] * b[3][3],

        a[0][2] * b[0][0] + a[1][2] * b[0][1] + a[2][2] * b[0][2] + a[3][2] * b[0][3],
        a[0][2] * b[1][0] + a[1][2] * b[1][1] + a[2][2] * b[1][2] + a[3][2] * b[1][3],
        a[0][2] * b[2][0] + a[1][2] * b[2][1] + a[2][2] * b[2][2] + a[3][2] * b[2][3],
        a[0][2] * b[3][0] + a[1][2] * b[3][1] + a[2][2] * b[3][2] + a[3][2] * b[3][3],

        a[0][3] * b[0][0] + a[1][3] * b[0][1] + a[2][3] * b[0][2] + a[3][3] * b[0][3],
        a[0][3] * b[1][0] + a[1][3] * b[1][1] + a[2][3] * b[1][2] + a[3][3] * b[1][3],
        a[0][3] * b[2][0] + a[1][3] * b[2][1] + a[2][3] * b[2][2] + a[3][3] * b[2][3],
        a[0][3] * b[3][0] + a[1][3] * b[3][1] + a[2][3] * b[3][2] + a[3][3] * b[3][3] );

}

template <typename T>
inline
VALIDATE( T, T, TMat4x4<T> ) operator/( const TMat4x4<T>& m, const T& s )
{
    assert( s != 0 );
    return TMat4x4<T>(
        m[0] / s,
        m[1] / s,
        m[2] / s,
        m[3] / s );
}

template <typename T, typename U>
inline
VALIDATE( T, U, TMat4x4<T> ) operator/( const TMat4x4<T>& m, const U& s )
{
    return ( m / static_cast<T>( s ) );
}

template <typename T>
inline
VALIDATE( T, T, TMat4x4<T> ) operator/( const T& s, const TMat4x4<T>& m )
{
    return TMat4x4<T>(
        s / m[0],
        s / m[1],
        s / m[2],
        s / m[3] );
}

template <typename T, typename U>
inline
VALIDATE( U, T, TMat4x4<U> ) operator/( const T& s, const TMat4x4<U>& m )
{
    return ( static_cast<U>( s ) / m );
}

template <typename T>
inline
typename TMat4x4<T>::Column operator/( const TMat4x4<T>& m, const typename TMat4x4<T>::Row& v )
{
    return Mat::invert( m ) * v;
}

template <typename T>
inline
typename TMat4x4<T>::Row operator/( const typename TMat4x4<T>::Column& v, const TMat4x4<T>& m )
{
    return v * Mat::invert( m );
}

template <typename T>
inline
TMat4x4<T> operator/( const TMat4x4<T>& m1, const TMat4x4<T>& m2 )
{
    return ( m1 * Mat::invert( m2 ) );
}

template <typename T>
inline
TMat4x4<T> operator%( const TMat4x4<T> m, const T& s )
{
    return TMat4x4<T>( m[0] % s,
                       m[1] % s,
                       m[2] % s,
                       m[3] % s );
}

template <typename T, typename U>
inline
TMat4x4<T> operator%( const TMat4x4<T>& m, const U& s )
{
    return ( m % static_cast<T>( s ) );
}

template <typename T>
inline
TMat4x4<T> operator%( const T& s, const TMat4x4<T> m )
{
    return TMat4x4<T>( s % m[0],
                       s % m[1],
                       s % m[2],
                       s % m[3] );
}

template <typename T, typename U>
inline
TMat4x4<U> operator%( const T& s, const TMat4x4<U>& m )
{
    return ( static_cast<U>( s ) % m );
}

template <typename T>
inline
TMat4x4<T> operator%( const TMat4x4<T>& m1, const TMat4x4<T>& m2 )
{
    return TMat4x4<T>( m1[0] % m2[0],
                       m1[1] % m2[1],
                       m1[2] % m2[2],
                       m1[3] % m2[3] );
}

// BITWISE BINARY OPERATORS
template <typename T>
inline
TMat4x4<T> operator&( const TMat4x4<T>& m, const T& s )
{
    return TMat4x4<T>( m[0] & s,
                       m[1] & s,
                       m[2] & s,
                       m[3] & s );
}

template <typename T, typename U>
inline
TMat4x4<T> operator&( const TMat4x4<T>& m, const U& s )
{
    return ( m & static_cast<T>( s ) );
}

template <typename T>
inline
TMat4x4<T> operator&( const TMat4x4<T>& m1, const TMat4x4<T> m2 )
{
    return TMat4x4<T>( m1[0] & m2[0],
                       m1[1] & m2[1],
                       m1[2] & m2[2],
                       m1[3] & m2[3] );
}

template <typename T>
inline
TMat4x4<T> operator|( const TMat4x4<T>& m, const T& s )
{
    return TMat4x4<T>( m[0] | s,
                       m[1] | s,
                       m[2] | s,
                       m[3] | s );
}

template <typename T, typename U>
inline
TMat4x4<T> operator|( const TMat4x4<T>& m, const U& s )
{
    return ( m | static_cast<T>( s ) );
}

template <typename T>
inline
TMat4x4<T> operator|( const TMat4x4<T>& m1, const TMat4x4<T> m2 )
{
    return TMat4x4<T>( m1[0] | m2[0],
                       m1[1] | m2[1],
                       m1[2] | m2[2],
                       m1[3] | m2[3] );
}

template <typename T>
inline
TMat4x4<T> operator^( const TMat4x4<T>& m, const T& s )
{
    return TMat4x4<T>( m[0] ^ s,
                       m[1] ^ s,
                       m[2] ^ s,
                       m[3] ^ s );
}

template <typename T, typename U>
inline
TMat4x4<T> operator^( const TMat4x4<T>& m, const U& s )
{
    return ( m ^ static_cast<T>( s ) );
}

template <typename T>
inline
TMat4x4<T> operator^( const TMat4x4<T>& m1, const TMat4x4<T> m2 )
{
    return TMat4x4<T>( m1[0] ^ m2[0],
                       m1[1] ^ m2[1],
                       m1[2] ^ m2[2],
                       m1[3] ^ m2[3] );
}

template <typename T>
inline
TMat4x4<T> operator<<( const TMat4x4<T>& m, uint32 shift )
{
    return TMat4x4<T>( m[0] << shift, m[1] << shift, m[2] << shift, m[3] << shift );
}

template <typename T>
inline
TMat4x4<T> operator>>( const TMat4x4<T>& m, uint32 shift )
{
    return TMat4x4<T>( m[0] >> shift, m[1] >> shift, m[2] >> shift, m[3] >> shift );
}

// COMPARISON BINARY OPERATORS
template <typename T, typename U>
inline
bool operator==( const TMat4x4<T>& m1, const TMat4x4<U>& m2 )
{
    return m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2] && m1[3] == m2[3];
}

template <typename T, typename U>
inline
bool operator!=( const TMat4x4<T>& m1, const TMat4x4<U>& m2 )
{
    return m1[0] != m2[0] || m1[1] != m2[1] || m1[2] != m2[2] || m1[3] != m2[3];
}

} // End nspc math

} // End nspc gel

#undef VALIDATE

#endif //GEL_MAT4X4_H