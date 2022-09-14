#pragma once
#include <string>
#include <functional>

bool Bigger(int a, int b);
bool compare(int a, int b, std::function<bool(int, int)> compareFunc);