#pragma once

namespace Utils
{
	void Swap(int* table, int firstIndex, int secondIndex);
	int* CreateRandomList(int listSize);
	int* CreateSortedAscendingList(int listSize);
	int* CreateSortedDescendingList(int listSize);

	void PrintTable(int* table, int size);
}