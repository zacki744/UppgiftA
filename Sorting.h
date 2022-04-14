#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

//helperfunktions
extern "C" void swap(int* c, int* b)
{
    int* temp = c;
    *c = *b;
    *b = *c;
    delete temp;
}

template<typename T>
int partition(T arr[], int low, int high)
{
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= arr[high])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;

}

template<typename T>
void qslast(T arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = partition(arr, start, end);
    qslast(arr, start, pivot - 1);
    qslast(arr, pivot + 1, end);
}

template<typename T>
void qsMedian(T arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = medianPartitian(arr, start, end);
    qslast(arr, start, pivot - 1);
    qslast(arr, pivot + 1, end);
}

template<typename T>
static int medianPartitian(T arr[], int start, int end)
{
    int midle = (start + end) / 2;
    if (arr[start] > arr[end])
    {
        swap(arr[start], arr[end]);
    }
    if (arr[midle] > arr[end])
    {
        swap(arr[midle], arr[end]);
    }
    if (arr[midle] < arr[start])
    {
        swap(arr[midle], arr[end]);
    }

    swap(arr[midle], arr[end]);

    return partition(arr, start + 1, end);
}

template<typename T>
void heapify(T arr[], int n, int i, int d)
{
    int largest = i;

    for (int j = 1; j <= d; j++)
    {
        int childIndex = d * i + j;
        if (childIndex < n && arr[childIndex] > arr[largest])
            largest = childIndex;
    }
    if (arr[largest] != arr[i]) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, d);
    }
}

//assigment A functions

template<typename T>
void quicksortPivotLast(T arr[], int n) // using the first element as pivot
{
    qslast(arr, 0, n - 1);
}

template<typename T>
void quicksortPivotMedian(T arr[], int n) // median of first, middle and last element as 
{
    qsMedian(arr, 0, n -1);
}

template <typename T>
void heapsort(T arr[], int n, int d) // d represents he number of children in the maxheap 
{
    int incriment = 1;
    for (int i = n / d - incriment; i >= 0; i--)
    {
        heapify(arr, n, i, d);
        incriment++;
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, d);
    }
}
