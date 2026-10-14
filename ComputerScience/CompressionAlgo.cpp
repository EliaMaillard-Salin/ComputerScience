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
    std::list<BinaryNodeTree*> unlinkedNodeTree = {};
    std::map<char, BinaryNodeTree*> binaryTreeAssociated = {};
    for (auto it : occurences)
    {
        BinaryNodeTree* node = new BinaryNodeTree();
        node->value = it.second;
        node->name = it.first;
        unlinkedNodeTree.push_back(node);
        binaryTreeAssociated[it.first] = node;
    }
    BinaryNodeTree* pRoot = nullptr;
    while(!unlinkedNodeTree.empty())
    {
        BinaryNodeTree* pFirstNode = nullptr;
        BinaryNodeTree* pSecondNode = nullptr;
        for (BinaryNodeTree* pNode : unlinkedNodeTree)
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

        BinaryNodeTree* newRoot = new BinaryNodeTree();
        newRoot->value = pFirstNode->value + pSecondNode->value;
        newRoot->left = pFirstNode; newRoot->right = pSecondNode;
        pFirstNode->root = newRoot; pSecondNode->root = newRoot;
        unlinkedNodeTree.remove(pFirstNode); unlinkedNodeTree.remove(pSecondNode);
        unlinkedNodeTree.push_back(newRoot);
    }
    std::vector<char> res = {};
    for (char c : toCompress)
    {
        int offset = 1;
        std::list<char> cValue = {};
        BinaryNodeTree* pN = binaryTreeAssociated[c];

        while(pN != pRoot)
        {
            BinaryNodeTree* pParent = pN->root;
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
