#ifndef PHYS3D_MATH_MAT4_H
#define PHYS3D_MATH_MAT4_H
#include "mat3.h"
#include "vec4.h"

namespace Math
{
    struct Mat4
    {
        Mat4() = default;
        Mat4(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4);

        Mat4(const real& col1_x, const real& col1_y, const real& col1_z, const real& col1_w,
            const real& col2_x, const real& col2_y, const real& col2_z, const real& col2_w,
            const real& col3_x, const real& col3_y, const real& col3_z, const real& col3_w,
            const real& col4_x, const real& col4_y, const real& col4_z, const real& col4_w);

        Mat4(const Mat3& mat);
        Mat4(const Mat4& mat) = default;

        Mat4(Mat4&& other) = default;

        Mat4& operator=(const Mat3& rhs);
        Mat4& operator=(const Mat4& rhs);

        Mat4& operator+=(const Mat4& rhs);
        Mat4& operator-=(const Mat4& rhs);
        Mat4& operator*=(const real& factor);
        Mat4& operator/=(const real& factor);

        Vec4 row1()const;
        Vec4 row2()const;
        Vec4 row3()const;
        Vec4 row4()const;

        real e11()const;
        real e12()const;
        real e13()const;
        real e14()const;

        real e21()const;
        real e22()const;
        real e23()const;
        real e24()const;

        real e31()const;
        real e32()const;
        real e33()const;
        real e34()const;

        real e41()const;
        real e42()const;
        real e43()const;
        real e44()const;

        Mat4& set(const real& col1_x, const real& col1_y, const real& col1_z, const real& col1_w,
            const real& col2_x, const real& col2_y, const real& col2_z, const real& col2_w,
            const real& col3_x, const real& col3_y, const real& col3_z, const real& col3_w,
            const real& col4_x, const real& col4_y, const real& col4_z, const real& col4_w);

        Mat4& set(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4);
        Mat4& set(const Mat4& other);
        Mat4& set(const Mat3& other);

        Mat4& clear();

        Vec4 multiply(const Vec4& rhs)const;
        Mat4& multiply(const Mat4& rhs);
        real determinant()const;
        Mat4& transpose();
        Mat4& invert();

        static Mat4 identityMatrix();
        static Mat4 multiply(const Mat4& lhs, const Mat4& rhs);
        static Vec4 multiply(const Mat4& lhs, const Vec4& rhs);
        static real determinant(const Mat4& mat);
        static bool invert(Mat4& mat);

        union
        {
            struct
            {
                Vec4 c0;
                Vec4 c1;
                Vec4 c2;
                Vec4 c3;
            };
            Vec4 f[4];

        };

        Vec4 column1;
        Vec4 column2;
        Vec4 column3;
        Vec4 column4;
    };
}
#endif