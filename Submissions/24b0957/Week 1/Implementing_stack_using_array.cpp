#include<bits/stdc++.h>
using namespace std;
class Stack {
    int top;
    int capacity;
    int* arr;
    public:
    Stack(int cap = 10) : top(-1), capacity(cap) {
        arr = new int[capacity];
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int value) {
        if (top >= capacity - 1) {
            int new_capacity = capacity * 2;
            while (new_capacity <= top + 1) {
                new_capacity *= 2;
            }
            int* new_arr = new int[new_capacity];
            for (int i = 0; i <= top; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity = new_capacity;
        }
        arr[++top] = value;
    }
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << "\n";
        }
    }
    int size() const {
        return top + 1;
    }
    bool isEmpty() const {
        return top == -1;
    }
    void clear() {
        top = -1;
    }
};