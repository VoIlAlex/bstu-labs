#include "pch.h"
#include <iostream>

struct SInput
{
	int A, B, C, D;
};
struct SOutput
{
	int X, Y, Z, R;
};

SOutput function(SInput input)
{
	int A = input.A;
	int B = input.B;
	int C = input.C;
	int D = input.D;
	int X, Y, Z, R;

	auto L1 = [=]() -> bool { return D > 6; };
	auto L2 = [=]() -> bool { return D > 2; };
	auto L3 = [=]() -> bool { return B > 5; };
	auto L4 = [=]() -> bool { return B == 4; };
	auto L5 = [=]() -> bool { return A < 6; };
	auto L6 = [=]() -> bool { return A > 10; };
	auto L7 = [=]() -> bool { return C == 9; };

	auto C1 = [&]() -> void { X = 31; Y = 31; Z = 31; R = 31; };
	auto C2 = [&]() -> void { X = 2 * X; };
	auto C3 = [&]() -> void { Y = 3 - Y; };
	auto C4 = [&]() -> void { X = R + Z; };
	auto C5 = [&]() -> void { R = 14; };
	auto C6 = [&]() -> void { R = -1; };


	C1();
	if (L1())
	{
		if (L2())
			if (!L3())
				C3();
	}
	else C2();
	if (!L4())
	{
		if (L5())
			C4();
		else
			if (L6());
			else C5();
	}
	if (L7())
		C6();

	return { X, Y, Z, R };
}

int main() {

	SInput input = { 10, 10, 10, 10 };

	SOutput output = function(input);



	

	printf("X: %d\nY: %d\nZ: %d\nR: %d\n", output.X, output.Y, output.Z, output.R);
	system("pause");
	return 0;
}