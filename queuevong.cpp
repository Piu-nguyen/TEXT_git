#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* arr;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue day!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        cout << "Them " << value << " vao queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return;
        }
        cout << "Xoa " << arr[front] << " khoi queue.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue rong!\n";
            return;
        }
        cout << "Cac phan tu trong queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    int userSize;
    cout << "Nhap kich thuoc cua queue: ";
    cin >> userSize;

    CircularQueue q(userSize);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.enqueue(60);
    q.display();

    return 0;
}
