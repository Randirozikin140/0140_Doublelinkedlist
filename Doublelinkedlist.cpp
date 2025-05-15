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

        //step 5: START.PREV = newNode (if START Exists)
        if(START != NULL)
            START->previous = newNode;
        
        //step 6:
        newNode->previous = NULL;

        //step 7: 
        START = newNode;
        return;


        //insert to between node
        //step 8: Locate position for insertion
        Node *current = START;
        while((current->next != NULL && current->next->noMhs < nim))
        {
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate number not allowed" << endl;
            return;
        }

        //step 9: insert between current and current ->next
        newNode->next = current->next; // Step 9a: newNode.next = current.next
        newNode->previous = current;   // Step 9b: newNode.previous = current

        //insert last node
        if (current->next != NULL)
            current->next->previous = newNode; // Step 9c: current.next.previous = newNode

            
    }

    void hapus()
    {
        if(START == NULL)
        {
            cout <<"\nMasukkan NIM yang akan didelete";
            int rollNo;
            cin >> rollNo;

            Node *current = START;

            //step 1: Tranverse the list to find the mode 
            while (current != NULL && current->noMhs != rollNo)
            {
                current = current->next;
            }
            if(current == NULL)
            {
                cout << "Record not found" << endl;
                return;
            }
            //step 2: if node is at the beginning
            if (current == START)
            {
                START = current->next; // Step 2a: START = current.next
                if (START != NULL)
                {
                    START->previous = NULL; // Step 2b: START.previous = NULL
                }
            }
            
        }
    }
};