#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstdlib>    //std::srand, std::rand
#include <ctime>
#define SIZE 100000
using namespace std;

int median( Type* array, int low, int high );

//quicksort
template<typename Type>
void quickSort1( Type* array, int low, int high )
{
  int pivotPosition;

	  if (low < high)
	  {
		  pivotPosition = median(array, low, high);
		  quickSort1(array, low, pivotPosition-1);
		  quickSort1(array, pivotPosition+1, high );
	  }

}

//swap
template< typename Type >
void swap( Type* array, int low, int high )
{
    Type temp;
    temp = array[low];
    array[low] = array[high];
    array[high] = temp;
}


int median( Type* array, int low, int high )
{
	int middle = (low+high)/2, upper = low, lower = high, temp;

	if ( array[low] > array[middle] )
		swap( array[middle], array[low] );
	if ( array[low] > array[high] )
		swap( array[low], array[high] );
	if ( array[middle] > array[high] )
		swap( array[high], array[middle] );

	swap(array[middle], array[low]);

	return partition(array, low, high);
}

template< typename Type >
const Type &partition( Type* array, int low, int high )
{
  int left, right;
  Type pivot;

  left = low;
  right = high;
  pivot = array[low];

  while ( left < right )
  {
    while ( array[right] > pivot )
      right--;

    while ( (left < right) && (array[left] <= pivot) )
      left++;

    if ( left < right )
     swap(array[left], array[right] );
  }

  array[low] = array[right];
  array[right] = pivot;

  return right;
}

void populateArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = ( std::rand() % 100000 ) + 1;
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
    double duration1, duration2, duration3;
    populateArray(arr, ARRAY_SIZE);

    quickSort1(arr, 0, ARRAY_SIZE);

}
