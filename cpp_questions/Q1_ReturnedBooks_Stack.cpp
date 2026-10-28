#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int size;
    int top;

public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int bookId) {
        if (isFull()) {
            cout << "Stack is full. Cannot return more books." << endl;
            return;
        }
        arr[++top] = bookId;
        cout << "Book " << bookId << " returned and placed on top." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. No book to arrange." << endl;
            return;
        }
        cout << "Book " << arr[top--] << " arranged on shelf." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack contents from top to bottom: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack returnedBooks(5);

    returnedBooks.push(101);
    returnedBooks.push(102);
    returnedBooks.push(103);
    returnedBooks.display();

    cout << "Top book: " << returnedBooks.peek() << endl;

    returnedBooks.pop();
    returnedBooks.display();

    returnedBooks.push(104);
    returnedBooks.display();

    return 0;
}
