#include "include/quat.h"

namespace Math
{
	Quat::Quat()
	{
		clear();
	}
	Quat::Quat(const real& _s, const real& i, const real& j, const real& k)
		:data(_mm_setr_ps(i, j, k, _s))
	{

	}
	Quat::Quat(const Vec4& vec4)
	{
		set(vec4);
	}
	Quat::Quat(__m128 d)
	{
		set(d);
	}
	Quat::Quat(const real& _s, const Vec3& vec3)
	{
		_mm_store_ps(f, vec3.data);
		s = _s;
	}

	Quat Quat::operator+(const Quat& rhs)const
	{
		return { _mm_add_ps(data, rhs.data) };
	}

	Quat Quat::operator-(const Quat& rhs)const
	{
		return { _mm_sub_ps(data, rhs.data) };
	}

	Quat& Quat::operator+=(const Quat& rhs)
	{
		_mm_store_ps(f, _mm_add_ps(data, rhs.data));
		return *this;
	}

	Quat& Quat::operator-=(const Quat& rhs)
	{
		_mm_store_ps(f, _mm_sub_ps(data, rhs.data));
		return *this;
	}

	Quat Quat::operator*(const real& rhs)const
	{
		return { _mm_mul_ps(data, _mm_set_ps1(rhs)) };
	}

	Quat& Quat::operator*=(const real& rhs)
	{
		_mm_store_ps(f, _mm_mul_ps(data, _mm_set_ps1(rhs)));
		return *this;
	}

	Quat& Quat::operator=(const Quat& rhs)
	{
		if (&rhs != this)
			set(rhs);
		return *this;
	}

	Quat& Quat::invert()
	{
		Quat conj = conjugate();
		real norm = magnitudeSquare();
		checkZero(norm);
		*this = conj * (1.0f / norm);
		return *this;
	}

	Quat Quat::inverse()
	{
		Quat copy = *this;
		return copy.invert();
	}

	Quat Quat::conjugate()
	{
		return { _mm_mul_ps(data, _mm_setr_ps(1, -1, -1, -1)) };
	}

	real Quat::magnitude() const
	{
		return std::sqrt(magnitudeSquare());
	}

	real Quat::magnitudeSquare() const
	{
		//https://stackoverflow.com/questions/37879678/dot-product-performance-with-sse-instructions
		__m128 temp = _mm_dp_ps(data, data, 0xff);
		return reinterpret_cast<float*>(&temp)[0];
	}

	Quat Quat::normal()
	{
		Quat copy = *this;
		return copy.normalized();
	}

	Quat& Quat::normalized()
	{
		real norm = magnitude();
		checkZero(norm);
		*this *= 1.0f / norm;
		return *this;
	}

	Quat& Quat::multiply(const Quat& rhs)
	{
		*this = multiply(*this, rhs);
		return *this;
	}

	Quat& Quat::set(const Quat& other)
	{
		_mm_store_ps(f, other.data);
		return *this;
	}

	Quat& Quat::set(const Vec4& other)
	{
		_mm_store_ps(f, other.data);
		return *this;
	}

	Quat& Quat::set(__m128 d)
	{
		_mm_store_ps(f, d);
		return *this;
	}

	Quat& Quat::set(const real& _s, const Vec3& v)
	{
		_mm_store_ps(f, v.data);
		s = _s;
		return *this;
	}

	Quat& Quat::clear()
	{
		_mm_store_ps(f, _mm_setzero_ps());
		return *this;
	}

	Quat Quat::euler(const real& xDeg, const real& yDeg, const real& zDeg)
	{
		return {};
	}
	Quat Quat::slerp(const Quat& a, const Quat& b, const real& t)
	{
		Quat q;

		Vec3 ImA(a.data);
		Vec3 ImB(b.data);
		real theta = Math::arccosx(ImA.dot(ImB));
		real sinTheta = Math::sinx(theta);
		checkZero(sinTheta);
		q = a * (Math::sinx((1.0f - t) * theta) / sinTheta) + b * (Math::sinx((t * theta)) / sinTheta);
		return q;
	}
	Vec3 Quat::rotate(const Vec3& _v, const Vec3& u, const real& deg)
	{
		Quat v(0, _v);
		Quat q(Math::cosx(Math::degreeToRadian(deg) / 2.0f), u * Math::sinx(Math::degreeToRadian(deg) / 2.0f));
		return { q.multiply(v).multiply(q.inverse()).data };
	}

	Quat Quat::multiply(const Quat& lhs, const Quat& rhs)
	{
		real s;
		Vec3 v;
		Vec3 ImL(lhs.data);
		Vec3 ImR(lhs.data);
		s = lhs.s * rhs.s - ImL.dot(ImR);
		v = ImR * lhs.s + ImL * rhs.s + Vec3::crossProduct(ImL, ImR);
		return { s, v };
	}
}