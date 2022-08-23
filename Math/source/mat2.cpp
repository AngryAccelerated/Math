#include "include/mat2.h"

namespace Math
{
	Mat2::Mat2()
	{
		clear();
	}

	Mat2::Mat2(const real& radian)
	{
		set(radian);
	}


	Mat2::Mat2(const Vec2& col0, const Vec2& col1) : c0(col0), c1(col1)
	{
	}

	Mat2::Mat2(const real& c0x, const real& c0y, const real& c1x, const real& c1y)
		: data(_mm_setr_ps(c0x, c0y, c1x, c1y))
	{
	}

	Mat2::Mat2(__m128 d)
	{
		_mm_store_ps(f, d);
	}

	Mat2::Mat2(const Mat2& mat)
	{
		set(mat);
	}

	

	Mat2& Mat2::operator=(const Mat2& rhs)
	{
		if (&rhs != this)
			set(rhs);
		return *this;
	}

	Mat2& Mat2::operator+=(const Mat2& rhs)
	{
		_mm_store_ps(f, _mm_add_ps(data, rhs.data));
		return *this;
	}

	Mat2& Mat2::operator-=(const Mat2& rhs)
	{
		_mm_store_ps(f, _mm_sub_ps(data, rhs.data));
		return *this;
	}

	Mat2& Mat2::operator*=(const real& factor)
	{
		_mm_store_ps(f, _mm_mul_ps(data, _mm_set1_ps(factor)));
		return *this;
	}

	Mat2& Mat2::operator/=(const real& factor)
	{
		checkZero(factor);
		_mm_store_ps(f, _mm_div_ps(data, _mm_set1_ps(factor)));
		return *this;
	}

	Mat2 Mat2::operator+(const Mat2& rhs) const
	{
		return Mat2(_mm_add_ps(data, rhs.data));
	}

	Mat2 Mat2::operator-(const Mat2& rhs) const
	{
		return Mat2(_mm_sub_ps(data, rhs.data));
	}

	Vec2 Mat2::operator[](uint8_t index)const
	{
		return v[index];
	}

	Vec2 Mat2::row1() const
	{
		return Vec2(c0.x, c1.x);
	}

	Vec2 Mat2::row2() const
	{
		return Vec2(c0.y, c1.y);
	}

	real Mat2::e00()const
	{
		return c0.x;
	}

	real Mat2::e01()const
	{
		return c0.y;
	}
	real Mat2::e10()const
	{
		return c1.x;
	}

	real Mat2::e11()const
	{
		return c1.y;
	}

	real Mat2::determinant() const
	{
		return determinant(*this);
	}

	Mat2& Mat2::transpose()
	{
		realSwap(c0.y, c1.x);
		return *this;
	}

	Mat2& Mat2::invert()
	{
		invert(*this);
		return *this;
	}

	Mat2& Mat2::multiply(const Mat2& rhs)
	{
		*this = multiply(*this, rhs);
		return *this;
	}

	Vec2 Mat2::multiply(const Vec2& rhs) const
	{
		return multiply(*this, rhs);
	}

	Mat2& Mat2::clear()
	{
		_mm_store_ps(f, _mm_setzero_ps());
		return *this;
	}

	Mat2& Mat2::set(const real& c0x, const real& c0y, const real& c1x, const real& c1y)
	{
		_mm_store_ps(f, _mm_setr_ps(c0x, c0y, c1x, c1y));
		return *this;
	}

	Mat2& Mat2::set(const Vec2& _c0, const Vec2& _c1)
	{
		_mm_store_ps(f, _mm_setr_ps(_c0.x, _c0.y, _c1.x, _c1.y));
		return *this;
	}

	Mat2& Mat2::set(const Mat2& other)
	{
		_mm_store_ps(f, other.data);
		return *this;
	}

	Mat2& Mat2::set(const real& radian)
	{
		const real c = Math::cosx(radian);
		const real s = Math::sinx(radian);
		_mm_store_ps(f, _mm_setr_ps(c, s, -s, c));
		return *this;
	}

	Mat2 Mat2::skewSymmetricMatrix(const Vec2& r)
	{
		return Mat2(0, -r.y, r.x, 0);
	}

	Mat2 Mat2::identity()
	{
		return Mat2(
			1, 0,
			0, 1);
	}

	Vec2 Mat2::multiply(const Mat2& lhs, const Vec2& rhs)
	{
		return Vec2(lhs.c0.x * rhs.x + lhs.c1.x * rhs.y, lhs.c0.y * rhs.x + lhs.c1.y * rhs.y);
	}

	Mat2 Mat2::multiply(const Mat2& lhs, const Mat2& rhs)
	{
		//lhs: x0 y0 x0 y0
		//rhs: x0 x0 x1 x1

		//lhs: x1 y1 x1 y1
		//rhs: y0 y0 y1 y1

		__m128 l1 = _mm_shuffle_ps(lhs.data, lhs.data, _MM_SHUFFLE(1, 0, 1, 0));
		__m128 r1 = _mm_shuffle_ps(rhs.data, rhs.data, _MM_SHUFFLE(2, 2, 0, 0));

		__m128 l2 = _mm_shuffle_ps(lhs.data, lhs.data, _MM_SHUFFLE(3, 2, 3, 2));
		__m128 r2 = _mm_shuffle_ps(rhs.data, rhs.data, _MM_SHUFFLE(3, 3, 1, 1));


		return { _mm_add_ps(_mm_mul_ps(l1, r1), _mm_mul_ps(l2, r2)) };
	}

	real Mat2::determinant(const Mat2& mat)
	{
		return mat.c0.x * mat.c1.y - mat.c1.x * mat.c0.y;
	}

	bool Mat2::invert(Mat2& mat)
	{
		const real det = mat.determinant();

		if (realEqual(det, 0))
			return false;

		realSwap(mat.c0.x, mat.c1.y);
		mat.f[1] *= -1;
		mat.f[2] *= -1;
		mat /= det;
		return true;
	}
}
