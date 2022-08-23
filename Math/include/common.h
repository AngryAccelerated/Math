#ifndef MATH_COMMON_H
#define MATH_COMMON_H

#include <cmath>
#include <cfloat>
#include <algorithm>
#include <cassert>
#include <xmmintrin.h>
#include <intrin.h>
#include <immintrin.h>

#define MATH_USE_SIMD

namespace Math
{
	using real = float;
	namespace Constant
	{
		const real Eps = 1e-5f;

		const real HalfPi = std::atan(1.0f) * 2.0f;
		const real Pi = std::atan(1.0f) * 4.0f;
		const real TwoPi = std::atan(1.0f) * 8.0f;
		const real InvPi = 1.0f / Pi;

		const real Rad2Deg = 180.0f / Pi;
		const real Deg2Rad = Pi / 180.0f;

		const real PosInfty = FLT_MAX;
		const real PosZero = FLT_MIN;

		const real NegInfty = -FLT_MAX;
		const real NegZero = -FLT_MIN;

	}
}

#endif