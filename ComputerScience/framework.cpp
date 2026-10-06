#include "framework.h"
#include <iostream>

void Utils::Swap(int* table, int firstIndex, int secondIndex)
{
	int a = table[firstIndex];
	table[firstIndex] = table[secondIndex];
	table[secondIndex] = a;
}

int* Utils::CreateRandomList(int listSize)
{
	int* table = new int[listSize];
	for (int i = 0; i < listSize; i++)
	{
		table[i] = rand() % listSize;
	}
	return table;
}

int* Utils::CreateSortedAscendingList(int listSize)
{
	int* table = new int[listSize];
	for (int i = 0; i < listSize; i++)
	{
		table[i] = i+1;
	}
	return table;
}

int* Utils::CreateSortedDescendingList(int listSize)
{
	int* table = new int[listSize];
	for (int i = 0; i < listSize; i++)
	{
		table[i] = listSize - i;
	}
	return table;
}

void Utils::PrintTable(int* table, int size)
{
	std::cout << "[";
	for (int i = 0; i < size; i++)
	{
		std::cout << table[i];
		if (i < size - 1)
			std::cout << ", ";
	}
	std::cout << "]\n";
}
