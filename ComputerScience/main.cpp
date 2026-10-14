
#include "framework.h"
#include "SortAlgorithms.h"
#include "SearchAlgorithm.h"
#include <iostream>
#include <time.h>

int main()
{
	srand(404);

	//for (int i = 1; i < 5; i++)
	//{
	//	int arraySize = std::pow(10,i);
	//	std::vector<int> table = Utils::CreateRandomList(arraySize);

	//	std::cout << "Choosen Algo : QuickSort \n";
	//	std::time_t timeBefore = std::time(nullptr);
	//	int steps = SortAlgorithms::QuickSort(table);
	//	std::time_t timeAfter = std::time(nullptr);
	//	std::cout << "Time Taken : " << timeAfter - timeBefore << " seconds, for "  << std::to_string(arraySize) << " elements\n";
	//	std::cout << "Steps Count : " << steps;
	//	std::cout << "\n\n ";
	//}

	//int arraySize = 10000;
	//std::vector<int> table = Utils::CreateRandomList(arraySize);

	//std::cout << "Choosen Algo : QuickSort Sort\n";
	//std::time_t timeBefore = std::time(nullptr);
	//int steps = SortSortAlgorithms::QuickSort(table);
	//std::time_t timeAfter = std::time(nullptr);
	//Utils::PrintTable(table);
	//std::cout << "Time Taken : " << timeAfter - timeBefore << " seconds, for " << std::to_string(arraySize) << " elements\n";
	//std::cout << "Steps Count : " << steps;
	//std::cout << "\n\n ";


	int arraySize = 10000;
	std::vector<int> table = Utils::CreateSortedAscendingList(arraySize);

	std::cout << "Array Size : " << std::to_string(arraySize) << "\n";
	std::clock_t linearStart = std::clock();
	int resLinear = SearchAlgo::LinearSearch(table,150);
	std::clock_t linearEnd = std::clock();
	std::cout << "LinearSearch returned " << resLinear << " in : " << std::to_string(((double)linearEnd - linearStart) / CLOCKS_PER_SEC) << " seconds \n";

	std::clock_t binaryStart = std::clock();
	int resBinary = SearchAlgo::BinarySearch(table,150);
	std::clock_t binaryEnd = std::clock();
	std::cout << "BinarySearch returned " << resBinary << " in : " << std::to_string(((double)binaryEnd - binaryStart) / CLOCKS_PER_SEC) << " seconds \n";

	std::clock_t jumpStart = std::clock();
	int resjump = SearchAlgo::JumpSearch(table,150);
	std::clock_t jumpEnd = std::clock();
	std::cout << "JumpSearch returned "   << resjump   << " in : " << std::to_string(((double)jumpEnd - jumpStart) / CLOCKS_PER_SEC) << " seconds \n";

	std::clock_t fibStart = std::clock();
	int resFib = SearchAlgo::FibonnaciSearch(table,150);
	std::clock_t fibEnd = std::clock();
	std::cout << "FibSearch returned "   << resFib   << " in : " << std::to_string(((double)fibEnd - fibStart) / CLOCKS_PER_SEC) << " seconds \n";

	return 1;
}