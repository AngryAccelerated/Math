#ifndef MATH_QUAT_H
#define MATH_QUAT_H

#include "vec4.h"
#include "mat3.h"

namespace Math
{
	struct Quat
	{
		Quat();
		Quat(const real& s, const real& i, const real& j, const real& k);
		Quat(const Vec4& vec4);
		Quat(__m128 d);
		Quat(const real& s, const Vec3& vec3);
		Quat(const Quat& copy) = default;
		Quat(Quat&& copy) = default;


		Quat operator+(const Quat& rhs)const;
		Quat operator-(const Quat& rhs)const;
		Quat& operator+=(const Quat& rhs);
		Quat& operator-=(const Quat& rhs);

		Quat operator*(const real& rhs)const;
		Quat& operator*=(const real& rhs);
		Quat& operator=(const Quat& rhs);

		Quat& invert();
		Quat inverse();
		Quat conjugate();

		real magnitude()const;
		real magnitudeSquare()const;
		Quat normal();
		Quat& normalized();

		Quat& multiply(const Quat& rhs);

		Quat& set(const Quat& other);
		Quat& set(const Vec4& other);
		Quat& set(__m128 d);
		Quat& set(const real& s, const Vec3& v);

		Quat& clear();

		static Quat euler(const real& xDeg, const real& yDeg, const real& zDeg);
		static Quat slerp(const Quat& a, const Quat& b, const real& t);
		static Vec3 rotate(const Vec3& v, const Vec3& axis, const real& deg);



		static Quat multiply(const Quat& lhs, const Quat& rhs);

		union
		{
			struct
			{
				//imaginary
				float x;
				float y;
				float z;

				//real
				float s;
			};
			float f[4]{};
			__m128 data;
		};
	};
}
#endif