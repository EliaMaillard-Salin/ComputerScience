#pragma once
#include "framework.h"
#include <vector>

namespace SortAlgorithms
{

	int BubbleSort(std::vector<int>& toSort);
	int SelectionSort(std::vector<int>& toSort);
	int InsertionSort(std::vector<int>& toSort);
	int MergeSort(std::vector<int>& toSort);
	int QuickSort(std::vector<int>& toSort, int first = 0, int last = -1);
	int HeapSort(std::vector<int> table);
};

