#include "framework.h"
#include <iostream>
#include <string>
#include <queue>

void Utils::Swap(std::vector<int>& table, int firstIndex, int secondIndex)
{
	int a = table[firstIndex];
	table[firstIndex] = table[secondIndex];
	table[secondIndex] = a;
}

std::vector<int> Utils::CreateRandomList(int listSize)
{
	std::vector<int> newVec = std::vector<int>(listSize);
	for (int i = 0; i < listSize; i++)
	{
		newVec[i] = rand() % listSize;
	}
	return newVec;
}

std::vector<int> Utils::CreateSortedAscendingList(int listSize)
{
	std::vector<int> newVec = std::vector<int>(listSize);
	for (int i = 0; i < listSize; i++)
	{
		newVec[i] = i+1;
	}
	return newVec;
}

std::vector<int> Utils::CreateSortedDescendingList(int listSize)
{
	std::vector<int> newVec = std::vector<int>(listSize);
	for (int i = 0; i < listSize; i++)
	{
		newVec[i] = listSize - i;
	}
	return newVec;
}

BinaryNodeTree* Utils::ConstructTreeFromList(int* table, int listSize)
{
	BinaryNodeTree* root = new BinaryNodeTree();
	
	for (int i = 0; i < listSize; i++)
	{
		BinaryNodeTree* currentNode = root;
		if (i == 0) {
			currentNode->value = table[0];
			currentNode->root = nullptr;
			currentNode->name = "Root";
			continue;
		}

		std::queue<BinaryNodeTree*> nextNodes = {};
		nextNodes.push(currentNode);

		while (!nextNodes.empty()) {
			currentNode = nextNodes.front();
			nextNodes.pop();

			if (currentNode->left == nullptr) {
				currentNode->left = new BinaryNodeTree();
				currentNode->left->root = currentNode;
				currentNode->left->value = table[i];
				currentNode->left->name = std::to_string(i);
				break;
			}
			else {
				nextNodes.push(currentNode->left);
			}

			if (currentNode->right == nullptr) {
				currentNode->right = new BinaryNodeTree();
				currentNode->right->root = currentNode;
				currentNode->right->value = table[i];
				currentNode->right->name = std::to_string(i);
				break;
			}
			else {
				nextNodes.push(currentNode->right);
			}
		}
	}
	return root;
}

void Utils::SwapValuesInTree(BinaryNodeTree* value1, BinaryNodeTree* value2)
{
	int a = value1->value;
	value1->value = value2->value;
	value2->value = a;
}


void Utils::PrintTable(std::vector<int> table)
{
	std::cout << "[";
	for (int i = 0; i < table.size(); i++)
	{
		std::cout << table[i];
		if (i < table.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]\n";
}

void Utils::PrintBinaryTree(BinaryNodeTree* tree)
{
	BinaryNodeTree* currentNode = tree;

	std::queue<BinaryNodeTree*> nextNodes = {};
	nextNodes.push(currentNode);
	std::cout << "Tree :\n";
	std::cout << "[";
	int count = 0;
	int offset = 1;
	while (!nextNodes.empty()) {
		currentNode = nextNodes.front();
		nextNodes.pop();
		std::string parentStr = "Parent :";
		if (currentNode->root != nullptr)
			parentStr += currentNode->root->name;
		std::cout << "(Node:" + currentNode->name <<", " << parentStr << ", " << currentNode->value << ")";

		count++;
		if (currentNode->left != nullptr) {
			nextNodes.push(currentNode->left);
		}
		if (currentNode->right != nullptr) {
			nextNodes.push(currentNode->right);
		}
		if (count == offset)
		{
			std::cout << "]\n";
			count = 0;
			offset *= 2;
			std::cout << "[";
		}

		if (count % 2 == 0 && count != 0)
		{
			std::cout << "], [";
		}
		else if (count != 0)
			std::cout << ",";
	}
	count++;
	for (; count < offset; count++)
	{
		if (count % 2 == 0 && count != 0)
		{
			std::cout << "], [";
		}
		else if (count != 0)
			std::cout << ",";
	}
	std::cout << "]\n";
}

void Utils::PrintNodeTree(BinaryNodeTree* node)
{
	if (node->left != nullptr)
		PrintNodeTree(node->left);
	if (node->right != nullptr)
		PrintNodeTree(node->right);
}
