/**
    Algorithms and Data Structures
    Homework 5
    Huzaifa Hashim
    Dual Pivot
    Referenced from geeksforgeeks.org
**/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int* arr, int low, int high, int* lp);

void DualPivotQuickSort(int* arr, int low, int high)
{
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partition(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}

int partition(int* arr, int low, int high, int* lp)
{
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {

        // if elements are less than the left pivot
        if (arr[k] < p) {
            swap(arr[k], arr[j]);
            j++;
        }

        // if elements are greater than or equal
        // to the right pivot
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            swap(arr[k], arr[g]);
            g--;
            if (arr[k] < p) {
                swap(arr[k], arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    swap(arr[low], arr[j]);
    swap(arr[high], arr[g]);

    *lp = j;
    return g;
}

// Driver code
int main()
{
    int arr[] = { 24, 8, 42, 75, 29, 77, 38, 57 };
    DualPivotQuickSort(arr, 0, 7);
    printf("Sorted array: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
