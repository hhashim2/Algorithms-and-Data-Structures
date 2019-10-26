 /*
CH08-320201
Algorithms and Data Structures
Homework 4
Heap Sort Variant
Huzaifa Hashim
h.hashim@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i;
    int r = 2*i + 1;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively maxHeapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        cout << arr[i];


        */// call  maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);*/
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    std::srand(std::time(0));
    //double duration1, duration2, duration3, duration4;
    int number;
    cout << "Please enter a positive number: ";
    cin >> number;

    int ARRAY_SIZE = number;
    int arr[ARRAY_SIZE];
    heapSort(arr, number);

    cout << "Sorted array is \n";
    printArray(arr, number);


}
