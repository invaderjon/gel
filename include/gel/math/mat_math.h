// mat_math.h
#ifndef GEL_MAT_MATH_H
#define GEL_MAT_MATH_H
#include <assert.h>
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

struct Mat
{
    /**
     * Computes the determinant of the matrix.
     *
     * @param m The matrix.
     * @return The determinant.
     */
    template <typename T>
    static TMat2x2<T> determinant( const TMat2x2<T>&m );

    /**
     * Computes the determinant of the matrix.
     *
     * @param m The matrix.
     * @return The determinant.
     */
    template <typename T>
    static TMat3x3<T> determinant( const TMat3x3<T>&m );

    /**
     * Computes the determinant of the matrix.
     *
     * @param m The matrix.
     * @return The determinant.
     */
    template <typename T>
    static TMat4x4<T> determinant( const TMat4x4<T>&m );

    /**
     * Computes the inverse of a matrix.
     *
     * @param m The matrix.
     * @return The inverse matrix.
     */
    template <typename T>
    static TMat2x2<T> invert( const TMat2x2<T>& m );

    /**
     * Computes the inverse of a matrix.
     *
     * @param m The matrix.
     * @return The inverse matrix.
     */
    template <typename T>
    static TMat3x3<T> invert( const TMat3x3<T>& m );

    /**
     * Computes the inverse of a matrix.
     *
     * @param m The matrix.
     * @return The inverse matrix.
     */
    template <typename T>
    static TMat4x4<T> invert( const TMat4x4<T>& m );

    /**
     * Computes the transpose of a matrix.
     *
     * @param m The matrix.
     * @return The inverse matrix.
     */
    template <typename T>
    static TMat4x4<T> transpose( const TMat4x4<T>& m );

    /**
     * Computes the transpose of a matrix.
     *
     * @param m The matrix.
     * @return The inverse matrix.
     */
    template <typename T>
    static TMat3x3<T> transpose( const TMat3x3<T>& m );

    /**
     * Computes the transpose of a matrix.
     *
     * @param m The matrix.
     * @return The inverse matrix.
     */
    template <typename T>
    static TMat2x2<T> transpose( const TMat2x2<T>& m );

    /**
     * Creates the translation matrix for the given offset.
     *
     * @param x The x offset.
     * @param y The y offset.
     * @param z The z offset.
     * @return The translation matrix.
     */
    template <typename T>
    static TMat4x4<T> translate( T x, T y, T z );

    /**
     * Creates the translation matrix for the given offset.
     *
     * @param offset The offset vector.
     * @return The translation matrix.
     */
    template <typename T>
    static TMat4x4<T> translate( TVec3<T> offset );

    /**
     * Creates the rotation matrix for the given rotation about the X axis.
     *
     * @param theta The rotation in radians.
     * @return The rotation matrix.
     */
    template <typename T, Math::AngleUnit Units = Math::Radians>
    static TMat4x4<T> rotateX( T theta );

    /**
     * Creates the rotation matrix for the given rotation about the y axis.
     *
     * @param theta The rotation in radians.
     * @return The rotation matrix.
     */
    template <typename T, Math::AngleUnit Units = Math::Radians>
    static TMat4x4<T> rotateY( T theta );

    /**
     * Creates the rotation matrix for the given rotation about the z axis.
     *
     * @param theta The rotation in radians.
     * @return The rotation matrix.
     */
    template <typename T, Math::AngleUnit Units = Math::Radians>
    static TMat4x4<T> rotateZ( T theta );
    /**
     * Creates the scale transformation matrix for the given scale factor.
     *
     * @param factor The scale factor.
     * @return THe scale matrix.
     */
    template <typename T>
    static TMat4x4<T> scale( T factor );
};

template <typename T>
TMat2x2<T> Mat::determinant( const TMat2x2<T>& m )
{
    // 2x2 Matrix
    // A B
    // C D

    // assign meaningful names to the values for readability
    #define A ( m[0][0] )
    #define B ( m[1][0] )
    #define C ( m[0][1] )
    #define D ( m[1][1] )

    // determinant
    T det = A * D - B * C;

    #undef A
    #undef B
    #undef C
    #undef D

    return det;
}

template <typename T>
TMat3x3<T> Mat::determinant( const TMat3x3<T>& m )
{
    // 3x3 Matrix
    // A B C
    // D E F
    // G H I

    // assign meaningful names to the values for readability
    #define A ( m[0][0] )
    #define B ( m[1][0] )
    #define C ( m[2][0] )
    #define D ( m[0][1] )
    #define E ( m[1][1] )
    #define F ( m[2][1] )
    #define G ( m[0][2] )
    #define H ( m[1][2] )
    #define I ( m[2][2] )

    // calculate cofactors
    T Ca =  E * I - F * H;
    T Cb = -D * I + F * G;
    T Cc =  D * H - E * G;

    // determinant from minors
    T det = A * Ca + B * Cb + C * Cc;

    #undef A
    #undef B
    #undef C
    #undef D
    #undef E
    #undef F
    #undef G
    #undef H
    #undef I

    return det;
}

template <typename T>
TMat4x4<T> Mat::determinant( const TMat4x4<T>& m )
{
    // 4x4 Matrix
    // A B C D
    // E F G H
    // I J K L
    // M N O P

    // assign meaningful names to the values for readability
    #define A ( m[0][0] )
    #define B ( m[1][0] )
    #define C ( m[2][0] )
    #define D ( m[3][0] )
    #define E ( m[0][1] )
    #define F ( m[1][1] )
    #define G ( m[2][1] )
    #define H ( m[3][1] )
    #define I ( m[0][2] )
    #define J ( m[1][2] )
    #define K ( m[2][2] )
    #define L ( m[3][2] )
    #define M ( m[0][3] )
    #define N ( m[1][3] )
    #define O ( m[2][3] )
    #define P ( m[3][3] )

    // pre-calculate 2x2 determinants
    T KLOP = K * P - O * L;
    T JLNP = J * P - N * L;
    T JKNO = J * O - N * K;
    T ILMP = I * P - M * L;
    T IKMO = I * O - M * K;
    T IJMN = I * N - M * J;

    // calculate cofactors
    T Ca =  F * KLOP - G * JLNP + H * JKNO;
    T Cb = -E * KLOP + G * ILMP - H * IKMO;
    T Cc =  E * JLNP - F * ILMP + H * IJMN;
    T Cd = -E * JKNO + F * IKMO - G * IJMN;

    // determinant from minors
    T det =  A * Ca + B * Cb + C * Cc + D * Cd;

    #undef A
    #undef B
    #undef C
    #undef D
    #undef E
    #undef F
    #undef G
    #undef H
    #undef I
    #undef J
    #undef K
    #undef L
    #undef M
    #undef N
    #undef O
    #undef P

    return det;
}

template <typename T>
TMat2x2<T> Mat::invert( const TMat2x2<T>& m )
{
    // 2x2 Matrix
    // A B
    // C D

    // assign meaningful names to the values for readability
    #define A ( m[0][0] )
    #define B ( m[1][0] )
    #define C ( m[0][1] )
    #define D ( m[1][1] )

    // create adjoint matrix
    TMat2x2<T> adj( D, -B, -C, A );

    // determinant
    T det = A * D - B * C;

    assert( det != static_cast<T>( 0 ) );

    T oneOverDet = static_cast<T>( 1 ) / det;

    #undef A
    #undef B
    #undef C
    #undef D

    return oneOverDet * adj;
}

template <typename T>
TMat3x3<T> Mat::invert( const TMat3x3<T>& m )
{
    // 3x3 Matrix
    // A B C
    // D E F
    // G H I

    // assign meaningful names to the values for readability
    #define A ( m[0][0] )
    #define B ( m[1][0] )
    #define C ( m[2][0] )
    #define D ( m[0][1] )
    #define E ( m[1][1] )
    #define F ( m[2][1] )
    #define G ( m[0][2] )
    #define H ( m[1][2] )
    #define I ( m[2][2] )

    // calculate cofactors
    T Ca =  E * I - F * H;
    T Cb = -D * I + F * G;
    T Cc =  D * H - E * G;
    T Cd = -B * I + C * H;
    T Ce =  A * I - C * G;
    T Cf = -A * H + B * G;
    T Cg =  B * F - C * E;
    T Ch = -A * F + C * D;
    T Ci =  A * E - B * D;

    // adjoint matrix
    TMat3x3<T> adj( Ca, Cd, Cg, Cb, Ce, Ch, Cc, Cf, Ci );

    // determinant from minors
    T det = A * Ca + B * Cb + C * Cc;

    assert( det != static_cast<T>( 0 ) );

    T oneOverDet = static_cast<T>( 1 ) / det;

    #undef A
    #undef B
    #undef C
    #undef D
    #undef E
    #undef F
    #undef G
    #undef H
    #undef I

    return oneOverDet * adj;
}

template <typename T>
TMat4x4<T> Mat::invert( const TMat4x4<T>& m )
{
    // 4x4 Matrix
    // A B C D
    // E F G H
    // I J K L
    // M N O P

    // assign meaningful names to the values for readability
    #define A ( m[0][0] )
    #define B ( m[1][0] )
    #define C ( m[2][0] )
    #define D ( m[3][0] )
    #define E ( m[0][1] )
    #define F ( m[1][1] )
    #define G ( m[2][1] )
    #define H ( m[3][1] )
    #define I ( m[0][2] )
    #define J ( m[1][2] )
    #define K ( m[2][2] )
    #define L ( m[3][2] )
    #define M ( m[0][3] )
    #define N ( m[1][3] )
    #define O ( m[2][3] )
    #define P ( m[3][3] )

    // pre-calculate 2x2 determinants
    T KLOP = K * P - O * L;
    T JLNP = J * P - N * L;
    T JKNO = J * O - N * K;
    T ILMP = I * P - M * L;
    T IKMO = I * O - M * K;
    T IJMN = I * N - M * J;
    T GHOP = G * P - O * H;
    T FHNP = F * P - N * H;
    T GHKL = G * L - K * H;
    T FGJK = F * K - J * G;
    T FHJL = F * L - J * H;
    T FGNO = F * O - N * G;
    T EHMP = E * P - M * H;
    T EGMO = E * O - M * G;
    T EFMN = E * N - M * F;
    T EHIL = E * L - I * H;
    T EGIK = E * K - I * G;
    T EFIJ = E * J - I * F;

    // calculate cofactors
    T Ca =  F * KLOP - G * JLNP + H * JKNO;
    T Cb = -E * KLOP + G * ILMP - H * IKMO;
    T Cc =  E * JLNP - F * ILMP + H * IJMN;
    T Cd = -E * JKNO + F * IKMO - G * IJMN;

    T Ce = -B * KLOP + C * JLNP - D * JKNO;
    T Cf =  A * KLOP - C * ILMP + D * IKMO;
    T Cg = -A * JLNP + B * ILMP - D * IJMN;
    T Ch =  A * JKNO - B * IKMO + C * IJMN;

    T Ci =  B * GHOP - C * FHNP + D * FGNO;
    T Cj = -A * GHOP + C * EHMP - D * EGMO;
    T Ck =  A * FHNP - B * EHMP + D * EFMN;
    T Cl = -A * FGNO + B * EGMO - C * EFMN;

    T Cm = -B * GHKL + C * FHJL - D * FGJK;
    T Cn =  A * GHKL - C * EHIL + D * EGIK;
    T Co = -A * FHJL + B * EHIL - D * EFIJ;
    T Cp =  A * FGJK - B * EGIK + C * EFIJ;

    // adjoint matrix
    TMat4x4<T> adj( Ca, Ce, Ci, Cm, Cb, Cf, Cj, Cn, Cc, Cg, Ck, Co, Cd, Ch, Cl, Cp );

    // determinant from minors
    T det = A * Ca + B * Cb + C * Cc + D * Cd;

    assert( det != static_cast<T>( 0 ) );

    T oneOverDet = static_cast<T>( 1 ) / det;

    #undef A
    #undef B
    #undef C
    #undef D
    #undef E
    #undef F
    #undef G
    #undef H
    #undef I
    #undef J
    #undef K
    #undef L
    #undef M
    #undef N
    #undef O
    #undef P

    return oneOverDet * adj;
}

template <typename T>
TMat4x4<T> Mat::transpose( const TMat4x4<T>& m )
{
    return TMat4x4<T>(
        m[0][0], m[0][1], m[0][2], m[0][3],
        m[1][0], m[1][1], m[1][2], m[1][3],
        m[2][0], m[2][1], m[2][2], m[2][3],
        m[3][0], m[3][1], m[3][2], m[3][3] );
}

template <typename T>
TMat3x3<T> Mat::transpose( const TMat3x3<T>& m )
{
    return TMat3x3<T>(
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2] );
}

template <typename T>
TMat2x2<T> Mat::transpose( const TMat2x2<T>& m )
{
    return TMat2x2<T>(
        m[0][0], m[0][1],
        m[1][0], m[1][1] );
}

template <typename T>
inline
TMat4x4<T> Mat::translate( T x, T y, T z )
{
    return Mat::translate( TVec3<T>( x, y, z ));
}

template <typename T>
inline
TMat4x4<T> Mat::translate( TVec3<T> offset )
{
    return TMat4x4<T>(
        1, 0, 0, offset.x,
        0, 1, 0, offset.y,
        0, 0, 0, offset.z,
        0, 0, 0, 1
    );
}

template <typename T, Math::AngleUnit Units>
inline
TMat4x4<T> Mat::rotateX( T theta )
{
    return TMat4x4<T>(
        1, 0, 0, 0,
        0, Math::cos<Units>( theta ), -Math::sin<Units>( theta ), 0,
        0, Math::sin<Units>( theta ), Math::cos<Units>( theta ), 0,
        0, 0, 0, 1
    );
}

template <typename T, Math::AngleUnit Units>
inline
TMat4x4<T> Mat::rotateY( T theta )
{
    return TMat4x4<T>(
        Math::cos( theta ), 0, Math::sin( theta ), 0,
        0, 1, 0, 0,
        -Math::sin( theta ), 0, Math::cos( theta ), 0,
        0, 0, 0, 1
    );
}

template <typename T, Math::AngleUnit Units>
inline
TMat4x4<T> Mat::rotateZ( T theta )
{
    return TMat4x4<T>(
        Math::cos( theta ), -Math::sin( theta ), 0, 0,
        Math::sin( theta ), Math::cos( theta ), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

template <typename T>
inline
TMat4x4<T> Mat::scale( T factor )
{
    return TMat4x4<T>(
        factor, 0, 0, 0,
        0, factor, 0, 0,
        0, 0, factor, 0,
        0, 0, 0, 1
    );
}

} // End nspc math

} // End nspc gel

#endif //GEL_MAT_MATH_H
