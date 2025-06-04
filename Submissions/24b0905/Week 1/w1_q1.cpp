#include<iostream>
using namespace std;

// Implementing Vector using array in CPP
class vector {
    int* arr;
    int size;
    int capacity;
public:
    vector() {
        capacity = 4;
        size = 0;
        arr = new int[capacity];
    }

    void push_back(int val){
        if(size == capacity){
            // Resize the array
            capacity *= 2;
            int* newArr = new int[capacity];

            for (int i=0; i<size; i++){
                newArr[i] = arr[i];
            }
            delete[] arr; // Free old array
            arr = newArr; // Point to new array
        }
        arr[size++] = val; // Add new element
    }

    void pop_back() {
        if(size>0){
            size--; // Decrease size
        }
    }

    int get(int index) {
        if (index < size)
            return arr[index]; // Return the element at index
        throw out_of_range("Index out of range");
    }

    int getSize() {
        return size; 
    }

    void print() {
        for (int i=0; i<size; i++){
            cout << arr[i] << " ";
            cout <<endl;
        }
    }

    ~vector() {
        delete[] arr;
    }
};

int main() {
    vector v; // Create a vector object

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5); // This will resize the array
    v.push_back(6); 

    cout << "Vector elements: ";
    v.print(); // Prints the array

    v.pop_back(); // Remove last element
    cout << "After pop_back, vector elements: ";
    v.print(); // Prints the array after pop_back

    cout << "element at index 2: " << v.get(2) << endl; // Get element at index 2
    cout << "Size of vector (after the resize): " << v.getSize() << endl; // Get size of vector
}