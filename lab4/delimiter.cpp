#include <iostream>
#include <stack> 
#include <string>

using namespace std;


bool delimiterMatch(string func)
{
    stack<char> delimiter;

    for (int i = 0; i < func.length(); i++)
    {
        if(func[i] == '(')
        {
            delimiter.push('(');
        }
        else if (func[i] == ')')//if closing char
        {
            if(delimiter.empty())
            {
                return false;
            }
            delimiter.pop();
        }
    }

    return delimiter.empty();//if completly emty 
}


int main()
{
    //1 test
    if(delimiterMatch("(x+b)"))
    {
        cout << "(x+b): true" << endl;
    }
    else
    {
        cout << "(x+b): false" << endl;
    }

    //2 test
    if(delimiterMatch("(a+b))"))
    {
        cout << "(a+b)): true" << endl;
    }
    else
    {
        cout << "(a+b)): false" << endl;
    }

    //3 test
    string userInput;
    cout << "Enter equation: ";
    getline(cin, userInput);

    if(delimiterMatch(userInput))
    {
        cout << "Delimiter matched " << endl;
    } 
    else
    {
        cout << "Delimiter didn't match" << endl;
    }
}



