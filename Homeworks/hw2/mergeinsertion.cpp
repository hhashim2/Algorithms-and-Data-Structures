/*
Algorithm and Data Structures
Homework#2
Huzaifa Hashim
hhashim@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>    //std::srand, std::rand
#include <ctime>      //std::time

void populateArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = ( std::rand() % 1000000000 ) + 1;
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

void sort(int arr[], int low, int high)
{
    //Insertion sort
    for (int i = low; i < high; i++)
    {
        for (int j = i - 1; j >= low; j--)
        {
            if (arr[i] < arr [j])
            {
                int holder = arr[j];
                arr[j] = arr[i];
                arr[i] = holder;
                i--;
            }
        }
    }
}
void merge(int arr[], int sub[], int low, int mid, int high)
{
    //Merge part of mergesort
    int a = low;
    int b = low;
    int c = mid;

    while ((a < mid) && (c < high))
    {
        if (arr[a] <= arr[c])
        {
            sub[b] = arr[a];
            a++;
        }

        else
        {
            sub[b] = arr[c];
            c++;
        }

        b++;
    }

    while(a == mid && c < high)
    {
        sub[b] = arr[c];
        c++;
        b++;
    }

    while(c == high && a < mid)
    {
        sub[b] = arr[a];
        a++;
        b++;
    }

    for (int d = low; d < high; d++)
        arr[d] = sub[d];
}

void split(int arr[], int sub[], int low, int high)
{
    //Split part of mergesort
    if (low < high - 1)
    {
        int mid = (low + high) / 2;
        split(arr, sub, low, mid);
        split(arr, sub, mid, high);
        if ((high - low) > 200)
        {
            //printf("%d\n%d\n%d\n", low, mid, high);
             sort(arr, low, high);
             //printf("used insertion\n");
        }

        else
        {
            merge(arr, sub, low, mid, high);
            //printf("used merge!\n");
        }
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
    int sub[ARRAY_SIZE];
    double duration1, duration2, duration3;

   //array populated with random numbers and printed
    populateArray(arr, ARRAY_SIZE);
    //printArray(arr, ARRAY_SIZE);
    clock_t start = clock();
    split(arr, sub, 0, ARRAY_SIZE);
    duration1 = (clock() - start) / (double) CLOCKS_PER_SEC;
    //printArray(arr, ARRAY_SIZE);
    std::cout << "\nRun time of average case = " << duration1 << std::endl;

    //printArray(arr, ARRAY_SIZE);

    clock_t start1 = clock();
    split(arr, sub, 0, ARRAY_SIZE);
    duration2 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    //printArray(arr, ARRAY_SIZE);
    std::cout << "\nRun time of best case = " << duration2 << std::endl;

    populateArray(arr, ARRAY_SIZE);
    split(arr, sub, 0, ARRAY_SIZE);
    //printArray(arr, ARRAY_SIZE);
    reverseArray(arr, ARRAY_SIZE);
    //printArray(arr, ARRAY_SIZE);

    clock_t start2 = clock();
    split(arr, sub, 0, ARRAY_SIZE);
    duration3 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    //printArray(arr, ARRAY_SIZE);
    std::cout << "\nRun time of worst case = " << duration3 << std::endl;

}
