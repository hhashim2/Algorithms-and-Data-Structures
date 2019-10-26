/**
    Algorithms and Data Structures
    Sorting (n^3 - 1) in linear time
    Logic is to change bases.
    If we set b as n, the value of O(logb(n)) becomes O(1)
    and overall time complexity becomes O(n).

    Huzaifa Hashim
**/

#include<iostream>
using namespace std;

int countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[n] ;
	for (int i=0; i < n; i++)
        count[i] = 0;

	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%n ]++;

	for (i = 1; i < n; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%n] - 1] = arr[i];
		count[(arr[i] / exp) % n]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}


//sorts arr[] of size n using Radix Sort
void sort(int arr[], int n)
{
	countSort(arr, n, 1);

	countSort(arr, n, n);

	countSort(arr, n, n*n);
}

// A utility function to print an array
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ", ";
}

int main()
{
	// Since array size is 7, elements should be from 0 to 343
	int arr[] = {40, 89, 190, 320, 303, 12, 342};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Given array is \n";
	printArr(arr, n);
    cout << "\n";
	sort(arr, n);

	cout << "\nSorted array is \n";
	printArr(arr, n);
	cout << "\n";
	return 0;
}
