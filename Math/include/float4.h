#ifndef MATH_FLOAT4_H
#define MATH_FLOAT4_H

#include "math.h"

namespace Math
{
    struct alignas(16) Float4
    {
        Float4();
        Float4(const real& fillNumber);
        Float4(const real& x, const real& y, const real& z, const real& w);
        Float4(__m128 d);
        Float4(const Float4& copy);
        Float4(Float4&& other) = default;


        Float4& fill(const real& fillNumber);
        Float4& set(const Float4& float4);
        Float4& set(const real& x, const real& y, const real& z, const real& w);
        Float4& set(__m128 d);

        Float4& clear();

        Float4 operator+(const Float4& rhs) const;
        Float4 operator-(const Float4& rhs) const;
        Float4 operator-() const;
        Float4 operator*(const real& factor) const;
        Float4 operator/(const real& factor) const;

        Float4& operator+=(const Float4& rhs);
        Float4& operator-=(const Float4& rhs);
        Float4& operator*=(const real& factor);
        Float4& operator/=(const real& factor);

        real magnitude()const;
        real magnitudeSquare()const;
        Float4& swap(Float4& rhs);
        Float4& negate();

        Float4 negative();
        Float4 lerp(const Float4& b, const real& t)const;
        real dot(const Float4& b);

        bool fuzzyEqual(const Float4& rhs, const real& epsilon = Constant::Eps) const;
        bool isOrigin(const real& epsilon) const;

        static real dotProduct(const Float4& lhs, const Float4& rhs);
        static Float4 lerp(const Float4& a, const Float4& b, const real& t);

        union
        {
            struct
            {
                float x;
                float y;
                float z;
                union
                {
                    float s;
                    float w;
                };
            };
            float f[4]{};
            __m128 data;
        };
    };
}
#endif