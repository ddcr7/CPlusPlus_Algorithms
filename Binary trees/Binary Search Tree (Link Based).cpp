#include <iostream>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode* left;
    treeNode* right;

    treeNode()
    {
        left = right = 0;
    }

    treeNode(int info, treeNode* l = 0, treeNode* r = 0)
    {
        this->data = info;
        left = l;
        right = r;
    }
};

class binarySearchTree
{
public:
    treeNode* root;

    binarySearchTree()
    {
        root = 0;
    }

    bool addNode(int data) //Adds a Node to the binary tree
    {
        treeNode *newNode = new treeNode(data);

        if(root == 0)
        {
            root = newNode;
            return true;
        }
        treeNode* temp = root;
        while(true)
        {
            if(data < temp->data)
            {
                if(temp->left == 0)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if(data > temp->data)
            {
                if(temp->right == 0)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else if(data == temp->data)
            {
                return false;
            }
        }
        return true;

    }

    void findAndDelete(int data) //finds the node and deletes the node from the binary tree
    {
        treeNode *temp = root, *prev = 0;

        //Searching for the data in the tree as we traverse
        //  through the list
        while(temp != 0 && temp->data != data)
        {
            prev = temp;
            if(temp->data < data) temp = temp->right;
            else temp = temp->left;
        }

        if(temp!=0 && temp->data == data) //Node is found
        {
            if(temp == root)
            {
                deleteNode(root);
            }
            else if(prev->left==temp)
            {
                deleteNode(prev->left);
            }
            else
            {
                deleteNode(prev->right);
            }
        }
        else if (root!=0)
            cout << "Data is not in the tree\n";
        else
            cout<< "Tree has no elements\n";
    }


    void deleteNode(treeNode* linkNode) //Deletes the specified node
    {
        treeNode *previous, *temp = linkNode;

        if(linkNode->right == 0)
            linkNode = linkNode->left;
        else if(linkNode->left == 0)
            linkNode = linkNode->right;
        else
        {
            temp = linkNode->left;
            previous = linkNode;

            while(temp->right != 0)
            {
                previous = temp;
                temp = temp->right;
            }

            linkNode->data = temp->data;

            if(previous == linkNode)
                previous->left = temp->left;
            else
                previous->right = temp->right;
        }
        delete temp;
    }


    void inorderTraversal(treeNode *temp)
    {
        if (temp != 0)
        {
            inorderTraversal(temp->left);
            cout << temp->data << " ";
            inorderTraversal(temp->right);
        }
    }

    void preOrderTraversal(treeNode *temp)
    {
        if(temp != 0)
        {
            preOrderTraversal(temp->left);
            preOrderTraversal(temp->right);
            cout << temp->data << " ";
        }
    }

    void postOrderTraversal(treeNode *temp)
    {
        if(temp != 0)
        {
            cout << temp->data << " ";
            postOrderTraversal(temp->left);
            postOrderTraversal(temp->right);
        }
    }
};

int main()
{
    binarySearchTree bst;
    bst.addNode(100);
    bst.addNode(75);
    bst.addNode(99);
    bst.addNode(110);
    bst.addNode(65);
    bst.addNode(80);
    bst.inorderTraversal(bst.root); cout << "\n";
    bst.findAndDelete(100);
    bst.inorderTraversal(bst.root);
    
    cout << endl;
}
