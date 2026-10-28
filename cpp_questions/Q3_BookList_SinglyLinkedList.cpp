#include <iostream>
using namespace std;

struct Node {
    int bookId;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int id) {
        Node *newNode = new Node;
        newNode->bookId = id;
        newNode->next = head;
        head = newNode;
        cout << "Inserted book ID " << id << " at the beginning." << endl;
    }

    void insertAtEnd(int id) {
        Node *newNode = new Node;
        newNode->bookId = id;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            cout << "Inserted book ID " << id << " as the first node." << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted book ID " << id << " at the end." << endl;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        cout << "Deleted book ID " << temp->bookId << " from the beginning." << endl;
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        cout << "Book IDs: ";
        while (temp != nullptr) {
            cout << temp->bookId << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList library;

    library.insertAtEnd(101);
    library.insertAtEnd(102);
    library.insertAtBeginning(99);
    library.display();

    library.deleteFromBeginning();
    library.display();

    library.insertAtEnd(103);
    library.display();

    return 0;
}
