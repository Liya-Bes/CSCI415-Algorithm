#include <iostream>

using namespace std;

int add(int *array, int size)
{
    int sum =0;
    for(int *i = array; i < array + size; i++)
    {//add the sum/current to next until we add everythign
        sum = sum + *i;
    }

    return sum;
}

int remove(int *array, int size)
{
    int *reader = array;
    int *placeEven = array;

    while(reader < array + size)
    {//keep going till end and check even
        if(*reader % 2 == 0)
        {
            *placeEven = *reader;
            placeEven++;
        }
        reader++;
    }

    return placeEven - array;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    cout << "Sum of numbers: " << add(numbers, size) << endl;
    size = remove(numbers, size);
    cout << "All even numbers: ";
    
    for (int *p = numbers; p < numbers + size; p++)
    {
        cout << *p << " ";
    }
    
    cout << endl;
    return 0;
}