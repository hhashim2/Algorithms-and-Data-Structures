/**
    Algorithms and Data Structures
    Homework 5
    Huzaifa Hashim
    Lomuto and Hoare's Partition Algorithm
    Referenced from geeksforgeeks.org
**/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstdlib>    //std::srand, std::rand
#include <ctime>
#define SIZE 100000
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void LquickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        LquickSort(arr, low, pi - 1);
        LquickSort(arr, pi + 1, high);
    }
}

int Hpartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met.
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void HquickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Hpartition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        HquickSort(arr, low, pi);
        HquickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
}

void populateArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = ( std::rand() % 100000 ) + 1;
    }
}

int main()
{
    //random number generator seed
    std::srand(std::time(0));
    int x;

    //user input for size of randomly generated array
    std::cout << "Enter size of randomized array = ";
    std::cin >> x;

    //double duration;
    int ARRAY_SIZE = x;
    int arr[ARRAY_SIZE];
    double duration1, duration2, duration3;
    populateArray(arr, ARRAY_SIZE);
    //printArray(arr, ARRAY_SIZE);
    clock_t start = clock();
    for(int i = 0; i <= 100000; i++)
    {
        printArray(arr, ARRAY_SIZE);
        LquickSort(arr, 0, ARRAY_SIZE);
    }

    duration1 = (clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\nRun time for Lomuto = " << duration1 << std::endl;

    clock_t start1 = clock();
    for(int i = 0; i <= 100000; i++)
    {
        printArray(arr, ARRAY_SIZE);
        HquickSort(arr, 0, ARRAY_SIZE);
        printArray(arr, ARRAY_SIZE);
    }

    duration2 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    std::cout << "\nRun time for Hoare = " << duration1 << std::endl;

}


