#include "include/mat4.h"

namespace Math
{
	Mat4::Mat4()
	{
		clear();
	}

	Mat4::Mat4(const Vec4& r1, const Vec4& r2, const Vec4& r3, const Vec4& r4)
	{
	}
	Mat4::Mat4(const real& e00, const real& e01, const real& e02, const real& e03,
		const real& e10, const real& e11, const real& e12, const real& e13,
		const real& e20, const real& e21, const real& e22, const real& e23,
		const real& e30, const real& e31, const real& e32, const real& e33)
	{
	}
	Mat4::Mat4(const Mat3& mat)
	{
	}

	Mat4& Mat4::operator=(const Mat3& rhs)
	{

		return *this;
	}

	Mat4& Mat4::operator=(const Mat4& rhs)
	{

		return *this;
	}

	Mat4& Mat4::operator+=(const Mat4& rhs)
	{

		return *this;
	}

	Mat4& Mat4::operator-=(const Mat4& rhs)
	{

		return *this;
	}

	Mat4& Mat4::operator*=(const real& factor)
	{

		return *this;
	}

	Mat4& Mat4::operator/=(const real& factor)
	{
		checkZero(factor);

		return *this;
	}

	Vec4 Mat4::c0() const
	{
		return Vec4(r0.x, r1.x,
			r2.x, r3.x);
	}

	Vec4 Mat4::c1() const
	{
		return Vec4(r0.y, r1.y,
			r2.y, r3.y);
	}

	Vec4 Mat4::c2() const
	{
		return Vec4(r0.z, r1.z,
			r2.z, r3.z);
	}

	Vec4 Mat4::c3() const
	{
		return Vec4(r0.w, r1.w,
			r2.w, r3.w);
	}

	real Mat4::e00() const
	{
		return f[0];
	}

	real Mat4::e01() const
	{
		return f[1];
	}

	real Mat4::e02() const
	{
		return f[2];
	}

	real Mat4::e03() const
	{
		return f[3];
	}

	real Mat4::e10() const
	{
		return f[4];
	}

	real Mat4::e11() const
	{
		return f[5];
	}

	real Mat4::e12() const
	{
		return f[6];
	}

	real Mat4::e13() const
	{
		return f[7];
	}

	real Mat4::e20() const
	{
		return f[8];
	}

	real Mat4::e21() const
	{
		return f[9];
	}

	real Mat4::e22() const
	{
		return f[10];
	}

	real Mat4::e23() const
	{
		return f[11];
	}

	real Mat4::e30() const
	{
		return f[12];
	}
	real Mat4::e31() const
	{
		return f[13];
	}
	real Mat4::e32() const
	{
		return f[14];
	}

	real Mat4::e33() const
	{
		return f[15];
	}

	Mat4& Mat4::set(
		const real& _e00, const real& _e01, const real& _e02, const real& _e03,
		const real& _e10, const real& _e11, const real& _e12, const real& _e13,
		const real& _e20, const real& _e21, const real& _e22, const real& _e23,
		const real& _e30, const real& _e31, const real& _e32, const real& _e33)
	{

		return *this;
	}

	Mat4& Mat4::set(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4)
	{

		return *this;
	}

	Mat4& Mat4::set(const Mat4& other)
	{

		return *this;
	}

	Mat4& Mat4::set(const Mat3& other)
	{

		return *this;
	}

	Mat4& Mat4::clear()
	{
		_mm512_store_ps(f, _mm512_setzero_ps());
		return *this;
	}

	real Mat4::minor(const real& row, const real& column)
	{
		return real();
	}

	Vec4 Mat4::multiply(const Vec4& rhs) const
	{
		return multiply(*this, rhs);
	}

	Mat4& Mat4::multiply(const Mat4& rhs)
	{
		*this = multiply(*this, rhs);
		return *this;
	}

	real Mat4::determinant() const
	{
		return determinant(*this);
	}

	Mat4& Mat4::transpose()
	{

		return *this;
	}

	Mat4& Mat4::invert()
	{
		invert(*this);
		return *this;
	}

	Mat4 Mat4::identity()
	{
		return {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1 };
	}

	Mat4 Mat4::multiply(const Mat4& lhs, const Mat4& rhs)
	{
		return { };
	}

	Vec4 Mat4::multiply(const Mat4& lhs, const Vec4& rhs)
	{
		return { };
	}

	real Mat4::determinant(const Mat4& mat)
	{
		return real();
	}

	bool Mat4::invert(Mat4& mat)
	{
		const real det = mat.determinant();
		if (realEqual(det, 0.0f))
			return false;

		return true;
	}
}
