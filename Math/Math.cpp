


#include <iostream>

#include "include/vec4.h"
#include "formatter.h"
using namespace std;

using namespace Math;
int main()
{
	Mat2 a, b;
	a.set(1, 2, 3, 4);
	b.set(5, 6, 7, 8);
	
	spdlog::info("a:{}, b:{}", a, b);
	spdlog::info("a mul b :{}", a.multiply(b));
	return 0;
}
