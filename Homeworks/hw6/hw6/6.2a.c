/**
    Algorithms and Data Structures
    Homework 6
    Huzaifa Hashim
    MSB Radix Sort
    Referenced from UT Arlington Lecture on Radix Sort
**/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int bits_per_item = sizeof(int) * 8;

int Bits(int number, int bit)
{
    int result = number >> bit;
    result = result & 1;
    return result;
}

void print_array(int *A, int length)
{
    int counter;
    for (counter = 0; counter < length; counter++)
        printf("%2d: %d\n", counter, A[counter]);

  printf("\n");
}

void RadixSort(int *items, int left, int right, int *scratch, int bit)
{
    if (left >= right) return;
    if (bit < 0) return;

    int counts[2];
    int indices[2];

    int i;
    counts[0] = 0;
    counts[1] = 0;

    for (i = left; i <= right; i++)
    {
        int binary = Bits(items[i], bit);
        counts[binary]++;
    }

    indices[0] = left;
    indices[1] = indices[0] + counts[0];

    for (i = left; i <= right; i++)
    {
        int binary = Bits(items[i], bit);
        int index = indices[binary];
        scratch[index] = items[i];
        indices[binary]++;
    }

    for (i = left; i <= right; i++)
        items[i] = scratch[i];

    int temp_left = left;
    for (i = 0; i < 2; i++)
    {
        int temp_right = temp_left + counts[i] - 1;
        RadixSort(items, temp_left, temp_right, scratch, bit-1);
        temp_left = temp_right + 1;
    }
}


void radixsortMSB(int *items, int length)
{
    int *scratch = malloc(sizeof(int) * length);

    RadixSort(items, 0, length -1, scratch, bits_per_item - 1);
    free(scratch);
}

int main()
{
    int A[] = {4, 93, 5, 104, 53, 90, 208};

    printf("size of int: %d\n\n", sizeof(int));

    printf("before radix sort:\n");
    print_array(A, 7);

    radixsortMSB(A, 7);

    printf("after radix sort:\n");
    print_array(A, 7);
    return 0;
}
