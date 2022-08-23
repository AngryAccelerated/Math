


#include <iostream>

#include "include/vec4.h"
#include "formatter.h"
using namespace std;

using namespace Math;
int main()
{
	Mat4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Mat4 m2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	//m.set(Mat4::identity());
	Mat2 a, b;
	a.set(1, 2, 3, 4);
	b.set(5, 6, 7, 8);
	Vec4 v(1, 2, 3, 4);
	spdlog::info("{}.multiply({}):{}", m1, v, m1.multiply(v));
	return 0;
}
