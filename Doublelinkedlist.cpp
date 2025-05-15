#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int noMhs;
    Node *next;
    Node *previous;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        //step 1
        Node *newNode = new Node();

        //step 2: assign value to the data fields
        newNode->noMhs = nim;

        //step 3: insert at beginning if list is empty or nim is smalles
        if (START == NULL || nim <= START->noMhs)
        {
            cout <<"\nDuplicate number not allowed" << endl;
            return;
        }
        //step 4: newNode.next + start
        newNode->next = START;
    }
};