#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_LEVEL = 7;
const int MAX_NODES = 128;

class Node{
    public:
        int number;
        int height;
        Node* next[7];
};

class SkipList
{
private:
    Node* head; 

public: 
    int number;
    int height;
    Node* next[7];

    SkipList()
    {//we'll create the new node to uses head
        head = new Node;
        head->height = MAX_LEVEL;

        for(int i=0; i < MAX_LEVEL; i++)
        {
            head->next[i] = nullptr;
        }
    }

    //
    int chooseRandomLevel()
    {
        int level =1;
        while(level < MAX_LEVEL && rand() %2 ==0)
            level++;//we keep increasing while the random resul is 0 and stop when it reaches 7
        
        return level;
    }

    void insert(int num)
    {//choose the height f the node
        int level = chooseRandomLevel();

        cout << "Number: " << num << endl;
        cout << "Level: " << level << endl;

        Node* newNode = new Node;
        newNode->number = num;
        newNode->height = level;

        for(int i =0; i < MAX_LEVEL; i++)
        {
            newNode->next[i] = nullptr;
        }

        Node* current = head;//then we connect the level 

        for(int i = MAX_LEVEL-1; i >=0; i--)
        {
            while(current->next[i] != nullptr && current->next[i]->number < num)
            {
                current = current ->next[i];
                
            }
            if(i <level)
                {
                    newNode-> next[i] = current->next[i];
                    current->next[i] =newNode;
                }
        }

    }

    void printLevel()
    {
        for(int i = MAX_LEVEL-1; i>=0; i--)
        {
            cout << "Level " << i + 1 << ": ";

            Node* current = head->next[i];

            while(current !=nullptr)
            {
                cout << current->number << " ";
                current = current->next[i];
            }

            cout << endl;

        }
    }

};






int main()
{
    SkipList list;
    
    int count = 0;
    int numbs[MAX_NODES];

    while (count < MAX_NODES)
    {//generate 128 num
        int number = rand() % 1000 +1;
        bool duplicate = false;

        for(int i=0; i<count; i++)
        {
            if(numbs[i] == number)
            {
                duplicate= true;
            }
        }
        if(duplicate == false)
        {
            numbs[count] = number;
            count++;

            list.insert(number);
        }
    }
    cout << "\n SKIP LIST \n";
    list.printLevel();

    return 0;
}