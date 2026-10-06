#include "Algorithms.h"

#include "framework.h"


int Algorithms::BubbleSort(int* toSort, int arraySize)
{
    int lastSortedIndex = arraySize;
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

int Algorithms::SelectionSort(int* toSort, int arraySize)
{
    int steps = 0;
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (toSort[i] > toSort[j])
                Utils::Swap(toSort, i, j);
            steps++;
        }
    }
    return steps;
}

int Algorithms::InsertionSort(int* toSort, int arraySize)
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
                if (currentChecked == arraySize - 1)
                    sorted = true;
            }
        }
        if (directionCheck == -1)
        {
            if (currentChecked == 0 || toSort[currentChecked] >= toSort[currentChecked - 1])
            {
                directionCheck = 1;
                currentChecked = furtherIndex;
                if (furtherIndex == arraySize - 1)
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
