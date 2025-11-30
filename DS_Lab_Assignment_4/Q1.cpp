#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty!\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
            break;

        case 4:
            cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
            break;

        case 5:
            q.display();
            break;

        case 6:
            q.peek();
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

