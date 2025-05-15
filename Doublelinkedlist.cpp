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
            else 
            {
                //step 3: link previous node to next node
                current->previous->next = current->next;

                //step 4: if current is not the last node
                if (current->next != NULL)
                current->next->previous = current->previous;
            }

            //step 5: delete the Node
            delete current;
            cout << "Record with roll number" << " rollno " << " delete" << endl;
        }
    }
    void treverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1: mark first node as current
        Node *currentNode = START;

        //step 2: repeat until currentNode == NULL
        cout << "i + 1 << " << currentNode->noMhs <<  endl;
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            //step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1: move to the last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        //step 2: Traverse backwards
        cout << i + 1 << "." << currentNode->noMhs << " " << endl; 
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            //step 3: Move to previous node
            currentNode = currentNode->previous;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        //step 1: traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        //step 2: output result
        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1.Add Record\n";
        cout << "2.Delete Record\n";
        cout << "3.view Ascending\n";
        cout << "4.view Descending\n";
        cout << "5.Search Record\n";
        cout << "Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.treverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "invalid option\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');  
}