#include "utilities.h"
#include <iostream>

bool Bigger(int a, int b)
{
	return a < b;
}

bool compare(int a, int b, std::function<bool(int, int)> compareFunc)
{
	return compareFunc(a, b);
}
