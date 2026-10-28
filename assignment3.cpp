#include <iostream>
using namespace std;

struct Node
{
    int bookID;
    Node *next;
};

class BookList
{
private:
    Node *head;

public:
    BookList()
    {
        head = NULL;
    }

    void insertBeginning(int id)
    {
        Node *newNode = new Node;

        newNode->bookID = id;
        newNode->next = head;
        head = newNode;

        cout << "\nBook ID " << id
             << " inserted at beginning.\n";
    }

    void insertEnd(int id)
    {
        Node *newNode = new Node;

        newNode->bookID = id;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;

            cout << "\nBook ID " << id
                 << " inserted at end.\n";

            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "\nBook ID " << id
             << " inserted at end.\n";
    }

    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "\nLibrary list is Empty. Nothing to delete.\n";
            return;
        }

        Node *temp = head;

        head = head->next;

        cout << "\nBook ID " << temp->bookID
             << " deleted from beginning.\n";

        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "\nLibrary list is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nBook IDs: ";

        while (temp != NULL)
        {
            cout << temp->bookID << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    BookList library;

    int choice, id;

    do
    {
        cout << "\n----- College Library Book List -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;

                library.insertBeginning(id);
                break;

            case 2:
                cout << "Enter Book ID: ";
                cin >> id;

                library.insertEnd(id);
                break;

            case 3:
                library.deleteBeginning();
                break;

            case 4:
                library.display();
                break;

            case 5:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}