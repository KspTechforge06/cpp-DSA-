#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Binary
{
private:
    Node *root;

public:
    Binary()
    {
        root = NULL;
    }

    Node* create()
    {
        int value;
        cout << "\nEnter node value (-1 for no node): ";
        cin >> value;

        if(value == -1)
            return NULL;

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter left child of " << value << " : ";
        newNode->left = create();

        cout << "Enter right child of " << value << " : ";
        newNode->right = create();

        return newNode;
    }

    void build()
    {
        cout << "\nCreate Binary Tree\n";
        root = create();
    }

    void inorder(Node *temp)
    {
        if(temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void preorder(Node *temp)
    {
        if(temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

   

    void display()
    {
        cout << "\nInorder Traversal: ";
        inorder(root);

        cout << "\nPreorder Traversal: ";
        preorder(root);

        
        cout << endl;
    }
};

int main()
{
    Binary b;

    b.build();
    b.display();

    return 0;
}