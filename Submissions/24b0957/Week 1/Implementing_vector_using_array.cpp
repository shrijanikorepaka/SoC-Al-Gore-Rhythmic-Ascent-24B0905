#include<bits/stdc++.h>
using namespace std;

class Vector {
    int size;
    int capacity;
    float* arr;
public:
    Vector(int cap = 10) : size(0), capacity(cap){
        arr = new float[capacity];
    }
    ~Vector() {
        delete[] arr;
    }
    void push_back(float value){
        if(this->size >= this->capacity) {
            int new_capacity = this->capacity * 2;
            while(new_capacity <= this->size) {
                new_capacity *= 2;
            }
            float* new_arr = new float[new_capacity];
            for(int i = 0; i < this->size; i++) {
                new_arr[i] = this->arr[i];
            }
            delete[] this->arr;
            this->arr = new_arr;
            this->capacity = new_capacity;
            delete[] new_arr;
        }
    }

    int size() const {
        return this->size;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }
    float& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return this->arr[index];
    }
};