#ifndef MATH_MAT3_H
#define MATH_MAT3_H

#include "vec3.h"
#include "vec2.h"
namespace Math
{

    struct Mat3
    {
        Mat3() = default;
        Mat3(const Mat3& mat);
        Mat3(const Vec3& c0, const Vec3& c1, const Vec3& c2);
        Mat3(const real& c0x, const real& col1_y, const real& col1_z,
            const real& col2_x, const real& col2_y, const real& col2_z,
            const real& col3_x, const real& col3_y, const real& col3_z);
        Mat3(Mat3&& other) = default;

        Mat3& operator=(const Mat3& rhs);
        Mat3& operator+=(const Mat3& rhs);
        Mat3& operator-=(const Mat3& rhs);
        Mat3& operator*=(const real& factor);
        Mat3& operator/=(const real& factor);

        Vec3 row1()const;
        Vec3 row2()const;
        Vec3 row3()const;

        real e11()const;
        real e12()const;
        real e13()const;

        real e21()const;
        real e22()const;
        real e23()const;

        real e31()const;
        real e32()const;
        real e33()const;

        Mat3& set(const real& col1_x, const real& col1_y, const real& col1_z,
            const real& col2_x, const real& col2_y, const real& col2_z,
            const real& col3_x, const real& col3_y, const real& col3_z);
        Mat3& set(const Vec3& col1, const Vec3& col2, const Vec3& col3);
        Mat3& set(const Mat3& other);
        Mat3& clear();

        Vec3 multiply(const Vec3& rhs)const;
        Mat3& multiply(const Mat3& rhs);
        real determinant()const;
        Mat3& transpose();
        Mat3& invert();

        static Mat3 skewSymmetricMatrix(const Vec3& v);
        static Mat3 identityMatrix();
        static Mat3 multiply(const Mat3& lhs, const Mat3& rhs);
        static Vec3 multiply(const Mat3& lhs, const Vec3& rhs);
        static real determinant(const Mat3& mat);
        static Mat3 rotate(const Vec3& axis, const real& deg);
        static bool invert(Mat3& mat);

        Vec3 column1;
        Vec3 column2;
        Vec3 column3;
    };
}
#endif
