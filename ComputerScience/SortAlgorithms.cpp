#include "SortAlgorithms.h"

#include "framework.h"
#include <iostream>


int SortAlgorithms::BubbleSort(std::vector<int>& toSort)
{
    int lastSortedIndex = toSort.size();
    int steps = 0;
    while(lastSortedIndex != 0)
    {
        int i = 0;
        for (int j = i+1; j < lastSortedIndex; j++)
        {
            if (toSort[i] > toSort[j])
                Utils::Swap(toSort, i, j);
            i++;
            steps++;
        }
        lastSortedIndex--;
    }

    return steps;
}

int SortAlgorithms::SelectionSort(std::vector<int>& toSort)
{
    int steps = 0;
    for (int i = 0; i < toSort.size(); i++)
    {
        for (int j = i + 1; j < toSort.size(); j++)
        {
            if (toSort[i] > toSort[j])
                Utils::Swap(toSort, i, j);
            steps++;
        }
    }
    return steps;
}

int SortAlgorithms::InsertionSort(std::vector<int>& toSort)
{
    int steps = 0;
    int currentChecked = 0;
    int furtherIndex = 0;
    int directionCheck = 1;
    bool sorted = false;
    while (!sorted)
    {
        if (directionCheck == 1)
        {
            if (toSort[currentChecked] > toSort[currentChecked + 1])
            {
                //Utils::Swap(toSort, currentChecked, currentChecked + directionCheck);
                furtherIndex = currentChecked+directionCheck;
                directionCheck = -1;
            }
            else
            {
                currentChecked++;
                if (currentChecked == toSort.size() - 1)
                    sorted = true;
            }
        }
        if (directionCheck == -1)
        {
            if (currentChecked == 0 || toSort[currentChecked] >= toSort[currentChecked - 1])
            {
                directionCheck = 1;
                currentChecked = furtherIndex;
                if (furtherIndex == toSort.size() - 1)
                    sorted = true;
            }
            if (toSort[currentChecked] < toSort[currentChecked - 1])
            {
                //Utils::Swap(toSort, currentChecked, currentChecked - 1);
                currentChecked--;
            }
        }
        steps++;
    }


    return steps;
}

int SortAlgorithms::MergeSort(std::vector<int>& toSort)
{
    int steps = 0;
    int larraySize = toSort.size() / 2;
    int rarraySize = toSort.size() - larraySize;
    std::vector<int> left = std::vector<int>(toSort.begin(), toSort.begin() + larraySize);
    std::vector<int> right = std::vector<int>(toSort.begin() + larraySize, toSort.end());

    if (larraySize > 1)
        steps+= MergeSort(left);
    if (rarraySize > 1)
        steps+= MergeSort(right);

    int r = 0;
    int l = 0;
    for (int i = 0; i < toSort.size(); i++)
    {
        steps++;
        if (r >= rarraySize)
        {
            toSort[i] = left[l++];
            continue;
        }
        if (l >= larraySize)
        {
            toSort[i] = right[r++];
            continue;
        }

        if (left[l] < right[r])
            toSort[i] = left[l++];
        else
            toSort[i] = right[r++];
    }
    return steps;
}


int SortAlgorithms::QuickSort(std::vector<int>& toSort, int first, int last)
{
    int steps = 0;
    int currentPivot = first;
    int comparedPos = last-1;
    int arrayRange = last;

    if (last == -1)
    {
        comparedPos = toSort.size() - 1;
        arrayRange = toSort.size();
    }
    int direction = -1;

    for (int j = first; j < arrayRange; j++)
    {
        if (direction == -1)
        {
            if (toSort[currentPivot] > toSort[comparedPos])
            {
                Utils::Swap(toSort, currentPivot, comparedPos);
                int temp = currentPivot;
                currentPivot = comparedPos;
                comparedPos = temp;
                direction = 1;
            }
        }
        else if (direction == 1)
        {
            if (toSort[currentPivot] < toSort[comparedPos])
            {
                Utils::Swap(toSort, currentPivot, comparedPos);
                int temp = currentPivot;
                currentPivot = comparedPos;
                comparedPos = temp;
                direction = -1;
            }
        }
        comparedPos += direction;
        steps++;
    }
    if (currentPivot - first > 1)
    {
        steps += QuickSort(toSort, first,currentPivot);
    }
    if ((arrayRange)-(currentPivot) > 1)
    {
        steps += QuickSort(toSort, currentPivot+1, arrayRange);
    }

    return steps;
}

int SortAlgorithms::HeapSort(int* toSort, int arraySize)
{
    int steps = 0;
    BinaryNodeTree* pRoot = Utils::ConstructTreeFromList(toSort, arraySize);
    int furtherPos = -1;
    BinaryNodeTree* furthestNode = pRoot;
    int lastIndex = arraySize - 1;
    
    while (lastIndex >= 0)
    {
        furtherPos = -1;
        steps += InHeapSort(pRoot,furthestNode,furtherPos);

        toSort[lastIndex--] = pRoot->value;
        pRoot->value = furthestNode->value;

        if (furtherPos == 1)
            furthestNode->root->left = nullptr;
        else if (furtherPos == 0)
            furthestNode->root->right = nullptr;
        if (furtherPos != -1)
            delete furthestNode;
    }
    return steps;
}

int SortAlgorithms::InHeapSort(BinaryNodeTree* toSort, BinaryNodeTree*& furthest, int& furthestSide)
{
    int steps = 0;
    if (toSort->right != nullptr && (toSort->right->right == nullptr && toSort->right->left == nullptr))
    {
        furthest = toSort->right;
        furthestSide = 0;
    }
    if (toSort->left != nullptr && (toSort->left->right == nullptr && toSort->left->left == nullptr))
    {
        furthest = toSort->left;
        furthestSide = 1;
    }

    if (toSort->right != nullptr && (toSort->right->right != nullptr || toSort->right->left != nullptr))
        steps += InHeapSort(toSort->right,furthest, furthestSide);
    if (toSort->left != nullptr && (toSort->left->right != nullptr || toSort->left->left != nullptr))
        steps += InHeapSort(toSort->left, furthest, furthestSide);

    if (toSort->right != nullptr && toSort->value < toSort->right->value)
    {
        Utils::SwapValuesInTree(toSort, toSort->right);
        steps++;
    }
    if (toSort->left != nullptr &&  toSort->value < toSort->left->value)
    {
        Utils::SwapValuesInTree(toSort, toSort->left);
        steps++;
    }


    return steps;
}
