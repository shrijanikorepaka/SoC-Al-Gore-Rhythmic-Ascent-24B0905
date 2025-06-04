#include<iostream>
using namespace std;

// Implementing stack using array in C++

class stack {
    int* arr;
    int capacity;
    int topIndex;

public:
    stack(int cap = 100) {
        capacity = cap;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex < capacity - 1) {
            arr[++topIndex] = val;
        }

        else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if(topIndex >= 0){
            topIndex--;
        }

        else {
            cout << "Stack underflow" << endl;
        }
    }

    int top() {
        if (topIndex >= 0) {
            return arr[topIndex];
        }

        throw out_of_range("Stack is empty");
    }

    bool is_empty() {
        return topIndex == -1;
    }

    ~stack() {
        delete[] arr;
    }
};

int main() {
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.top() << endl; // Should print 30

    s.pop();
    cout << "Top element after pop is: " << s.top() << endl; // Should print 20

    return 0;
}