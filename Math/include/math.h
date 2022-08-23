#ifndef MATH_H
#define MATH_H
#include "common.h"
namespace Math
{
	//basic real utilities
	inline void realSwap(real& lhs, real& rhs)
	{
		const real temp = lhs;
		lhs = rhs;
		rhs = temp;
	}
	inline bool fuzzyRealEqual(const real& lhs, const real& rhs, const real& epsilon = Constant::Eps)
	{
		return std::fabs(lhs - rhs) < epsilon;
	}
	inline bool realEqual(const real& lhs, const real& rhs)
	{
		return fuzzyRealEqual(lhs, rhs);
	}
	inline void checkZero(const real& num)
	{
		assert(!realEqual(num, 0.0f));
	}
	inline real square(const real& x)
	{
		return x * x;
	}
	inline real cube(const real& x)
	{
		return x * x * x;
	}
	//trigonometric function
	inline real sinx(const real& x)
	{
		return std::sin(x);
	}
	inline real cosx(const real& x)
	{
		return std::cos(x);
	}
	inline real tanx(const real& x)
	{
		return std::tan(x);
	}
	inline real arcsinx(const real& x)
	{
		return std::asin(x);
	}
	inline real arccosx(const real& x)
	{
		return std::acos(x);
	}
	inline real arctanx(const real& y, const real& x)
	{
		return std::atan2(y, x);
	}
	inline real max(const real& a, const real& b)
	{
		return std::max(a, b);
	}
	inline real min(const real& a, const real& b)
	{
		return std::min(a, b);
	}
	inline real absMax(const real& a, const real& b)
	{
		return std::max(std::fabs(a), std::fabs(b));
	}
	inline real absMin(const real& a, const real& b)
	{
		return std::min(std::fabs(a), std::fabs(b));
	}
	inline real sqrt(const real& x)
	{
		return std::sqrt(x);
	}
	inline real pow(const real& x, const real& e)
	{
		return std::pow(x, e);
	}
	//other
	inline bool sameSign(const real& a, const real& b)
	{
		return a >= 0 && b >= 0 || a <= 0 && b <= 0;
	}
	inline bool sameSign(const real& a, const real& b, const real& c)
	{
		return a >= 0 && b >= 0 && c >= 0 || a <= 0 && b <= 0 && c <= 0;
	}
	inline int8_t sign(const real& num)
	{
		return num > 0 ? 1 : -1;
	}
	inline bool isInRange(const real& value, const real& low, const real& high, const real& epsilon = Constant::Eps)
	{
		return value >= low - epsilon && value <= high + epsilon;
	}
	inline bool fuzzyIsInRange(const real& value, const real& low, const real& high, const real& epsilon = Constant::Eps)
	{
		return value >= low - epsilon && value <= high + epsilon || value <= low + epsilon && low >= high - epsilon;
	}
	inline real clamp(const real& num, const real& low, const real& high)
	{
		return std::clamp(num, low, high);
	}
	inline size_t clamp(const size_t& num, const size_t& low, const size_t& high)
	{
		return std::min(std::max(num, low), high);
	}
	inline real degreeToRadian(const real& angle)
	{
		return angle * (Constant::Pi / 180.0f);
	}
	inline real radianToDegree(const real& radian)
	{
		return radian * (180.0f / Constant::Pi);
	}
	template <typename T, size_t iterations = 2> inline T fastInverseSqrt(T x) {
		typedef typename std::conditional<sizeof(T) == 8, std::int64_t, std::int32_t>::type Tint;
		T y = x;
		T x2 = y * 0.5f;
		Tint i = *(Tint*)&y;
		i = (sizeof(T) == 8 ? 0x5fe6eb50c7b537a9 : 0x5f3759df) - (i >> 1);
		y = *(T*)&i;
		for (size_t k = 0; k <= iterations; k++)
			y = y * (1.5f - (x2 * y * y));
		return y;
	}
}
#endif // !PHYS3D_MATH_H
