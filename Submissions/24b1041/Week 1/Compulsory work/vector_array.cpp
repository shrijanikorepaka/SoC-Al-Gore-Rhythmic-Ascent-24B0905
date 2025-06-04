#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;
template <typename T>

class myvector{
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
    myvector(){Size=0;Capacity=2;Data= new T[Capacity];}
    ~myvector(){
        delete[] Data;
    }
    T at(int index){
        if(index>Size || index<0){
            throw runtime_error("Index out of range!");
        }else{
        return Data[index];
        }
    }
    T& operator[](int index){
        return Data[index];
    }
    T front(){
        if(Size==0){throw runtime_error("Vector is empty!");}
        return Data[0];
    }
    T back(){
        if(Size==0){throw runtime_error("Vector is empty!");}
        return Data[Size-1];
    }
    int size(){
        return Size;
    }
    int capacity(){
        return Capacity;
    }
    bool empty(){
        return Size==0;
    }
    T* data(){
        return Data;
    }
    void push_back(T value){
        if(Size==Capacity){expand();}
        Data[Size++]=value;
    }
    void pop_back(){
        if(Size==0){throw runtime_error("Vector is empty!");}
        Size=Size-1;
    }
    void clear(){
        delete[] Data;
        Data= new T[2];
        Capacity=2;
        Size=0;
    }
    T* begin(){
        return Data;
    }
    T* end(){
        return Data+Size;
    }
    T* rbegin(){
        return Data+Size-1;
    }
    T* rend(){
        return Data-1;
    }
    void insert(T* position, T value){
        int index=position-Data;
        if(index<0 || index>=Size){throw runtime_error("Iterator is invalid!");}
        if(Size==Capacity){expand();}
        for(int i=index+1;i<Size;i++){
            Data[i]=Data[i-1];
        }
        Data[index]=value;
        Size++;
    }
    void erase(T* position){
        int index=position-Data;
        if(index<0 || index>=Size){throw runtime_error("Iterator is invalid!");}
        for(int i=index+1;i<Size;i++){
            Data[i-1]=Data[i];
        }
        Size--;
    }
};
int main() {
    myvector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\nBack: " << v.back() << endl;

    for (auto it = v.rbegin(); it != v.rend(); --it) {
        cout << *it << " ";
    }

    return 0;
}
