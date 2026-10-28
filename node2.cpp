#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};

class LinkedList
{
    private:
       Node *head;
    
    public: 
    LinkedList()
    {
        head = NULL;
    }

    void createList()
    {
        int n, value;
        cout << "\nEnter number of nodes: ";
        cin >> n;
        if(n <= 0)
        {
            cout << "Invalid number of nodes.";
            return;
        }
        for(int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;
            insertEnd(value);
        }
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "\nLinked List is empty." << endl;
            return;
        }

        Node *temp = head;
        cout << "\nLinked List: ";
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteNode(int value)
{
    if(head == NULL)
    {
        cout << "\nLinked List is empty.";
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    // If first node contains the value
    if(temp->data == value)
    {
        head = temp->next;
        delete temp;
        cout << "\nNode deleted.";
        return;
    }

    // Search for the node
    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if(temp == NULL)
    {
        cout << "\nValue not found.";
        return;
    }

    // Delete the node
    prev->next = temp->next;
    delete temp;

    cout << "\nNode deleted.";
}

};

int main()
   {
    LinkedList list;
    int value, delValue;
    list.createList();
    list.display();
    cout <<"Enter a value to insert at end";
    cin >> value;
    list.insertEnd(value);
    list.display();
    return 0; 
    cout << "\nEnter value to delete: ";
    cin >> delValue;

    list.deleteNode(delValue);

    list.display();


   }