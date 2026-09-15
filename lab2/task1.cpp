#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    srand(time(0));

    int num[10];
    for(int i =0; i < 10; i++)
    {
        num[i] = rand() % 41 -20;// generate the number b/n -20 & 20
        cout << num[i] << " " ;
    }
    cout << endl;

    int targetNum = 1000;
    cout << "Target Number: " << targetNum << endl;
    
    
    bool isFound = false;
    //time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int combination = 0; combination < 1024; combination++)//1024 based on the formula
    {
        int sum =0; 
        for (int i =0; i<10; i++)
        {
            if(combination & (1 << i))
            {
                sum = sum + num[i];
            }
        }

        
        if(sum == targetNum)
        {
            //cout << "Subset is found " << sum << endl;
            isFound = true;
        }   
            
    }

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    
    if(isFound == true)
    {
        cout << "subset found" << endl;
    }
    else
    {
        cout << "No subset" << endl;
    }

    cout << "Time in Sec: " << elapsed.count() << endl;
    //cout << endl;
    return 0;
}