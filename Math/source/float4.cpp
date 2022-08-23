#include "include/float4.h"

namespace Math
{
	Float4::Float4()
	{
		clear();
	}
	Float4::Float4(const real& fillNumber)
	{
		fill(fillNumber);
	}
	Float4::Float4(const real& _x, const real& _y, const real& _z, const real& _s)
	{
		set(_x, _y, _z, _s);
	}
	Float4::Float4(__m128 d) : data(d)
	{
	}
	Float4::Float4(const Float4& copy)
	{
		set(copy);
	}
	Float4& Float4::fill(const real& fillNumber)
	{
		_mm_store_ps(f, _mm_set_ps1(fillNumber));
		return *this;
	}
	Float4& Float4::set(const Float4& float4)
	{
		_mm_store_ps(f, float4.data);
		return *this;
	}
	Float4& Float4::set(const real& _x, const real& _y, const real& _z, const real& _w)
	{
		_mm_store_ps(f, _mm_setr_ps(_x, _y, _z, _w));
		return *this;
	}
	Float4& Float4::set(__m128 d)
	{
		_mm_store_ps(f, d);
		return *this;
	}
	Float4& Float4::clear()
	{
		_mm_store_ps(f, _mm_setzero_ps());
		return *this;
	}
	Float4 Float4::operator+(const Float4& rhs) const
	{
		return { _mm_add_ps(data, rhs.data) };
	}

	Float4 Float4::operator-(const Float4& rhs) const
	{
		return { _mm_sub_ps(data, rhs.data) };
	}
	Float4 Float4::operator-() const
	{
		return { _mm_mul_ps(data, _mm_set_ps1(-1)) };
	}
	Float4 Float4::operator*(const real& factor) const
	{
		return { _mm_mul_ps(data, _mm_set_ps1(factor)) };
	}

	Float4 Float4::operator/(const real& factor) const
	{
		checkZero(factor);
		return { _mm_div_ps(data, _mm_set_ps1(factor)) };
	}

	Float4& Float4::operator+=(const Float4& rhs)
	{
		_mm_store_ps(f, _mm_add_ps(data, rhs.data));
		return *this;
	}

	Float4& Float4::operator-=(const Float4& rhs)
	{
		_mm_store_ps(f, _mm_sub_ps(data, rhs.data));
		return *this;
	}

	Float4& Float4::operator*=(const real& factor)
	{
		_mm_store_ps(f, _mm_mul_ps(data, _mm_set_ps1(factor)));
		return *this;
	}

	Float4& Float4::operator/=(const real& factor)
	{
		checkZero(factor);
		_mm_store_ps(f, _mm_div_ps(data, _mm_set_ps1(factor)));
		return *this;
	}
	real Float4::magnitude() const
	{
		return sqrt(magnitudeSquare());
	}
	real Float4::magnitudeSquare() const
	{
		return dotProduct(*this, *this);
	}

	Float4& Float4::swap(Float4& rhs)
	{
		__m128 temp = data;
		_mm_store_ps(f, rhs.data);
		_mm_store_ps(rhs.f, temp);
		return *this;
	}

	Float4& Float4::negate()
	{
		_mm_store_ps(f, _mm_mul_ps(data, _mm_set_ps1(-1)));
		return *this;
	}

	Float4 Float4::negative()
	{
		return Float4(_mm_mul_ps(data, _mm_set_ps1(-1)));
	}

	Float4 Float4::lerp(const Float4& b, const real& t) const
	{
		return lerp(*this, b, t);
	}

	real Float4::dot(const Float4& b)
	{
		return dotProduct(*this, b);
	}

	bool Float4::fuzzyEqual(const Float4& rhs, const real& epsilon) const
	{
		return (*this - rhs).magnitudeSquare() < epsilon;
	}

	bool Float4::isOrigin(const real& epsilon) const
	{
		return fuzzyEqual({ 0, 0, 0 , 0 }, epsilon);
	}

	real Float4::dotProduct(const Float4& lhs, const Float4& rhs)
	{
		//https://stackoverflow.com/questions/37879678/dot-product-performance-with-sse-instructions
		__m128 temp = _mm_dp_ps(lhs.data, rhs.data, 0xff);
		return reinterpret_cast<float*>(&temp)[0];
	}
	Float4 Float4::lerp(const Float4& a, const Float4& b, const real& t)
	{
		return a + (b - a) * t;
	}
}
