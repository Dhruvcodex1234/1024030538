#include <iostream>
using namespace std;

#define MAX 100

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue is full!\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        arr[rear] = x;
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty!\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
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
            cout << (q.isEmpty() ? "Queue empty\n" : "Queue not empty\n");
            break;

        case 4:
            cout << (q.isFull() ? "Queue full\n" : "Queue not full\n");
            break;

        case 5:
            q.display();
            break;

        case 6:
            q.peek();
            break;

        case 7:
            return 0;
        }
    }
}

