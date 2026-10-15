#include <iostream>

using namespace std;
int digits[9] ={0};

bool safe(int num)
{
    for(int i =0; i < 9; i++)
    {
        if(digits[i] == num)
        {
            return false;
        }
    }
    return true;
}

void checkEquation()
{
    double A = digits[0];
    double B = digits[1];
    double C = digits[2];
    double D = digits[3];
    double E = digits[4];
    double F = digits[5];
    double G = digits[6];
    double H = digits[7];
    double I = digits[8];
    double result = A /B*C+D*E*F/G+H*I;

    if(result > 99.9999 && result < 100.0001)
    {
    //print each number a-i
            std::cout<< A << " / " << B << " * " << C << " + " << D << " * " << E<< " * " << F
                << " / " << G << " + " << H << " * " << I << " = " << result << endl;
        std::cout << std::endl;
    }
}

void solve(int index)
{
    if(index == 9)
    {
        checkEquation();
        return;
    }
    for(int num = 1; num <= 9; num++)
    {
        if(safe(num))
        {
            digits[index] = num;//choose
            solve(index + 1);//explore
            digits[index] = 0;//unchoose
        }
    }
}

int main()
{
    solve(0);
    return 0;
}