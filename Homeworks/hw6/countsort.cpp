/**
    Algorithms and Data Structures
    Homework 6
    Huzaifa Hashim
    Count Sort
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector <int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;

	vector<int> count(range), output(arr.size());
	for(int i = 0; i < arr.size(); i++)
		count[arr[i]-min]++;

	for(int i = 1; i < count.size(); i++)
		count[i] += count[i-1];

	for(int i = arr.size()-1; i >= 0; i--)
	{
		output[ count[arr[i]-min] -1 ] = arr[i];
			count[arr[i]-min]--;
	}

	for(int i=0; i < arr.size(); i++)
			arr[i] = output[i];
}

void printArray(vector <int> & arr)
{
	for (int i=0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	vector <int> arr = {9, 1, 6, 7, 6, 2, 1};
	cout << "Input Array = ";
	printArray(arr);
	countSort(arr);
	cout << "Sorted Array = ";
	printArray(arr);
	return 0;
}
