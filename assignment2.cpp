#include <iostream>
using namespace std;

#define MAX 100

class Queue
{
private:
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == MAX - 1)
        {
            cout << "\nQueue is Full. Cannot add more customers.\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = value;

        cout << "\nCustomer with ticket " << value
             << " added to queue.\n";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue is Empty. No customer to serve.\n";
            return;
        }

        cout << "\nCustomer with ticket "
             << arr[front] << " served.\n";

        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue is Empty.\n";
            return;
        }

        cout << "\nCustomers waiting: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n----- Ticket Booking Counter -----\n";
        cout << "1. Enqueue (New Customer)\n";
        cout << "2. Dequeue (Serve Customer)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter ticket number: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}