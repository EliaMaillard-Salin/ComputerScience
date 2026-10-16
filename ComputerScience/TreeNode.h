#pragma once
#include <string>


class TreeNode
{
public:
	TreeNode(bool _onLeft);
	~TreeNode();
	int SortNode();

	static TreeNode* LastLeaf;

	int value = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode* pParent = nullptr;
	std::string name = "";
	bool onLeft;
};

