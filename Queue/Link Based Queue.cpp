#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int info, Node* ptr = 0)
    {
        this->next = ptr;
        this->data = info;
    }
};

class linkedQueue
{
private:
    Node* front;
    Node* back;

public:
    int count = 0;

    linkedQueue()
    {
        front = back = 0;
    }

    bool isEmpty() //returns the status of the queue
    {
        return (front==0 && back ==0);
    }

    void enQueue(int info) //adds the element at the back of the queue
    {
        Node* temp = new Node(info);

        if (back == 0)
        {
            front  = back = temp;
        }
        else
        {
            back->next = temp;
            back = temp;
        }
        count++;
    }

    int deQueue() //deletes the first element entered into the queue
    {
        if (isEmpty())
        {
            return -999;
        }

        Node* temp;
        int intReturn;

        intReturn = front -> data;

        temp = front;
        front = front->next;

        delete temp;
        count--;

        return intReturn;
    }

    int elementNo() //returns the status of the number of elements
    {
        return count;
    }

    void print() //prints the queue
    {
        for(Node* temp = front ;temp != 0;temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << "\n";
    }
};

int main()
{
    linkedQueue theQueue;
    theQueue.enQueue(10);
    theQueue.enQueue(20);
    theQueue.print();
    cout<< "Number of elements in the Queue are: " << theQueue.elementNo() << endl;
    theQueue.deQueue();
    theQueue.print();
    cout<< "Number of elements in the Queue are: " << theQueue.elementNo() << endl;
    theQueue.enQueue(30);
    theQueue.enQueue(40);
    theQueue.print();
    cout<< "Number of elements in the Queue are: " << theQueue.elementNo() << endl;


}
