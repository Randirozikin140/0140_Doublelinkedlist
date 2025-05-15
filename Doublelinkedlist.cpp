#include <iostream>
#include <string>
using namespace std;

//
//
//

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
};