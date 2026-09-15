#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    long num = rand() % 900000 + 100000;
    long divisor =0;
    bool isPrime = true;
    int count = 0;

    srand(time(0));

    for(divisor = 2; divisor * divisor <= num; divisor++)
    {
        count++; 
        //cout << "Testing: " << divisor << endl;
        if(num % divisor == 0)
        {
            isPrime = false;
            break;
        }
    }

    cout << "Number: " << num << endl;
    cout << "Amount of Tests done: " << count << endl;
    
    if(!isPrime)
        cout << "Not Prime" << endl;
    else 
        cout << "Prime" << endl;
    

    return 0;
}