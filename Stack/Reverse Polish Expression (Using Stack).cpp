/*
Reverse Polish notation, also known as Polish postfix notation or simply postfix notation, 
is a mathematical notation in which operators follow their operands,
 in contrast to Polish notation, in which operators precede their operands.
 */
#include<iostream>
#include <sstream>
#include <string>

using namespace std;

class Node // Implementation of a Node for a Linked List Stack
{
public:
    float data;
    Node* next;

    Node(float info, Node* ptr = 0)
    {
        this->data = info;
        this->next = ptr;
    }
};

class floatLinkedStack //Linked List implementation of a stack for data of type float
{
private:
    Node* top;

public:
    int count;

    floatLinkedStack()
    {
        top = 0;
        count = 0;
    }

    bool isEmpty() //checks if stack is top of stack is empty
    {
        return top == 0;
    }

    float topVal() //returns value of top of the stack
    {
        return top->data;
    }

    void push(float info) //pushes ew element to the top of stack
    {
        Node* temp = new Node(info);

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

    float pop() //removes top most value from the stack
    {
        if(isEmpty())
        {
            return -999;
        }

        float floatReturn;
        floatReturn = top->data;

        Node* temp;
        temp = top;

        top = top->next;

        delete temp;
        count--;

        return floatReturn;
    }

    int elementNo() //returns number of elements in the stack
    {
       return count;
    }

    void printStack()
    {
        for(Node* temp = top; temp != 0 ; temp=temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
};


bool performOp(floatLinkedStack &theStack ,string word)
//performs operation on the top two elements of the stack and pushes the result back into the stack at the top
//returns true if operator error is present else returns false
{
    if (word == "+")
    {
        if(theStack.elementNo() < 2)
        {
            return true;
        }
        float a,b;
        a = theStack.topVal();
        theStack.pop();
        b = theStack.topVal();
        theStack.pop();
        theStack.push(b+a);
        return false;
    }
    else if (word == "*")
    {
        if(theStack.elementNo() < 2)
        {
            return true;
        }
        float a,b;
        a = theStack.topVal();
        theStack.pop();
        b = theStack.topVal();
        theStack.pop();
        theStack.push(b*a);
        return false;
    }
    else if (word == "/")
    {
        if(theStack.elementNo() < 2)
        {
            return true;
        }
        float a,b;
        a = theStack.topVal();
        theStack.pop();
        b = theStack.topVal();
        theStack.pop();
        if (a == 0)
        {
            theStack.count = -999; //To check if Division by zero error occurs outside the function and display the error
        }
        else
            theStack.push(b/a);
        return false;
    }
    else if (word == "-")
    {
        if(theStack.elementNo() < 2)
        {
            return true;
        }
        float a,b;
        a = theStack.topVal();
        theStack.pop();
        b = theStack.topVal();
        theStack.pop();
        theStack.push(b-a);
        return false;
    }

    else
        theStack.push(stof(word));
}

int main()
{
    int const SIZE = 1000;
    char symbol[SIZE];
    string word;

    cin.getline(symbol, SIZE);//Input from user
    stringstream str(symbol); //To traverse through the user input one string at a time seperated by a white space
    floatLinkedStack theStack;

    bool OperatorError = false; // turns true if operators are greater than number of operands

    while(str >> word && !OperatorError)
    {
        if(word == "=") // Input is executed only unless an = is input by the user
        {
            word = "\n";
            break;
        }
        OperatorError = performOp(theStack, word);
    }
    cout << "\n";

    if (theStack.elementNo() > 1) //If number of elemnts in stack is more than one after execution, Operand error is shown
    {
        cout<< "Error: Too many operands" << endl;
    }
    else if (theStack.elementNo() == -999) //If operands are divided by 0 , the count is set to -999 and error is shown
    {
        cout << "Error: Division by 0" << endl;
    }
    else if (OperatorError)
    {
        cout << "Error: Too many operators" << endl;
    }
    else
    {
        //Final answer is displayed which is the top of the stack
        theStack.printStack();
    }

    return 0;
}

/*
 * Sample Outputs:
 *
EXAMPLE 1:

10 15 + =
25

Process finished with exit code 0

EXAMPLE 2:

10 15 - =
-5

Process finished with exit code 0
*/
