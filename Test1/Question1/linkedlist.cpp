#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef>

using namespace std;

class node
{
public:
    int info;
    node *next;

    node()
    {
        next = NULL;
    }

    node(int data)
    {
        info = data;
        next = NULL;
    }
};

class list
{
public:
    node *head, *tail;

    list()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insert(int data)
    {
        node *p = new node(data);
        if (isEmpty())
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    void reverse()
    {
        // Implement this method
        node *before = NULL;
        node *current = head;
        node *nextNode;

        tail = head;

        //while we still have node we will reverse
        while(current != NULL)
        {//10->20->30->null
            nextNode = current->next;//next node is 20->30->null
            current->next = before;
            before = current;
            current = nextNode;
        }

        head = before;
    }

    friend ostream &operator<<(ostream &out, const list &l)
    {
        // Implement this method
        node* current = l.head;

        while(current != NULL)
        {
            out << current-> info << " ";
            current = current->next;
        }
        return out;
        
    }
};

list list1, list2, list3, list4;

void Setup()
{
    int len1 = rand() % 100 + 1;
    int len2 = rand() % 100 + 1;
    int len3 = rand() % 100 + 1;

    // list1 and list2 are supposd to be different
    for (int i = 0; i < len1; i++)
        list1.insert(rand() % 100);
    for (int i = 0; i < len2; i++)
        list2.insert(rand() % 100);

    // For your convenience, list3 and list4 are the same
        for (int i = 0; i < len3; i++)
    {
    int num = rand() % 100;//create one num and assign instead of generating new for both so it can be the same
    
        list3.insert(num);
        list4.insert(num);
    }
}

bool Test(list l1, list l2)
{
    // Implement this method
    //lets creeate pointer
    node *p1List = l1.head;
    node *p2List = l2.head;

    //so while it not empty we compare
    while(p1List != NULL && p2List != NULL)
    {
        if(p1List->info != p2List->info)
        {
            return false; //they're not the same
        }
         p1List = p1List->next;
         p2List = p2List->next;
    }

    //ifthey ar same and empty
    if(p1List == NULL && p2List == NULL)
    {
        return true;
    }

    return false;
}

int main()
{

    srand(time(NULL));

    Setup();

    bool result = Test(list1, list2);

    cout << "List1:" << list1 << endl;
    cout << "List2:" << list2 << endl;
    if (result)
        cout << "They are the same\n";
    else
        cout << "They are not the same\n";

    result = Test(list3, list4);
    cout << "List3:" << list3 << endl;
    cout << "List4:" << list4 << endl;
    if (result)
        cout << "They are the same\n";
    else
        cout << "They are not the same\n";

    cout << "List3:" << list3 << endl;
    list3.reverse();
    cout << "List3 Reversed:" << list3 << endl;
}