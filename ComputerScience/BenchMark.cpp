#include "BenchMark.h"

#include "framework.h"
#include "SortAlgorithms.h"
#include "SearchAlgorithm.h"
#include "CompressionAlgo.h"
#include <iostream>
#include <time.h>

std::vector<int> BenchMark::LaunchSortingAlgo(int size, ListState state)
{
	int sortingArraySize = size;
	std::vector<int> toSortTable = {};


	std::cout << "Array Size : " << std::to_string(sortingArraySize) << "\n";

	toSortTable = CreateTable(state, size);
	std::clock_t bubbleStart = std::clock();
	int resBubble = SortAlgorithms::BubbleSort(toSortTable);
	std::clock_t bubbleEnd = std::clock();
	std::cout << "BubbleSort returned " << resBubble << " in : " << std::to_string(((double)bubbleEnd - bubbleStart) / CLOCKS_PER_SEC) << " seconds \n";

	toSortTable = CreateTable(state, size);
	std::clock_t SelectionStart = std::clock();
	int resSelection = SortAlgorithms::SelectionSort(toSortTable);
	std::clock_t SelectionEnd = std::clock();
	std::cout << "SelectionSort returned " << resSelection << " in : " << std::to_string(((double)SelectionEnd - SelectionStart) / CLOCKS_PER_SEC) << " seconds \n";

	toSortTable = CreateTable(state, size);
	std::clock_t InsertionStart = std::clock();
	int resInsertion = SortAlgorithms::InsertionSort(toSortTable);
	std::clock_t InsertionEnd = std::clock();
	std::cout << "InsertionSort returned " << resInsertion << " in : " << std::to_string(((double)InsertionEnd - InsertionStart) / CLOCKS_PER_SEC) << " seconds \n";

	toSortTable = CreateTable(state, size);
	std::clock_t QuickStart = std::clock();
	int resQuick = SortAlgorithms::QuickSort(toSortTable);
	std::clock_t QuickEnd = std::clock();
	std::cout << "QuickSort returned " << resQuick << " in : " << std::to_string(((double)QuickEnd - QuickStart) / CLOCKS_PER_SEC) << " seconds \n";

	toSortTable = CreateTable(state, size);
	std::clock_t MergeStart = std::clock();
	int resMerge = SortAlgorithms::MergeSort(toSortTable);
	std::clock_t MergeEnd = std::clock();
	std::cout << "MergeSort returned " << resMerge << " in : " << std::to_string(((double)MergeEnd - MergeStart) / CLOCKS_PER_SEC) << " seconds \n";

	toSortTable = CreateTable(state, size);
	std::clock_t HeapStart = std::clock();
	int resHeap = SortAlgorithms::HeapSort(toSortTable);
	std::clock_t HeapEnd = std::clock();
	std::cout << "HeapSort returned " << resHeap << " in : " << std::to_string(((double)HeapEnd - HeapStart) / CLOCKS_PER_SEC) << " seconds \n";
	std::cout << "\n" << std::endl;

	return toSortTable;
}

void BenchMark::LaunchSearchingAlgo(int size, int toFind, std::vector<int> customList)
{
	if (customList.empty())
		customList = Utils::CreateSortedAscendingList(size);
	int arraySize = size;

	std::cout << "Array Size : " << std::to_string(arraySize) << "\n";
	std::clock_t linearStart = std::clock();
	int resLinear = SearchAlgo::LinearSearch(customList, toFind);
	std::clock_t linearEnd = std::clock();
	std::cout << "LinearSearch returned " << resLinear << " in : " << std::to_string(((double)linearEnd - linearStart) / CLOCKS_PER_SEC) << " seconds \n";

	std::clock_t binaryStart = std::clock();
	int resBinary = SearchAlgo::BinarySearch(customList, toFind);
	std::clock_t binaryEnd = std::clock();
	std::cout << "BinarySearch returned " << resBinary << " in : " << std::to_string(((double)binaryEnd - binaryStart) / CLOCKS_PER_SEC) << " seconds \n";

	std::clock_t jumpStart = std::clock();
	int resjump = SearchAlgo::JumpSearch(customList, toFind);
	std::clock_t jumpEnd = std::clock();
	std::cout << "JumpSearch returned " << resjump << " in : " << std::to_string(((double)jumpEnd - jumpStart) / CLOCKS_PER_SEC) << " seconds \n";

	std::clock_t fibStart = std::clock();
	int resFib = SearchAlgo::FibonnaciSearch(customList, toFind);
	std::clock_t fibEnd = std::clock();
	std::cout << "FibSearch returned " << resFib << " in : " << std::to_string(((double)fibEnd - fibStart) / CLOCKS_PER_SEC) << " seconds \n";
	std::cout << "\n" << std::endl;
}

void BenchMark::LaunchHuffmanAlgo(std::string toCompress)
{
	std::clock_t huffStart = std::clock();
	std::vector<char> aa = COmpressionAlgo::Huffman(toCompress);
	std::clock_t huffEnd = std::clock();
	std::cout << "Huffman completed in :" << std::to_string(((double)huffEnd - huffStart) / CLOCKS_PER_SEC) << " seconds for :"<<  toCompress.size() <<" characters\n";

	COmpressionAlgo::CompressFile(aa, "Huff.bin");
}

std::vector<int> BenchMark::CreateTable(ListState state, int size)
{
	switch (state)
	{
	case BenchMark::ASCENDING_SORTED:
		return Utils::CreateSortedAscendingList(size);
		break;
	case BenchMark::DESCENDING_SORTED:
		return Utils::CreateSortedDescendingList(size);
		break;
	case BenchMark::RANDOM:
		return Utils::CreateRandomList(size);
		break;
	default:
		break;
	}
}
