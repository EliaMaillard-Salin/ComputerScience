#pragma once

struct BinaryTree
{
	int value;
	bool isLeaf;
	BinaryTree* left;
	BinaryTree* right;
};


namespace Utils
{
	void Swap(int* table, int firstIndex, int secondIndex);
	int* CreateRandomList(int listSize);
	int* CreateSortedAscendingList(int listSize);
	int* CreateSortedDescendingList(int listSize);

	void PrintTable(int* table, int size);
}