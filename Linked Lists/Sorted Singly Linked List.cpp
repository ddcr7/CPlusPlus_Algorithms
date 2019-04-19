#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int info, Node* ptr = 0)
    {
        this->data = info;
        this->next = ptr;
    }
};

class singlyLinkedList
{
private:
    Node* head;
    Node* tail;

public:

    singlyLinkedList()
    {
        head = tail = 0;
    }

    ~singlyLinkedList()
    {
        for(Node* p = head; !isEmpty();)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }

    bool isEmpty()
    {
        return head == 0;
    }

    void addToHead(int info)
    {
        Node* temp = new Node(info,head);
        if(tail == 0)
        {tail = head = new Node(info);}
    }

    void addToTail(int info)
    {
        if (tail!=0)
        {
            tail->next = new Node(info);
        }else{tail = head = new Node(info);}
    }

    void sortedInsert(int info)
    {
        Node* newNode = new Node(info);

        if(head==0 || head->data >= newNode->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while(temp->next != 0 && temp->next->data < info)
                temp = temp -> next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void printAll() const
    {
        for (Node *tmp = head; tmp != 0; tmp = tmp->next)
            cout << tmp->data << " ";
        cout << endl;
    }
};

int main()
{
    singlyLinkedList SLL;
    int userInput;

    cout << "Enter a number to be entered into the linked list: ";
    cin >> userInput;

    while(userInput != -1)
    {
        SLL.sortedInsert(userInput);
        SLL.printAll();
        cout << "Enter a number to be entered into the linked list: ";
        cin >> userInput;
    }

    return 0;
}

/*
OUTPUT:

Enter a number to be entered into the linked list:5
5
Enter a number to be entered into the linked list:2
2 5
Enter a number to be entered into the linked list:4
2 4 5
Enter a number to be entered into the linked list:5
2 4 5 5
Enter a number to be entered into the linked list:7
2 4 5 5 7
Enter a number to be entered into the linked list:12
2 4 5 5 7 12
Enter a number to be entered into the linked list:17
2 4 5 5 7 12 17
Enter a number to be entered into the linked list:14
2 4 5 5 7 12 14 17
Enter a number to be entered into the linked list:-1
 -1

Process finished with exit code 0


 */
