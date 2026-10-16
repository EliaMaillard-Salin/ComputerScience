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
                Utils::Swap(toSort, currentChecked, currentChecked + directionCheck);
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
                Utils::Swap(toSort, currentChecked, currentChecked - 1);
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

int SortAlgorithms::HeapSort(std::vector<int> table)
{
    int steps = 0;
    TreeNode* pRoot = Utils::ConstructTreeFromList(table);
    int furtherPos = -1;
    int lastIndex = table.size() - 1;
    
    while (lastIndex >= 0)
    {
        furtherPos = -1;
        steps += pRoot->SortNode();

        table[lastIndex--] = pRoot->value;
        pRoot->value = TreeNode::LastLeaf->value;
        delete TreeNode::LastLeaf;
    }
    return steps;
}
