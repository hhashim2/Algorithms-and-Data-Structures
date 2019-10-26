/*
Algorithm and Data Structures
Homework#3
Huzaifa Hashim
hhashim@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int recursiveFib(int);
long long bottomupFib(int);
long long closedformFib(int);
long long Matrixfib(int n);

int main()
{
    std::srand(std::time(0));
    double duration1, duration2, duration3, duration4;
    long long int number;
    cout << "Please enter a positive number: ";
    cin >> number;

    /*clock_t start = clock();
    cout << "recursive = " << recursiveFib(number) << endl;
    duration1 = (clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\nRun time of naive recursive = " << duration1 << std::endl;
    */

    clock_t start1 = clock();
    cout << "\nBottom Up = " << bottomupFib(number) << endl;
    duration2 = (clock() - start1) / (double) CLOCKS_PER_SEC;
    std::cout << "Run time of bottom up = " << duration2 << std::endl;

    clock_t start2 = clock();
    closedformFib(number);
    duration3 = (clock() - start2) / (double) CLOCKS_PER_SEC;
    std::cout << "Run time of closed form = " << duration3 << std::endl;

    clock_t start3 = clock();
    cout << "\nMatrix Form = " << Matrixfib(number) << endl;
    duration4 = (clock() - start3) / (double) CLOCKS_PER_SEC;
    std::cout << "Run time of matrix multiplication = " << duration4 << std::endl;
}

int recursiveFib(int x)
{
    if (x < 2)
        return x;

    else
        return (recursiveFib(x - 1) + recursiveFib(x - 2));
}

long long int bottomupFib(int n)
{
	if(n <= 1)
		return n;

	long long int previousFib = 0, currentFib = 1;
	for(int i = 0; i < n - 1; i++)
	{
        long long int newFib =  previousFib + currentFib;
		previousFib = currentFib;
		currentFib = newFib;
	}

	return currentFib;
}


long long int closedformFib(int n)
{
    double x = (1 + sqrt(5))/2;
    cout << "\nClosed Form = " << ((pow(x, n) - pow(1 - x, n))/sqrt(5)) << endl;
    return 0;
}

long long Matrixfib(int n)
{
    long long fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j]);
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j]);
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1]);
}
