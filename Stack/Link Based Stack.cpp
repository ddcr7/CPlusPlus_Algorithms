#include <iostream>
using namespace std;
//A stack is a LIFO structure (Last in First out)
class Node
{
public:

    int data;
    Node* next;

    Node(int info, Node *ptr = 0)
    {
        this->data = info;
        this->next = ptr;

    }
};

class intLinkedStack
{
private:
    Node* top;

public:
    int count;

    intLinkedStack()
    {
        count = 0;
        top = 0;
    }

    bool isEmpty()
    {
        return top == 0;
    }

    void push(int info) //Adds an element to the top of the stack
    {
        Node *temp = new Node(info);

        if (isEmpty())
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }

        count++;
    }

    int pop() //Removes the top most element of the stack
    {
        if(isEmpty())
        {
            return -999;
        }
        int intReturn = top->data;

        Node *temp;
        temp = top;

        top = top->next;

        delete temp;
        count--;

        return intReturn;
    }

    void print(){
        cout << "Number of items in the Linked Stack are: " << count << endl;
        cout << "The stack (from the top): ";
        for(Node *temp = top; temp != 0; temp=temp->next)
            cout << temp->data << " ";
        cout << endl;}
};

int main()
{
    intLinkedStack linkedStack;

    linkedStack.push(10);
    linkedStack.print();
    cout << "\n";
    linkedStack.push(20);
    linkedStack.push(30);
    linkedStack.push(40);
    linkedStack.push(50);
    linkedStack.print();
    cout << "\n";
    linkedStack.pop();
    linkedStack.print();
}
