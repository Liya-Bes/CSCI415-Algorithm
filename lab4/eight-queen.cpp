#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

vector<int> col;
int solutions =0;

bool safeToPlace(int columns)
{
    int row = col.size();

    for(int i = 0; i<row; i++)
    {
        if(col[i] == columns)
        {
            return false;
        }
        if(row-i == columns-col[i] || row - i == col[i] - columns)
        {
            return false;
        }
    }
    return true;
}

void solvePlacement(int row)
{
    //if all 8 of them are placed
    if(row == N)
    {
        solutions++;
        cout << "Solution " << solutions << ":" << endl;

        for(int i =0; i<N;i++)
        {
            for(int j=0; j<N; j++)
            {
                if(col[i] ==j)
                {
                    cout << " Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout<< endl;
        }
        cout << endl;
        return;
    }
    //try the column
    for(int column=0; column < N; column++)
    {
        if(!safeToPlace(column))
        {
            continue;
        }
        col.push_back(column);//place the queen 
        solvePlacement(row+1); //move to next row
        col.pop_back();
    }
}

int main()
{
    solvePlacement(0);
    cout << "total sol " << solutions << endl;
    return 0;
}