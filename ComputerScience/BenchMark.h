#pragma once

#include <vector>
#include <string>

class BenchMark
{
public:
	enum ListState
	{
		ASCENDING_SORTED,
		DESCENDING_SORTED,
		RANDOM,
	
	};

	std::vector<int> LaunchSortingAlgo(int size,ListState state);
	void LaunchSearchingAlgo(int size, int toFind, std::vector<int> customList = {});
	void LaunchHuffmanAlgo(std::string toCompress);

private:
	std::vector<int> CreateTable(ListState state, int size);
};

