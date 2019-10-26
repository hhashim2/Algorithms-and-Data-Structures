/*
Algorithm and Data Structures
Homework#1
Huzaifa Hashim
hhashim@jacobs-university.de
*/

#include <iostream>   //std::cout
#include <algorithm>  //std::swap
#include <cstdlib>    //std::srand, std::rand
#include <ctime>      //std::time

void populateArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = ( std::rand() % 100000 ) + 1;
    }
}

void printArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void reverseArray(int arr[], std::size_t size)
{
   int temp;
   for (int i = 0; i < size / 2; ++i)
   {
      temp = arr[i];
      arr[i] = arr[size - i - 1];
      arr[size - i - 1] = temp;
    }
}

void selectionSort(int arr[], std::size_t size)
{
    for(int i = 0; i < (size - 1); ++i)
    {
        int mincount = i;
        for(int j = (i + 1); j < size; ++j)
        {
            if(arr[j] < arr[mincount])
                mincount = j;
        }
        if(mincount != i) std::swap(arr[i], arr[mincount]);
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
    double duration1, duration2, duration3;
    int ARRAY_SIZE = x;
    int arr[ARRAY_SIZE];

    //array populated with random numbers and printed
    populateArray(arr, ARRAY_SIZE);
    std::cout << "Random Array = \n";

    selectionSort(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);

    std::cout << "\nAlready Sorted array = \n";
    clock_t start1 = clock();
    selectionSort(arr, ARRAY_SIZE);
    duration2 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    //printArray(arr, ARRAY_SIZE);
    std::cout << "\nRun time of best case = " << duration2 << std::endl;
    std::cout << "\n";

    //clock function to calculate time
    /*
    clock_t start = clock();
    //selection sort algorithm for average case on a random
    //sequence of numbers
    selectionSort(arr, ARRAY_SIZE);
    duration1 = (clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\nRun time of average case = " << duration1 << std::endl;
    std::cout << "\nSorted array = \n";
    //printArray(arr, ARRAY_SIZE);
*/
    //selection sort algorithm on already sorted array for best case


    //sequence reversed for worst case
    reverseArray(arr, ARRAY_SIZE);
    clock_t start2 = clock();
    selectionSort(arr, ARRAY_SIZE);
    duration3 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    //printArray(arr, ARRAY_SIZE);
    std::cout << "\nRun time of worst case = " << duration3 << std::endl;
    std::cout << "\n";

    return 0;
}
