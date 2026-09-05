#include <iostream>

using namespace std;

template <class genType>
void mySwap(genType &el1, genType &e12)
{
    genType temp = el1;
    el1 = e12;
    e12 = temp;
}

int main()
{
    double n = 2;
    double m = 3;
    double x = 10.5;
    double y = 2.7;

    cout << "Before Swapping: " << endl;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    mySwap(n, m);

    cout << "After Swapping: " << endl;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    cout << "Before Swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    mySwap(n, m);

    cout << "After Swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cin.ignore();
    return 0;
}