#ifndef MATH_FLOAT8_H
#define MATH_FLOAT8_H

#include "common.h"
namespace Math
{
	union float8
	{
		__m256 data;
		float f[8];
	};
}
#endif // !MATH_FLOAT8_H
