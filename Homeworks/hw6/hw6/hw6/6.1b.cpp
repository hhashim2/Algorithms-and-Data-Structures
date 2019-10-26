/**
    Algorithms and Data Structures
    Homework 6
    Huzaifa Hashim
    Bucket Sort
    Code referenced from GeeksforGeeks
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{
	vector<float> b[n];
	for (int i = 0; i < n; i++)
	{
        int index = n * arr[i];
        b[index].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
	float arr[] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
	int n = sizeof(arr)/sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
	cout << arr[i] << ", ";
	return 0;
}
