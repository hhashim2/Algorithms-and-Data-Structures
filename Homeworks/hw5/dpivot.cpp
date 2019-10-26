#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high, int* s)
{
    if(arr[low] > arr[high])
        swap(arr[high], arr[low]);


    int i = low + 1;
    int j = high + 1;
    int k = low + 1;
    int ptr_left = arr[low];
    int ptr_right = arr[high];

    while( k <= j)
    {
        if(arr[k] < ptr_left)
            swap(arr[k], arr[i]);

        else if(arr[k] >= ptr_right)
        {
            while(arr[j] > ptr_right && k < j)
                j--;

            swap(arr[k], arr[j]);
            j--;

            if(arr[k] < ptr_left)
            {
                swap(arr[k], arr[i]);
                i++;
            }
        }
        k++;
    }
    i++;
    j++;

    swap(arr[low], arr[i]);
    swap(arr[high], arr[j]);

    *s = i;
    return j;
}

void quick_Sort(int arr[], int low, int high)
{
    int left_pivot;
    int right_pivot;

    if(low < high)
    {
        right_pivot = partition(arr, low, high, &left_pivot);
        quick_Sort(arr, low, left_pivot - 1);
        quick_Sort(arr, left_pivot + 1, right_pivot - 1);
        quick_Sort(arr, right_pivot + 1, high);
    }
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
    int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
	int size = sizeof(a) / sizeof(int);
	//printarr(a, size);
	quick_Sort(a, 0, size - 1);
	//printarr(a, size);
	return 0;
}
