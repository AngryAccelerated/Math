#ifndef MATH_FLOAT2_H
#define MATH_FLOAT2_H

#include "common.h"
namespace Math
{
	union float2
	{
		__m64 data;
		float num[2];
	};

	inline float2Add();

	inline float2Mul();
	
}
#endif // !MATH_FLOAT2_H
