#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* last;

    Node(int info, Node* lastptr = 0, Node* nextPtr = 0)
    {
        this->data = info;
        this->next = nextPtr;
        this->last = lastptr;
    }
};

class doublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:

    doublyLinkedList()
    {
        head = tail = 0;
    }

    ~doublyLinkedList()
    {
        for(Node* p;! isEmpty();)
        {
            p = head->next;
            delete p;
            head = p;
        }
    }

    bool isEmpty()
    {
        return head == 0;
    }

    void addToHead(int info) //Adds a node to the head of the linked list
    {
        Node* temp = new Node(info, 0, head);

        if (head != 0)
            head->last = temp;
        head = temp;

        if(tail==0) tail = head;
    }

    void addToTail(int info) //Adds a node to the end of the linked list
    {
        if (tail != 0)
        {
            Node* temp = new Node(info, tail);

            tail->next = temp;
            tail = tail->next;

        } else {
            head = tail = new Node(info);
        }
    }

    int deleteFromHead() //deletes the first node in the linked list
    {
        int info = head->data;
        Node* temp = head;

        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            head = head->next;
            head->last = 0;
        }

        delete temp;
        return info;
    }

    int deleteFromTail() //deletes last node in the linked list
    {
        int info = tail->data;

        if(head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            Node* temp = tail;
            tail = tail->last;
            tail->next = 0;
            delete temp;
        }
        return info;
    }

    bool isInList(int info) //Returns true if data is present in the linked list
    {
        Node* tmp;
        for(tmp = head; tmp != 0 && !(tmp->data == info);tmp = tmp->next);
        return tmp!=0;
    }

    int deleteElement(int info) //Deletes the Element from the Linked List While maintaining the Link between the Nodes
    {
        if (head!=0)
        {
            if (head == tail && head->data==info)
            {
                delete head;
                head = tail = 0;
            }
            else if (info == head ->data)
            {
                Node* temp;
                temp = head->next;
                head->last=0;
                delete temp;
            }
            else
            {
                Node* temp;

                for(temp=head;
                    temp!=0 && !(info==temp->data);
                    temp=temp->next);

                if(temp!=0)
                {
                    temp->last->next = temp->next;

                    if (temp->next != 0)
                        temp->next->last = temp->last;

                    if(temp==tail)
                    {
                        tail = temp->last;

                        delete temp;
                    }
                }
            }
        }
    }

    void printAll() //Prints the Linked List
    {
        for (Node *tmp = head; tmp != 0; tmp = tmp->next)
            cout << tmp->data << " ";
        cout << endl;
    }
};

int main()
{
    doublyLinkedList *dll = new doublyLinkedList();
    dll->addToHead(1);
    dll->addToTail(2);
    dll->printAll();

    return 0;
}
