#pragma once
#include <string>
#include <vector>

struct BinaryNodeTree
{
	int value;
	BinaryNodeTree* left = nullptr;
	BinaryNodeTree* right = nullptr;
	BinaryNodeTree* root = nullptr;
	std::string name = "";
};

namespace Utils
{
	void Swap(std::vector<int>& toSwap, int firstIndex, int secondIndex);
	std::vector<int> CreateRandomList(int listSize);
	std::vector<int> CreateSortedAscendingList(int listSize);
	std::vector<int> CreateSortedDescendingList(int listSize);

	BinaryNodeTree* ConstructTreeFromList(int* table, int listSize);
	void SwapValuesInTree(BinaryNodeTree* value1, BinaryNodeTree* value2);
	void PrintTable(std::vector<int> table);
	void PrintBinaryTree(BinaryNodeTree* tree);
	void PrintNodeTree(BinaryNodeTree* node);
}