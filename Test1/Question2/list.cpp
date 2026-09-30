#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef>
#include <fstream>

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

    int moveToFront(int data)
    {
        node *before = NULL;
        node *current = head;
        int comparisons =0;
        while(current != NULL)
        {
            comparisons++;
            if(current->info == data)
            {
                if(current==head)
                {
                    return comparisons;
                }
                if(current == tail)
                {
                    tail = before;
                }
                before->next = current->next;
                current->next = head;
                head = current;
                return comparisons;
            }

            /*if(current->info == data && current==head)
            {
                return;
            }*/
            
            before = current;
            current = current-> next;
        }
        insert(data);
        return comparisons;
    }

    int transpose(int data)
    {
        node *before = NULL;
        node *current = head;
        node *beforeBefore = NULL;
        int comparisons =0;

        while(current != NULL && current->info != data)
        {
            comparisons++;
            beforeBefore = before;
            before = current;
            current = current-> next;
            
        }
            //node *beforeBefore = head;
            if(current == NULL)
            {
                insert(data);
                return comparisons;
            }

            if(current == head)
            {
                return comparisons;
            }

           /*while(beforeBefore->next != current)
            {
                beforeBefore = beforeBefore->next;
            }*/ 
            if(current == tail)
            {
                tail = before;
            }

            if(beforeBefore== NULL)
            {
                head = current;
            }
            else
            {
                beforeBefore->next = current;
            }

        before->next = current->next;
        current->next = before;
        return comparisons;
    }

    void runFile(string filename)
    {
        ifstream file(filename);

        list moveToFrontList;
        list transposeList;
        long long moveToFront=0;
        long long transpose =0;
        int data;

        while(file >> data)
        {
            moveToFront += moveToFrontList.moveToFront(data);

        }

        file.close();
        file.open(filename);

        while(file >> data)
        {
            transpose += transposeList.transpose(data);
        }

        cout << endl;
        cout << filename << endl;
        cout << "Move to front: " << moveToFront << endl;
        cout << "Transpose: " << transpose << endl;
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
    list test;
    test.runFile("data1_trace.txt");
    test.runFile("data2_zipf.txt");
    test.runFile("data3_shift.txt");
    test.runFile("data4_uniform.txt");
    test.runFile("data5_burst.txt");
    
    return 0;
}