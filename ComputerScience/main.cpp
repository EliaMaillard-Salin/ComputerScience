
#include "framework.h"
#include "Algorithms.h"
#include <iostream>

int main()
{
	srand(404);
	int arraySize = 10;
	int* table = Utils::CreateSortedDescendingList(arraySize);

	std::cout << "Choosen Algo : InsertionSort\n";

	std::cout << "Before Sorting\n";
	Utils::PrintTable(table, arraySize);
	std::cout << "\n";

	int steps = Algorithms::InsertionSort(table, arraySize);
	std::cout << "After Sorting\n";
	Utils::PrintTable(table, arraySize);
	std::cout << "Steps Count : " << steps;



	return 1;
}