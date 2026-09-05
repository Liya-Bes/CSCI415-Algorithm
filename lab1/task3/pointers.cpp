#include <iostream>

using namespace std;

class Node
{
    public:
        int *space;
        int size;

        Node(int s[], int a)
        {
            size = a;
            space = new int[a];
            for (int i = 0; i < a; i++)
                space[i] = s[i];
        }

        //our copy constructor
        Node(const Node &other)
        {
            size = other.size;
            space = new int[size];
            for (int i = 0; i < size; i++)
                space[i] = other.space[i];
        }

        //b. printing node
        friend ostream& operator<<(ostream& output, const Node& n)
        {
            for (int i = 0; i < n.size; i++)
            {
                output << n.space[i] << " ";
            }
            return output;
        }

};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6};
    Node test1(t, sizeof(t)/4), test2(test1);
    test1.space[2] = 7;
    cout << test2.space[2] << endl;

    //test
    cout << test1 << endl;
    cout << test2 << endl;

    cin.ignore();
}