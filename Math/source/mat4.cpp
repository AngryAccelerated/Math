#include "include/mat4.h"

namespace Math
{
	Mat4::Mat4(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4)
		:column1(col1), column2(col2), column3(col3), column4(col4)
	{
	}
	Mat4::Mat4(const real& col1_x, const real& col1_y, const real& col1_z, const real& col1_w, const real& col2_x, const real& col2_y, const real& col2_z, const real& col2_w, const real& col3_x, const real& col3_y, const real& col3_z, const real& col3_w, const real& col4_x, const real& col4_y, const real& col4_z, const real& col4_w)
		: column1(col1_x, col1_y, col1_z, col1_w),
		column2(col2_x, col2_y, col2_z, col2_w),
		column3(col3_x, col3_y, col3_z, col3_w),
		column4(col4_x, col4_y, col4_z, col4_w)
	{
	}
	Mat4::Mat4(const Mat3& mat)
		:column1(mat.column1.x, mat.column1.y, mat.column1.z, 0),
		column2(mat.column2.x, mat.column2.y, mat.column2.z, 0),
		column3(mat.column3.x, mat.column3.y, mat.column3.z, 0)
	{
	}

	Mat4& Mat4::operator=(const Mat3& rhs)
	{
		column1 = rhs.column1;
		column2 = rhs.column2;
		column3 = rhs.column3;
		column4.clear();
		return *this;
	}

	Mat4& Mat4::operator=(const Mat4& rhs)
	{
		column1 = rhs.column1;
		column2 = rhs.column2;
		column3 = rhs.column3;
		column4 = rhs.column4;
		return *this;
	}

	Mat4& Mat4::operator+=(const Mat4& rhs)
	{
		column1 += rhs.column1;
		column2 += rhs.column2;
		column3 += rhs.column3;
		column4 += rhs.column4;
		return *this;
	}

	Mat4& Mat4::operator-=(const Mat4& rhs)
	{
		column1 -= rhs.column1;
		column2 -= rhs.column2;
		column3 -= rhs.column3;
		column4 -= rhs.column4;
		return *this;
	}

	Mat4& Mat4::operator*=(const real& factor)
	{
		column1 *= factor;
		column2 *= factor;
		column3 *= factor;
		column4 *= factor;
		return *this;
	}

	Mat4& Mat4::operator/=(const real& factor)
	{
		column1 /= factor;
		column2 /= factor;
		column3 /= factor;
		column4 /= factor;
		return *this;
	}

	Vec4 Mat4::row1() const
	{
		return Vec4(column1.x, column2.x,
			column3.x, column4.x);
	}

	Vec4 Mat4::row2() const
	{
		return Vec4(column1.y, column2.y,
			column3.y, column4.y);
	}

	Vec4 Mat4::row3() const
	{
		return Vec4(column1.z, column2.z,
			column3.z, column4.z);
	}

	Vec4 Mat4::row4() const
	{
		return Vec4(column1.w, column2.w,
			column3.w, column4.w);
	}

	real Mat4::e11()const
	{
		return column1.x;
	}

	real Mat4::e12()const
	{
		return column1.y;
	}

	real Mat4::e13()const
	{
		return column1.z;
	}

	real Mat4::e14()const
	{
		return column1.w;
	}

	real Mat4::e21()const
	{
		return column2.x;
	}

	real Mat4::e22()const
	{
		return column2.y;
	}

	real Mat4::e23()const
	{
		return column2.z;
	}

	real Mat4::e24()const
	{
		return column2.w;
	}

	real Mat4::e31()const
	{
		return column3.x;
	}

	real Mat4::e32()const
	{
		return column3.y;
	}

	real Mat4::e33()const
	{
		return column3.z;
	}

	real Mat4::e34()const
	{
		return column3.w;
	}

	real Mat4::e41()const
	{
		return column4.x;
	}

	real Mat4::e42()const
	{
		return column4.y;
	}

	real Mat4::e43()const
	{
		return column4.z;
	}

	real Mat4::e44()const
	{
		return column4.w;
	}

	Mat4& Mat4::set(const real& col1_x, const real& col1_y, const real& col1_z, const real& col1_w,
		const real& col2_x, const real& col2_y, const real& col2_z, const real& col2_w, const real& col3_x,
		const real& col3_y, const real& col3_z, const real& col3_w, const real& col4_x, const real& col4_y,
		const real& col4_z, const real& col4_w)
	{
		column1.set(col1_x, col1_y, col1_z, col1_w);
		column2.set(col2_x, col2_y, col2_z, col2_w);
		column3.set(col3_x, col3_y, col3_z, col3_w);
		column4.set(col4_x, col4_y, col4_z, col4_w);
		return *this;
	}

	Mat4& Mat4::set(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4)
	{
		column1.set(col1);
		column2.set(col2);
		column3.set(col3);
		column4.set(col4);
		return *this;
	}

	Mat4& Mat4::set(const Mat4& other)
	{
		column1.set(other.column1);
		column2.set(other.column2);
		column3.set(other.column3);
		column4.set(other.column4);
		return *this;
	}

	Mat4& Mat4::set(const Mat3& other)
	{
		column1.set(other.column1);
		column2.set(other.column2);
		column3.set(other.column3);
		column4.clear();
		return *this;
	}

	Mat4& Mat4::clear()
	{
		column1.clear();
		column2.clear();
		column3.clear();
		column4.clear();
		return *this;
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
		realSwap(column1.y, column2.x);
		realSwap(column1.z, column3.x);
		realSwap(column1.w, column4.x);

		realSwap(column2.z, column3.y);
		realSwap(column2.w, column4.y);

		realSwap(column3.w, column4.z);
		return *this;
	}

	Mat4& Mat4::invert()
	{
		invert(*this);
		return *this;
	}

	Mat4 Mat4::identityMatrix()
	{
		return {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1 };
	}

	Mat4 Mat4::multiply(const Mat4& lhs, const Mat4& rhs)
	{
		return { multiply(lhs, rhs.column1),
			multiply(lhs, rhs.column2),
			multiply(lhs, rhs.column3),
			multiply(lhs, rhs.column4) };
	}

	Vec4 Mat4::multiply(const Mat4& lhs, const Vec4& rhs)
	{
		return {
			lhs.column1.x * rhs.x + lhs.column2.x * rhs.y + lhs.column3.x * rhs.z + lhs.column4.x * rhs.w,
			lhs.column1.y * rhs.x + lhs.column2.y * rhs.y + lhs.column3.y * rhs.z + lhs.column4.y * rhs.w,
			lhs.column1.z * rhs.x + lhs.column2.z * rhs.y + lhs.column3.z * rhs.z + lhs.column4.z * rhs.w,
			lhs.column1.w * rhs.x + lhs.column2.w * rhs.y + lhs.column3.w * rhs.z + lhs.column4.w * rhs.w
		};
	}

	real Mat4::determinant(const Mat4& mat)
	{
		const real det11 = Mat3::determinant({
			mat.column2.y, mat.column2.z, mat.column2.w,
		mat.column3.y, mat.column3.z, mat.column3.w ,
		mat.column4.y, mat.column4.z, mat.column4.w });

		const real det21 = -Mat3::determinant({
			mat.column2.x, mat.column2.z, mat.column2.w,
		mat.column3.x, mat.column3.z, mat.column3.w ,
		mat.column4.x, mat.column4.z, mat.column4.w });

		const real det31 = Mat3::determinant({
			mat.column2.x, mat.column2.y, mat.column2.w,
		mat.column3.x, mat.column3.y, mat.column3.w ,
		mat.column4.x, mat.column4.y, mat.column4.w });

		const real det41 = -Mat3::determinant({
			mat.column2.x, mat.column2.y, mat.column2.z,
		mat.column3.x, mat.column3.y, mat.column3.z ,
		mat.column4.x, mat.column4.y, mat.column4.z });

		return mat.column1.x * det11 +
			mat.column1.y * det21 +
			mat.column1.z * det31 +
			mat.column1.w * det41;
	}

	bool Mat4::invert(Mat4& mat)
	{
		const real det = mat.determinant();
		if (realEqual(det, 0.0f))
			return false;

		const real det11 = Mat3::determinant(
			{ mat.e22(),mat.e23(),mat.e24(),
			mat.e32(),mat.e33(),mat.e34(),
			mat.e42(),mat.e43(),mat.e44() });

		const real det12 = -Mat3::determinant(
			{ mat.e12(),mat.e13(),mat.e14(),
			mat.e32(),mat.e33(),mat.e34(),
			mat.e42(),mat.e43(),mat.e44() });

		const real det13 = Mat3::determinant(
			{ mat.e12(),mat.e13(),mat.e14(),
			mat.e22(),mat.e23(),mat.e24(),
			mat.e42(),mat.e43(),mat.e44() });

		const real det14 = -Mat3::determinant(
			{ mat.e12(),mat.e13(),mat.e14(),
			mat.e22(),mat.e23(),mat.e24(),
			mat.e32(),mat.e33(),mat.e34() });


		const real det21 = -Mat3::determinant(
			{ mat.e21(),mat.e23(),mat.e24(),
			mat.e31(),mat.e33(),mat.e34(),
			mat.e41(),mat.e43(),mat.e44() });

		const real det22 = Mat3::determinant(
			{ mat.e11(),mat.e13(),mat.e14(),
			mat.e31(),mat.e33(),mat.e34(),
			mat.e41(),mat.e43(),mat.e44() });

		const real det23 = -Mat3::determinant(
			{ mat.e11(),mat.e13(),mat.e24(),
			mat.e21(),mat.e23(),mat.e24(),
			mat.e41(),mat.e43(),mat.e44() });

		const real det24 = Mat3::determinant(
			{ mat.e11(),mat.e13(),mat.e14(),
			mat.e21(),mat.e23(),mat.e24(),
			mat.e31(),mat.e33(),mat.e34() });


		const real det31 = Mat3::determinant(
			{ mat.e21(),mat.e22(),mat.e24(),
			mat.e31(),mat.e32(),mat.e34(),
			mat.e41(),mat.e42(),mat.e44() });

		const real det32 = -Mat3::determinant(
			{ mat.e11(),mat.e12(),mat.e14(),
			mat.e31(),mat.e32(),mat.e34(),
			mat.e41(),mat.e42(),mat.e44() });

		const real det33 = Mat3::determinant(
			{ mat.e11(),mat.e12(),mat.e14(),
			mat.e21(),mat.e22(),mat.e24(),
			mat.e41(),mat.e42(),mat.e44() });

		const real det34 = -Mat3::determinant(
			{ mat.e11(),mat.e12(),mat.e14(),
			mat.e21(),mat.e22(),mat.e24(),
			mat.e31(),mat.e32(),mat.e34() });


		const real det41 = -Mat3::determinant(
			{ mat.e21(),mat.e22(),mat.e23(),
			mat.e31(),mat.e32(),mat.e33(),
			mat.e41(),mat.e42(),mat.e43() });

		const real det42 = Mat3::determinant(
			{ mat.e11(),mat.e12(),mat.e13(),
			mat.e31(),mat.e32(),mat.e33(),
			mat.e41(),mat.e42(),mat.e43() });

		const real det43 = -Mat3::determinant(
			{ mat.e11(),mat.e12(),mat.e13(),
			mat.e21(),mat.e22(),mat.e23(),
			mat.e41(),mat.e42(),mat.e43() });

		const real det44 = Mat3::determinant(
			{ mat.e11(),mat.e12(),mat.e13(),
			mat.e21(),mat.e22(),mat.e23(),
			mat.e31(),mat.e32(),mat.e33() });

		mat.set(det11, det12, det13, det14,
			det21, det22, det23, det24,
			det31, det32, det33, det34,
			det41, det42, det43, det44);

		mat /= det;
		return true;

	}
}
