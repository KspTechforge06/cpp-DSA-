#include <iostream>
#include <stack>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class BST 
{ 
    private:
    Node* root;
    Node* insertNode(Node* node, int value)
    {
        if(node == NULL)
        {
            return new Node(value);
        }
        if(value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else
        {
            node->right = insertNode(node->right, value);
        }
        return node;
    }
};

public:
    BST()
    {
        root = NULL;
    }

void createBST()
{
    int n, value;
    cout<<"Enter the number of nodes in the BST: ";
    cin>>n;
    cout<<"Enter Node value:\n";
    for(int i =1; i<=n;i++)
    {
        cin>>value;
        root = insertNode(root, value);

    }
}

void inorder()
{
    stack<Node*> s;
    Node* current = root;
    cout<<"Inorder Traversal of BST: ";
    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
            S.push(current);
            current = current->left;
            
        }
        current = s.top();
            s.pop();
            cout<<current->data<<" ";
            current = current->right;
        }
        cout<<endl;

}

void preorder()
{
    S.pop();
    cout<<current->data<<" ";
    if (current->right !=NULL)
    
}
int main()
{
    BST tree;
    tree.createBST();
    tree.inorder();
    tree.preorder();
    return 0;
}
