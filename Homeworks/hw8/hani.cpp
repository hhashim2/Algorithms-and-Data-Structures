#include <iostream>
#include <cmath>
using namespace std;

computeCone(int rad, int height)
{

    return 1/3 * 3.1426 * rad * rad * height;
}

computeHemisphere(int rad)
{

    return 2/3 * 3.1426 * rad * rad * rad;
}


int main()
{
    int x, y, a, b;
    cout << "enter height1";
    cin >> x;

    cout << "enter rad1";
    cin >> a;
    cout << "enter rad2";
    cin >> b;

    cout << "cone:\n";
    computeCone(a, x);
    cout << "sphere:\n";
    computeHemisphere(b);

}
