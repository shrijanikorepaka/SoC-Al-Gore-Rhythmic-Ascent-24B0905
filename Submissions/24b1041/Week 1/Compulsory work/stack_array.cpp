#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;

template <typename T>

class mystack{
    private:
    T* Data;
    int Size;
    int Capacity;
    
    void expand(){
         Capacity=Capacity*2;
        T* newdata = new T[Capacity];
        for(int i=0;i<Size;i++){
            newdata[i]=Data[i];
        }
        delete[] Data;
        Data=newdata;
    }
    public:
    void push(T value){
        if(Size==Capacity){
            expand();
        }
        Data[Size++]=value;
    }
    void pop(){
        if(Size==0){throw runtime_error("Stack is empty");}
        Size=Size-1;
    }
    T top(){
        if(Size==0){throw runtime_error("Stack si empty");}
        return Data[Size-1];
    }
    int size(){
        return Size;
    }
    bool empty(){
        return Size==0;
    }
};
#include <iostream>
#include <stack>

int main() {
    mystack<int> s;
    
    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    
    // Check size
    std::cout << "Size: " << s.size() << "\n";
    
    // Access top element
    std::cout << "Top: " << s.top() << "\n";
    
    // Remove elements
    while (!s.empty()) {
        std::cout << "Popping: " << s.top() << "\n";
        s.pop();
    }
    
    return 0;
}