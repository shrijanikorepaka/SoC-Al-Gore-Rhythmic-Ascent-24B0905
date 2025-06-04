#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;
template <typename T>

class myqueue{
    private:
    T* Data;
    int Size;
    int Capacity;


    void expand(){
        Capacity *=2;
        T* newData = new T[Capacity];
        for(int i=0;i<Size;i++){
            newData[i]=Data[i];
        }
        delete[] Data;
        Data=newData;
    }
    public:
    myqueue(){Size=0;Capacity=2;Data= new T[Capacity];}
    ~myqueue(){
        delete[] Data;
    }
    void push(T element){
        if(Size==Capacity){expand();}
        Data[Size++]=element;
    }
    void pop(){
        if(Size==0){throw runtime_error("Queue is empty!");}
        T* newData= new T[Size-1];
        for(int i=1;i<Size;i++){
            newData[i-1]=Data[i];
        }
        Data=newData;
        delete[] Data;
        Size--;
    }
    T* front(){
        if(Size==0){throw runtime_error("Queue is empty!");}
        return Data;
    }
    T* back(){
        if(Size==0){throw runtime_error("Queue is empty!");}
        return Data+Size-1;
    }
    int size(){
        return Size;
    }
    bool empty(){
        return Size==0;
    }
};
int main() {
    myqueue<int> q;

    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    cout << "Pushing elements: 10, 20, 30" << endl;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    cout << "Popping an element..." << endl;
    q.pop();

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "Popping all elements..." << endl;
    q.pop();
    q.pop();

    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    try {
        q.pop();  // This should throw an error
    } catch (runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
