
#include "framework.h"
#include "Algorithms.h"
#include <iostream>

int main()
{
	srand(404);
	int arraySize = 100;
	int* table = Utils::CreateSortedAscendingList(arraySize);

	std::cout << "Choosen Algo : Merge Sort\n";

	std::cout << "Before Sorting\n";
	Utils::PrintTable(table, arraySize);
	std::cout << "\n";

	int steps = Algorithms::MergeSort(table, arraySize);
	std::cout << "After Sorting\n";
	Utils::PrintTable(table, arraySize);
	std::cout << "Steps Count : " << steps;



	return 1;
}