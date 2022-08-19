#ifndef MATH_FLOAT4_H
#define MATH_FLOAT4_H

#include "common.h"
namespace Math
{
	union float4
	{
		__m128 data;
		float num[4];
	};
}
#endif // !MATH_FLOAT4_H
