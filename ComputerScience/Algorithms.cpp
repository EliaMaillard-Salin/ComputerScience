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

int Algorithms::MergeSort(int* toSort, int arraySize)
{
    int steps = 0;
    int larraySize = arraySize / 2;
    int* leftArray = new int[larraySize];
    int rarraySize = arraySize - larraySize;
    int* rightArray = new int[rarraySize];

    int j = 0;
    for (int i = 0; i < larraySize; i++)
    {
        leftArray[i] = toSort[j++];
    }
    for (int i = 0; i < rarraySize; i++)
    {
        rightArray[i] = toSort[j++];
    }
    if (larraySize > 1)
    {
        steps+= MergeSort(leftArray, larraySize);
    }
    if (rarraySize > 1)
    {
        steps+= MergeSort(rightArray, rarraySize);
    }

    int r = 0;
    int i = 0;
    for (int l = 0; l < larraySize;l++)
    {
        if (r >= rarraySize || leftArray[l] < rightArray[r])
            toSort[i++] = leftArray[l];
        else
            toSort[i++] = rightArray[r++];
        steps++;
    }
    for (; r < rarraySize; r++)
    {
        toSort[i++] = rightArray[r++];
    }

    return steps;
}

int Algorithms::QuickSort(int* toSort, int arraySize)
{
    int steps = 0;
    int currentPivot = 0;
    int comparedPos = arraySize -1;

    int direction = -1;
    for (int j = 0; j < arraySize - 1; j++)
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

    int larraySize = currentPivot;
    int* leftArray = new int[larraySize];
    int rarraySize = arraySize - 1 - currentPivot;
    int* rightArray = new int[rarraySize];
    int j = 0;
    for (int i = 0; i < larraySize; i++)
    {
        leftArray[i] = toSort[j++];
    }
    j++;
    for (int i = 0; i < rarraySize; i++)
    {
        rightArray[i] = toSort[j++];
    }

    if (larraySize > 1)
    {
        steps += QuickSort(leftArray, larraySize);
    }
    if (rarraySize > 1)
    {
        steps += QuickSort(rightArray, rarraySize);
    }
    int i = 0;
    for (int l = 0; l < larraySize; l++)
    {
        toSort[i++] = leftArray[l];
    }
    i++;
    for (int r = 0; r < rarraySize; r++)
    {
        toSort[i++] = rightArray[r];
    }


    return steps;
}
