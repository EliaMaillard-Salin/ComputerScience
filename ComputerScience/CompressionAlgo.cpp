#include "CompressionAlgo.h"

#include <map>
#include <list>
#include <fstream>
#include "framework.h"
std::vector<char> COmpressionAlgo::Huffman(std::string toCompress)
{
    std::map<char, int> occurences = {};
    for (char c : toCompress)
    {
        occurences[c] += 1;
    }
    std::list<TreeNode*> unlinkedNodeTree = {};
    std::map<char, TreeNode*> binaryTreeAssociated = {};
    for (auto it : occurences)
    {
        TreeNode* node = new TreeNode(true);
        node->value = it.second;
        node->name = it.first;
        unlinkedNodeTree.push_back(node);
        binaryTreeAssociated[it.first] = node;
    }
    TreeNode* pRoot = nullptr;
    while(!unlinkedNodeTree.empty())
    {
        TreeNode* pFirstNode = nullptr;
        TreeNode* pSecondNode = nullptr;
        for (TreeNode* pNode : unlinkedNodeTree)
        {
            if (pFirstNode == nullptr)
            {
                pFirstNode = pNode;
                continue;
            }
            if (pSecondNode == nullptr)
            {
                pSecondNode = pNode;
                continue;
            }
            if (pNode->value < pFirstNode->value)
            {
                pFirstNode = pNode;
                continue;
            }
            if (pNode->value < pSecondNode->value)
            {
                pSecondNode = pNode;
                continue;
            }
        }
        if (pSecondNode == nullptr)
        {
            unlinkedNodeTree.remove(pFirstNode);
            pFirstNode->name = "ROOT";
            pRoot = pFirstNode;
            continue;
        }

        TreeNode* newRoot = new TreeNode(true);
        newRoot->value = pFirstNode->value + pSecondNode->value;
        newRoot->left = pFirstNode; pFirstNode->onLeft = true;
        newRoot->right = pSecondNode; pSecondNode->onLeft = false;
        pFirstNode->pParent = newRoot; pSecondNode->pParent = newRoot;
        unlinkedNodeTree.remove(pFirstNode); unlinkedNodeTree.remove(pSecondNode);
        unlinkedNodeTree.push_back(newRoot);
    }
    std::vector<char> res = {};
    for (char c : toCompress)
    {
        int offset = 1;
        std::list<char> cValue = {};
        TreeNode* pN = binaryTreeAssociated[c];

        while(pN != pRoot)
        {
            TreeNode* pParent = pN->pParent;
            cValue.push_front((pN == pParent->left ? 0 : 1));
            offset *= 2;
            pN = pParent;
        }
        res.insert(res.end() ,cValue.begin(), cValue.end());
    }
    return res;
}

void COmpressionAlgo::CompressFile(std::vector<char>& txt, std::string path)
{
    std::string filename{ path };
    std::fstream s{ filename, s.binary | s.trunc | s.in | s.out };

    s.is_open();
    s.write(reinterpret_cast<char*>(txt.data()), txt.size());
}
