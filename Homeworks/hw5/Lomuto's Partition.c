/**
    Algorithms and Data Structures
    Homework 5
    Huzaifa Hashim
    Hoare's Partition Algorithm
    Referenced from geeksforgeeks.org
**/

#include <iostream>
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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i]) << endl;
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
