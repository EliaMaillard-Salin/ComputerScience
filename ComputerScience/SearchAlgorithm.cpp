#include "SearchAlgorithm.h"
#include <cmath>

int SearchAlgo::LinearSearch(std::vector<int> vec,int value)
{
    for (int i = 0; i < vec.size();i++)
    {
        if (value == vec[i])
            return i;
    }
    return -1;
}

int SearchAlgo::BinarySearch(std::vector<int>& vec, int value, int begin, int size)
{
    if (size == -1)
        size = vec.size();

    if (size == 1 && vec[begin] != value)
        return -1;

    int halfSize = std::ceil(size * 0.5f);
    int halfIndex = begin + halfSize;
    if (vec[halfIndex] == value)
        return halfIndex;

    if (vec[halfIndex] < value)
        return BinarySearch(vec, value, halfIndex, halfSize);
    if (vec[halfIndex] > value)
        return BinarySearch(vec, value, begin, halfSize);

    return -1;
}

int SearchAlgo::JumpSearch(std::vector<int> vec, int value)
{
    int jumpValue = std::sqrt(vec.size());

    bool availableTiles = true;
    int currentIndex = 0;
    int highestIndex = 0;
    while (availableTiles)
    {
        currentIndex += jumpValue;

        if (currentIndex >= vec.size() || currentIndex == highestIndex )
            return -1;

        if (vec[currentIndex] < value)
        {
            highestIndex = currentIndex;
            continue;
        }

        if (vec[currentIndex] == value)
            return currentIndex;

        if (vec[currentIndex] > value)
        {
            if (currentIndex == 0)
                return -1;
            highestIndex = currentIndex;
            currentIndex -= (jumpValue + 1);
            jumpValue = 1;
        }
    }

    return -1;
}

int SearchAlgo::FibonnaciSearch(std::vector<int> vec, int value)
{
    int mMinus2 = 0;
    int mMinus1 = 1;
    int m = mMinus2 + mMinus1;
    while (m < vec.size())
    {
        mMinus2 = mMinus1;
        mMinus1 = m;
        m = mMinus2 + mMinus1;
    }
    m = m - mMinus1;
    mMinus1 = mMinus1 - mMinus2;
    mMinus2 = m - mMinus1;
    
    int offset = m;
    int pivot = 0;
    int maxPivot = 0;
    int minPivot = 0;
    while (true)
    {
        pivot += offset;
        
        if (vec[pivot] == value)
            return pivot;

        if (value < vec[pivot])
        {
            if (pivot == minPivot)
                return -1;

            maxPivot = pivot;
            if (pivot == 0)
                return -1;
            pivot -= offset;
            offset = mMinus2;
        }
        else
        {
            if (pivot == maxPivot)
                return -1;

            minPivot = pivot;
            if (pivot >= vec.size())
                return -1;
            offset = mMinus1;
        }

        m = std::min(1,m - mMinus1);
        mMinus1 = std::min(1,mMinus1 - mMinus2);
        mMinus2 = std::min(0,m - mMinus1);


    }
    return -1;
}
