#include<iostream>
#define MAX_SIZE 10
using namespace std;

//Array implementation of a queue data structure
class ArrayBasedQueue
{
public:
    int arr[MAX_SIZE];
    int rear;
    int front;
    int count = 0;

    ArrayBasedQueue()//instantiates the queue
    {
        front = rear = -1;
    }

    bool isEmpty() //returns the state of the queue
    {
        return (front == -1 && rear == -1);
    }

    void enQueue(int data)
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "Queue full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                front = rear = 0;
                arr[rear] = data;
            }

            else if (rear == MAX_SIZE-1 && front != 0)
            {
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
            count++;
        }
    }

    int deQueue()
    //removes an element from the queue
    //removes the first added element since a queue is a FIFO structure (First in first out)
    {
        int temp;

        if (isEmpty())
        {
            return -999;
        }
        else
        {
            if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                temp = arr[front];
                front++;
                count--;
            }
        }
        return temp;
    }

    int elementNo() //returns the number of elements in the queue at the time when called
    {
        return count;
    }

    void print() //Prints the queue
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for(int i = front ; i<= rear ; i++)
            {
                cout << arr[i]<<" ";
            }

        }
    }
};
//Main implemented to test the above code
int main()
{
    ArrayBasedQueue *queue = new ArrayBasedQueue;
    queue->enQueue(5);
    queue->enQueue(10);
    queue->print();
    cout<<"\nNumber of elements in Queue are: " << queue->elementNo() << endl;
    cout << "\n";
    queue->deQueue();
    queue->print();
    cout<<"\nNumber of elements in Queue are: " << queue->elementNo() << endl;
    cout << "\n";
    queue->enQueue(20);
    queue->enQueue(30);
    queue->print();
    cout<<"\nNumber of elements in Queue are: " << queue->elementNo() << endl;
}
