#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


class Node{
    public:
        string text;
        Node* next;
};

class LineEditor
{
private:
    Node* head; 

public: 

    LineEditor()
    {//we'll create empty list
        head = nullptr;
    }

    void insert(int lineNumber, string text)
    {//

        Node* newNode = new Node;
        newNode->text = text;
        //newNode->next = nullptr;

        if(lineNumber == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        for(int i=1; i < lineNumber-1; i++)
        {
            if(current == nullptr)
            {
                return;
            }
            current = current->next;
        }

        if(current == nullptr)
        {
            return;
        }
        newNode->next = current->next;
        current->next = newNode;

    }

    void insertEnd(string text)
    {//

        Node* newNode = new Node;
        newNode->text = text;
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;

            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

    }

    void deleteLine(int lineNumber)
    {
        Node* current = head;

        if(head == nullptr)
        {
            return; 
        }

        if(lineNumber == 1)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 1; i< lineNumber-1; i++)
        {
            current = current->next;
        }

        if(current->next != nullptr)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void deleteRange(int start, int end)
    {
        for(int i = start; i<= end; i++)
        {
            deleteLine(start);
        }
    }

    void printList()
    { 

        //Node* current = head->next[i];
        Node* current = head;
        int lineNum = 1;

        while(current !=nullptr)
        {
            cout << lineNum << "> " << current->text << endl;
            current = current->next;
            lineNum++;
        }

        
    }

    void appendAfter(int lineNumber, string text)
    {
        if(head == nullptr)
        {
            insertEnd(text);
            return;
        }

        Node* current = head;

        for(int i=1; i<lineNumber; i++)
        {
            if(current == nullptr)
            {
                return;
            }
            current = current->next;
        }

        if(current == nullptr)
        {
            insertEnd(text);
            return;
        }

        Node* newNode = new Node;
        newNode->text = text;
        newNode->next = current->next;
        current->next = newNode;

    }

    void savingFile(string fileName)
    {
        ofstream file(fileName);
        
        Node* current = head;
        while(current != nullptr)
        {
            file << current->text << endl;
            current = current->next;
        }
        file.close();
    }

    void loadingFile(string fileName)
    {
        ifstream file(fileName);

        if(!file)
        {
            return;
        }
        string text;
        while(getline(file, text))
        {
            insertEnd(text);
        }
        file.close();
    }

};






int main()
{

    string fileName;
    string command;
    string text;
    int n;
    int m;
    int currentLine =1;

    cout << "Enter ";
    cin >> fileName;
    cin.ignore();

    LineEditor editFile;
    editFile.loadingFile(fileName);


    while(true)
    {
        cout << currentLine << "> ";
        getline(cin, command);

        stringstream input(command);
        char letter;
        input >> letter;

        if(letter == 'L')
        {
            editFile.printList();
        }
        else if(letter == 'I')
        {
            if(input >> n)
            {
                currentLine = n;
            }

            cout << currentLine << "> ";
            getline(cin, text);
            editFile.insert(currentLine, text);
        }
        else if(letter == 'D')
        {
            if(input >> n)
            {
                if(input >> m)
                    editFile.deleteRange(n, m);
                else
                    editFile.deleteLine(n);

                currentLine = n;
            }
            else
                editFile.deleteLine(currentLine);
        }
        else if(letter == 'A')
        {
            getline(cin, text);
            editFile.appendAfter(currentLine, text);
            currentLine++;
        }
        else if(letter == 'E')
        {
            editFile.savingFile(fileName);
            break;
        }

    }


    return 0;
}