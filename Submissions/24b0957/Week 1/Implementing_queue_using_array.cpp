#include<bits/stdc++.h>
using namespace std;

class Queue {
    int size;
    int capacity;
    int* arr;
    int first;
    int last;
public:
    Queue(int cap = 10) : size(0), capacity(cap), first(0), last(-1) {
        arr = new int[capacity];
    }
    ~Queue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if (size == capacity) {
            int new_capacity = capacity * 2;
            while (new_capacity <= size) {
                new_capacity *= 2;
            }
            int* new_arr = new int[new_capacity];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[(first + i) % capacity];
            }
            delete[] arr;
            arr = new_arr;
            first = 0;
            last = size - 1;
            capacity = new_capacity;
        }
        last = (last + 1) % capacity;
        arr[last] = value;
        size++;
    }
    void dequeue() {
        if (size > 0) {
            first = (first + 1) % capacity;
            size--;
        } else {
            cout << "Queue Underflow" << "\n";
        }
    }
    int getSize() const {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
    void clear() {
        size = 0;
        first = 0;
        last = -1;
    }
};