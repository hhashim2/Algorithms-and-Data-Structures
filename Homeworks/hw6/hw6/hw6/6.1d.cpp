/**
    Algorithms and Data Structures
    Homework 6
    Huzaifa Hashim
    Sorting strings with radix sort
    length determined at runtime
    Used functions from StackOverflow
**/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

size_t Max(string arr[], int n)
{
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i].size() > max)
            max = arr[i].size();
    }

    return max;
}

void countSort(string a[], int size, size_t k)
{
    string *x = NULL;
    int *y = NULL;
    x = new string[size];
    y = new int[257];

    for (int i = 0; i <257; i++)
        y[i] = 0;

    for (int j = 0; j < size; j++)
        y[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;

    for (int k = 1; k <257; k++)
        y[k] += y[k - 1];

    for (int r = size - 1; r >= 0; r--)
    {
        x[y[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        y[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++)
        a[l] = x[l];

    delete[] x;
    delete[] y;
}


void radixSort(string b[], int r)
{
    size_t max = Max(b, r);

    for (size_t pos = max; pos > 0; pos--)
        countSort(b, r, pos - 1);
}

int main()
{
    string data[] = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};

    puts("Input String:");

    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        printf("%s, ", data[i].c_str());

    cout << "\n\n";
    radixSort(data, (int)(sizeof(data) / sizeof(data[0])));

    puts("Alphabetically sorted string:");

    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        printf("%s, ", data[i].c_str());

    cout << "\n\n";
    return 0;
}
