// Queue using array in C++

#include <iostream>
using namespace std;

class queue {
    int* arr;
    int front, rear, capacity, size;

public:
    queue (int cap = 100) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int val) {
        if (size < capacity) {
            rear = (rear + 1) % capacity;
            arr[rear] = val;
            size++;
        }
        else {
            cout << "queue is full" <<endl;
        }
    }

    void dequeue() {
        if (size > 0){
            front = (front + 1) % capacity;
            size--;
        }
        else {
            cout << "queue is empty" << endl;
        }
    }

    int getFront() {
        if (size > 0) {
            return arr[front];
        }
        throw out_of_range("Queue is empty");
        
    }

    bool isEmpty() {
        return size == 0;
    }

    ~queue() {
        delete[] arr;
    }

};

int main() {
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.getFront() << endl; // Should print 10
    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl; // Should print 20
    
    while (!q.isEmpty()) {
        cout << "Dequeueing: " << q.getFront() << endl;
        q.dequeue();
    }
    
    return 0;
}
