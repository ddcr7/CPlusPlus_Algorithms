#include<iostream>

using namespace std;

class arrayStack
{
private:
    int topOfStack;
    int const static SIZE = 100;
    int stack[SIZE];
public:
    arrayStack()
    {
        topOfStack = 0;
    }

    bool isEmpty()
    {
        return topOfStack == 0;
    }

    bool push(int data)
    {
        if(topOfStack + 1 > SIZE)
        {
            return false;
        }

        stack[topOfStack++] = data;
        return true;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -99999;
        }

        return stack[--topOfStack];
    }

    void print()
    {
        cout << "Top: ";
        for(int i = topOfStack - 1; i >= 0 ; i--)
        {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }

    int top()
    {
        return topOfStack;
    }
};

int main()
{
    arrayStack stack;

    cout << "Is the Stack Empty?  " << stack.isEmpty() << endl;
    stack.push(7);
    stack.push(10);
    stack.push(20);
    stack.print();
    stack.pop();
    stack.print();
    stack.push(27);
    stack.push(30);
    stack.pop();
    stack.print();

}

