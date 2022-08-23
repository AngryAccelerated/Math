#include "include/mat3.h"

namespace Math
{
	Mat3::Mat3(const Mat3& mat) : column1(mat.column1), column2(mat.column2), column3(mat.column3)
	{
	}


	Mat3::Mat3(const Vec3& col1, const Vec3& col2, const Vec3& col3)
		: column1(col1), column2(col2), column3(col3)
	{
	}

	Mat3::Mat3(const real& col1_x, const real& col1_y, const real& col1_z, const real& col2_x,
		const real& col2_y, const real& col2_z, const real& col3_x, const real& col3_y,
		const real& col3_z)
		: column1(col1_x, col1_y, col1_z), column2(col2_x, col2_y, col2_z), column3(col3_x, col3_y, col3_z)
	{
	}

	Mat3& Mat3::operator=(const Mat3& rhs)
	{
		if (&rhs == this)
			return *this;
		column1 = rhs.column1;
		column2 = rhs.column2;
		column3 = rhs.column3;
		return *this;
	}

	Mat3& Mat3::operator+=(const Mat3& rhs)
	{
		column1 += rhs.column1;
		column2 += rhs.column2;
		column3 += rhs.column3;
		return *this;
	}

	Mat3& Mat3::operator-=(const Mat3& rhs)
	{
		column1 -= rhs.column1;
		column2 -= rhs.column2;
		column3 -= rhs.column3;
		return *this;
	}

	Mat3& Mat3::operator*=(const real& factor)
	{
		column1 *= factor;
		column2 *= factor;
		column3 *= factor;
		return *this;
	}

	Mat3& Mat3::operator/=(const real& factor)
	{
		assert(!realEqual(factor, 0));
		column1 /= factor;
		column2 /= factor;
		column3 /= factor;
		return *this;
	}

	Vec3 Mat3::row1() const
	{
		return Vec3(column1.x, column2.x, column3.x);
	}

	Vec3 Mat3::row2() const
	{
		return Vec3(column1.y, column2.y, column3.y);
	}

	Vec3 Mat3::row3() const
	{
		return Vec3(column1.z, column2.z, column3.z);
	}

	real Mat3::e11()const
	{
		return column1.x;
	}

	real Mat3::e12()const
	{
		return column2.x;
	}

	real Mat3::e13()const
	{
		return column3.x;
	}

	real Mat3::e21()const
	{
		return column1.y;
	}

	real Mat3::e22()const
	{
		return column2.y;
	}

	real Mat3::e23()const
	{
		return column3.y;
	}

	real Mat3::e31()const
	{
		return column1.z;
	}

	real Mat3::e32()const
	{
		return column2.z;
	}

	real Mat3::e33()const
	{
		return column3.z;
	}

	real Mat3::determinant() const
	{
		return determinant(*this);
	}

	Mat3& Mat3::transpose()
	{
		realSwap(column1.y, column2.x);
		realSwap(column1.z, column3.x);
		realSwap(column2.z, column3.y);
		return *this;
	}

	Mat3& Mat3::invert()
	{
		invert(*this);
		return *this;
	}

	Mat3& Mat3::clear()
	{
		column1.clear();
		column2.clear();
		column3.clear();
		return *this;
	}

	Mat3& Mat3::set(const real& col1_x, const real& col1_y, const real& col1_z, const real& col2_x,
		const real& col2_y, const real& col2_z, const real& col3_x, const real& col3_y,
		const real& col3_z)
	{
		column1.set(col1_x, col1_y, col1_z);
		column2.set(col2_x, col2_y, col2_z);
		column3.set(col3_x, col3_y, col3_z);
		return *this;
	}

	Mat3& Mat3::set(const Vec3& col1, const Vec3& col2, const Vec3& col3)
	{
		column1 = col1;
		column2 = col2;
		column3 = col3;
		return *this;
	}

	Mat3& Mat3::set(const Mat3& other)
	{
		column1 = other.column1;
		column2 = other.column2;
		column3 = other.column3;
		return *this;
	}

	Vec3 Mat3::multiply(const Vec3& rhs) const
	{
		return multiply(*this, rhs);
	}

	Mat3& Mat3::multiply(const Mat3& rhs)
	{
		*this = multiply(*this, rhs);
		return *this;
	}

	Mat3 Mat3::skewSymmetricMatrix(const Vec3& v)
	{
		return Mat3(
			0, v.z, -v.y,
			-v.z, 0, v.x,
			v.y, -v.x, 0);
	}

	Mat3 Mat3::identityMatrix()
	{
		return Mat3(1, 0, 0,
			0, 1, 0,
			0, 0, 1);
	}

	Mat3 Mat3::multiply(const Mat3& lhs, const Mat3& rhs)
	{
		return Mat3(multiply(lhs, rhs.column1),
			multiply(lhs, rhs.column2),
			multiply(lhs, rhs.column3));
	}

	Vec3 Mat3::multiply(const Mat3& lhs, const Vec3& rhs)
	{
		return Vec3(lhs.column1.x * rhs.x + lhs.column2.x * rhs.y + lhs.column3.x * rhs.z,
			lhs.column1.y * rhs.x + lhs.column2.y * rhs.y + lhs.column3.y * rhs.z,
			lhs.column1.z * rhs.x + lhs.column2.z * rhs.y + lhs.column3.z * rhs.z);
	}

	real Mat3::determinant(const Mat3& mat)
	{
		return mat.column1.x * Vec2::crossProduct(mat.column2.y, mat.column2.z, mat.column3.y, mat.column3.z) +
			mat.column2.x * Vec2::crossProduct(mat.column3.y, mat.column3.z, mat.column1.y, mat.column1.z) +
			mat.column3.x * Vec2::crossProduct(mat.column1.y, mat.column1.z, mat.column2.y, mat.column2.z);
	}

	Mat3 Mat3::rotate(const Vec3& axis, const real& deg)
	{
		Mat3 mat3;
		real a = Math::cosx(Math::degreeToRadian(deg) / 2.0f);
		real sin = Math::sinx(Math::degreeToRadian(deg) / 2.0f);
		real b = sin * axis.x;
		real c = sin * axis.y;
		real d = sin * axis.z;
		mat3.column1.set(1.0f - 2.0f * (c * c + d * d), 2 * (b * c + a * d), 2 * (b * d - a * c));
		mat3.column2.set(2 * (b * c - a * d), 1.0f - 2.0f * (b * b + d * d), 2 * (a * b + c * d));
		mat3.column3.set(2 * (b * d + a * c), 2 * (c * d - a * b), 1.0f - 2.0f * (b * b + c * c));
		return mat3;
	}

	bool Mat3::invert(Mat3& mat)
	{
		const real det = mat.determinant();
		if (realEqual(det, 0.0f))
			return false;

		const real det11 = Vec2::crossProduct(mat.column2.y, mat.column2.z, mat.column3.y, mat.column3.z);
		const real det12 = Vec2::crossProduct(mat.column2.x, mat.column2.z, mat.column3.x, mat.column3.z) * -1;
		const real det13 = Vec2::crossProduct(mat.column2.x, mat.column2.y, mat.column3.x, mat.column3.y);

		const real det21 = Vec2::crossProduct(mat.column1.y, mat.column1.z, mat.column3.y, mat.column3.z) * -1;
		const real det22 = Vec2::crossProduct(mat.column1.x, mat.column1.z, mat.column3.x, mat.column3.z);
		const real det23 = Vec2::crossProduct(mat.column1.x, mat.column1.y, mat.column3.x, mat.column3.y) * -1;

		const real det31 = Vec2::crossProduct(mat.column1.y, mat.column1.z, mat.column2.y, mat.column2.z);
		const real det32 = Vec2::crossProduct(mat.column1.x, mat.column1.z, mat.column2.x, mat.column2.z) * -1;
		const real det33 = Vec2::crossProduct(mat.column1.x, mat.column1.y, mat.column2.x, mat.column2.y);

		mat.set(det11, det12, det13, det21, det22, det23, det31, det32, det33);
		mat.transpose();
		mat /= det;
		return true;
	}
}
