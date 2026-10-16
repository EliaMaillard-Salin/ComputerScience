#pragma once
#include <string>
#include <vector>
#include "TreeNode.h"

namespace Utils
{
	void Swap(std::vector<int>& toSwap, int firstIndex, int secondIndex);
	std::vector<int> CreateRandomList(int listSize);
	std::vector<int> CreateSortedAscendingList(int listSize);
	std::vector<int> CreateSortedDescendingList(int listSize);

	TreeNode* ConstructTreeFromList(std::vector<int> table);
	void SwapValuesInTree(TreeNode* value1, TreeNode* value2);
	void PrintTable(std::vector<int> table);
	void PrintBinaryTree(TreeNode* tree);
	void PrintNodeTree(TreeNode* node);
}