#include <iostream>
#include <stack> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string addNums(string num1, string num2)
{
    stack<int> a;
    stack<int> b;
    stack<int> result;

    for(int i =0; i < num1.length(); i++)
    {
        a.push(num1[i]-'0');
    }

    for(int i =0; i < num2.length(); i++)
    {
        b.push(num2[i]-'0');
    }

    int carry = 0;

    while(!a.empty() || !b.empty() || carry)
    {
        int x = 0;
        int y = 0;

        if(!a.empty())
        {
            x = a.top();
            a.pop();
        }

        if(!b.empty())
        {
            y = b.top();
            b.pop();
        }

        int sum = x+y+carry;
        result.push(sum % 10);
        carry = sum / 10;
    }

    string answer = "";

    while(!result.empty())
    {
        answer = answer + char('0' + result.top());
        result.pop();
    }
    return answer;

}

int main()
{
    srand(time(0));
    string numbers[10];

    for(int i = 0; i < 10; i++)
    {
        numbers[i] = "";
        numbers[i] = numbers[i] + char('1' + rand() % 9);

        for (int j=1; j < 16; j++)
        {
            numbers[i] += char('0' + rand() % 10);
        }

        cout << numbers[i] << endl;
    }

    string num1 = numbers[0];

    for(int i = 1; i < 10; i++)
    {
        string num2 = numbers[i];

        cout << "Number 1: " << num1 << endl;
        cout << "Number 2: " << num2 << endl;

        string sum = addNums(num1, num2);
        cout << "Sum of the nums: " << sum << endl;
        num1 = sum;
    }
    return 0;
}