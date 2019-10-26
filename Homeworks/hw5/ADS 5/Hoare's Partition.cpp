/**
    Algorithms and Data Structures
    Homework 5
    Huzaifa Hashim
    Hoare's Partition Algorithm
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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
}

void populateArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = ( std::rand() % 1000 ) + 1;
    }
}

// Driver program to test above functions
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
    double duration1;
    populateArray(arr, ARRAY_SIZE);
    //printArray(arr, ARRAY_SIZE);
    clock_t start = clock();
    for(int i = 0; i < 100000; i++)
    {
        //printArray(arr, ARRAY_SIZE);
        quickSort(arr, 0, ARRAY_SIZE);
    }

    duration1 = (clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\nRun time = " << duration1 << std::endl;

}

