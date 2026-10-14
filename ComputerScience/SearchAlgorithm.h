#pragma once

#include <vector>

namespace SearchAlgo
{
	int LinearSearch(std::vector<int> vec, int value);
	int BinarySearch(std::vector<int>& vec, int value,int begin = 0, int size = -1);
	int JumpSearch(std::vector<int> vec, int value);
	int FibonnaciSearch(std::vector<int> vec, int value);
}

