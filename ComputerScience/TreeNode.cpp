#include "TreeNode.h"
#include "framework.h"

TreeNode* TreeNode::LastLeaf = nullptr;

TreeNode::TreeNode(bool _onLeft):
    onLeft(_onLeft)
{
}

TreeNode::~TreeNode()
{
    if (pParent != nullptr)
    {
        if (onLeft)
            pParent->left = nullptr;
        else
            pParent->right = nullptr;
    }
}

int TreeNode::SortNode()
{
    int steps = 0;

    if (right == nullptr && left == nullptr)
    {
        LastLeaf = this;
    }

    if (right != nullptr)
        steps += right->SortNode();
    if (left != nullptr)
        steps += left->SortNode();

    if (right != nullptr && value < right->value)
    {
        Utils::SwapValuesInTree(this, right);
        steps++;
    }
    if (left != nullptr && value < left->value)
    {
        Utils::SwapValuesInTree(this, left);
        steps++;
    }
    return steps;
}
