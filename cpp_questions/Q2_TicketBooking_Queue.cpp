#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int customerId) {
        if (isFull()) {
            cout << "Queue is full. Customer cannot be added." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = customerId;
        cout << "Customer " << customerId << " joined the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No customer to serve." << endl;
            return;
        }

        cout << "Customer " << arr[front] << " served and removed." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i != rear; i = (i + 1) % size) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue counter(5);

    counter.enqueue(10);
    counter.enqueue(20);
    counter.enqueue(30);
    counter.display();

    counter.dequeue();
    counter.display();

    counter.enqueue(40);
    counter.enqueue(50);
    counter.display();

    return 0;
}
