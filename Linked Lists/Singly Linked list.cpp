#include<iostream>
using namespace std;

//Singly Linked list using pointers
//  Handles only adding to Linked list and printing the array

class Node //Represents a node in the lINKED list
{
public:
    int data; //input
    Node* next; //pointer

    Node(int info, Node *ptr = 0) //sets the input data and pointer to respective variables
    {
           data = info;
           next = ptr;
    }
};

class SingleLinkedList //Singly Linked List
{
public:
    //CONSTRUCTOR
    SingleLinkedList() //Sets the Head and Tail of the List to NULL
    {
        head = tail = 0;
    }
    //DECONSTRUCTOR
    ~SingleLinkedList() //Sets the node pointer to the next node while deleting the node pointer
                            // Used to free up the space in memory used by the List
    {
        for(Node *p; !isEmpty();)
        {
            p = head -> next;
            delete head;
            head = p;
        }
    }

    int isEmpty() //Checks and returns TRUE if head is NULL
    {
        return head == 0;
    }

    void addToHead(int data) //Adds new data to the head of the Linked List
    {
        head = new Node(data, head);
        if (tail == 0)
        {
            tail = head;
        }
    }

    void addToTail(int data) //Adds new data to the tail of the Linked List
    {
        if (tail != 0)
        {
            tail -> next = new Node(data);
            tail = tail -> next;
        } else{
            head = tail = new Node(data);
        }
    }

    void printAll() const
    {
        for (Node *tmp = head; tmp != 0; tmp = tmp->next)
            cout << tmp->data << " ";
        cout << endl;
    }

private:
    //Node pointers for head and tail of the Linked List
    Node *head, *tail;
};

int main()
{
    SingleLinkedList List;

    int loopRunning;
    loopRunning = 1;

    while(loopRunning == 1)
    {
        int inp;
        cin >> inp;
        if (inp == -1)
            break;
        List.addToHead(inp);
    }
    List.printAll();

    return 0;
}

