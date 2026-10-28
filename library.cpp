#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    int books[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Return Book - Push
    void push(int book) {
        if (top == MAX - 1) {
            cout << "Stack is Full!" << endl;
        } else {
            top++;
            books[top] = book;
            cout << "Book " << book << " returned." << endl;
        }
    }

    // Arrange Book - Pop
    void pop() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Book " << books[top] << " arranged on shelf." << endl;
            top--;
        }
    }

    // Top Book - Peek
    void peek() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Top Book: " << books[top] << endl;
        }
    }

    // Display Stack
    void display() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Returned Books:" << endl;

            for (int i = top; i >= 0; i--) {
                cout << books[i] << endl;
            }
        }
    }
};

int main() {
    Stack s;
    int choice, book;

    do {
        cout << "\n--- Library Stack ---" << endl;
        cout << "1. Return Book (Push)" << endl;
        cout << "2. Arrange Book (Pop)" << endl;
        cout << "3. Top Book (Peek)" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> book;
            s.push(book);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}