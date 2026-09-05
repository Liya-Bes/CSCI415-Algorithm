#include <iostream>
#include <string> 
using namespace std;

template <class genType, int size = 50>
class genClass
{
    public:
        genType storage[size];

};

int main()
{
    genClass<int> intObject;
    genClass<float, 123> floatObject;

        for (int i = 0; i < 10; i++)
        {
            intObject.storage[i] = i + 1;
        }

        for (int i = 0; i < 20; i++)
        {
            floatObject.storage[i] = 1.0 + (i * 0.1);
        }

        for (int i = 0; i < 10; i++)
        {
            cout << intObject.storage[i] << endl;
        }

         for (int i = 0; i < 10; i++)
        {
            cout << floatObject.storage[i] << endl;
        }

    cin.ignore();
    return 0;
}