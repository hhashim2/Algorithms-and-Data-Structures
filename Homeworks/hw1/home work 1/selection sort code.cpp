/*By Farzan Ali Khan
Code for selction sort(example with an array)*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
using namespace std;
int main(void) {
    int i,j,minimum,length,number,index =0,temp,change = 0,random_number;
    srand ( static_cast < unsigned int >( time (0)));
    double duration;
    length = 10;//change for varying number of n
    cout<<"the number of elements are "<<length<<endl;
    int arr[length];
    for (i=0;i<length;i++){
        random_number = (rand()%1000) + 1;//get random number from 1 to 1000
        number=random_number;
        arr[i] = number;//assign number to the array
    }
    //code for printing the array
    cout<<"the unsorted array is:"<<endl;
    for (i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
    /*sorting using selection sort begins*/
    clock_t Start = clock();//start clock for average case
    for (i=0;i<length;i++){//loop to untill the end of the array
        minimum = arr[i];//assign the current member as the minimum
        index = 0;
        change = 0;
        for (j = i + 1;j<length;j++){//loop through the array to find the smallest value
            if (arr[j] < minimum){
                minimum = arr[j];
                index = j;
                change = 1;//variable that tells if there is a change
            }
        }
        if (change == 1){//swap the smallest with the current value if the current is not the minimum
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

        }
    }

    duration = clock() - Start/(double) CLOCKS_PER_SEC;//stop clock

    /*Print sorted array*/
    cout<<"sorted array is:"<<endl;
    for (i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
    //the sorted array is taken as the best case
    /*sorting begins on best case*/
    clock_t Start1 = clock();//start clock for best case
    for (i=0;i<length;i++){
        minimum = arr[i];
        index = 0;
        change = 0;
        for (j = i + 1;j<length;j++){
            if (arr[j] < minimum){
                minimum = arr[j];
                index = j;
                change = 1;
            }
        }
        if (change == 1){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

        }
    }
    clock_t duration2 = clock() - Start1/(double) CLOCKS_PER_SEC;

    //reverse the sorted array to get the worst case
    for (i = 0; i < length/2; ++i) {
    temp = arr[length-i-1];
    arr[length-i-1] = arr[i];
    arr[i] = temp;
    }
    //print the worst case
    cout<<"worst case array"<<endl;
    for (i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
    clock_t Start2 = clock();//start clock for worst case
    for (i=0;i<length;i++){
        minimum = arr[i];
        index = 0;
        change = 0;
        for (j = i + 1;j<length;j++){
            if (arr[j] < minimum){
                minimum = arr[j];
                index = j;
                change = 1;
            }
        }
        if (change == 1){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

        }
    }
    clock_t duration3 = clock() - Start2/(double) CLOCKS_PER_SEC;
    cout<<"Time taken for best case: "<<duration<<" ms"<<endl;
    cout<<"Time taken for average case: "<<duration2<<" ms"<<endl;
    cout<<"Time taken for worst case: "<<duration3<<" ms"<<endl;
}


