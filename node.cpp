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
};
    void createList()
    {
        int n, value;
        cout << "\nEnter number of nodes:";
        cin >> n;
        if(n<=0)
        {
            cout <<"Invalid number of nodes.";
            return;
        }

        for(int i=1; i<=n; i++)
        {
            cout<< "Enter Value"<<i<<" :";
            cin>>value;
            insertEnd(value);
        }
        cout <<"\nLinkedlist Created. \n";

    }
    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(head==NULL)
        {
            head = newNode;
            return;
        }
        //traversing head just  create a temp node to traverse till last 
        Node *temp = head; 
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        //attach new node 
        temp->next =newNode;
    }
    void display()
   {

    if(head==NULL)
    {
        cout<<"\nLinked List is Empty.\n";
        return;
    }
    Node *temp=head;
    cout<<"\nLinked List : ";
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";temp=temp->next;

    }
   }
};
