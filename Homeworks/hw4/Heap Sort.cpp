 /*
CH08-320201
Algorithms and Data Structures
Homework 4
Huzaifa Hashim
h.hashim@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
void heapSort(int arr[], int n);
void maxHeapify(int arr[], int n, int i);
void printArray(int arr[], int n);

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }

    //printArray(arr, n);
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2*i;
    int r = 2*i + 1;

    if (leftChild < n && arr[i] > arr[largest])
        largest = leftChild;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
    //printArray(arr, n);
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    std::srand(std::time(0));
    double number;
    cout << "Please enter a positive number: ";
    cin >> number;
    double duration1;
    int ARRAY_SIZE = number;
    int arr[ARRAY_SIZE];
    //printArray(arr, number);

    clock_t start = clock();
    heapSort(arr, number);
    clock_t stop = clock();
    //printArray(arr, ARRAY_SIZE);
    duration1 = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Run time for size " << number << " is = " << duration1;

    cout << "\nSorted array is \n\n";
    printArray(arr, number);
}
