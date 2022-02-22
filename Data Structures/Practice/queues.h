#include<iostream>
using namespace std;
template<class T>
class Queue{
    public:
    bool IsEmpty(){
        if(front==-1||front>rear){
            return true;
        }
        else{
            return false;
        }
    }
    bool IsFull(){
        if(rear==max-1&&front==0){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(T data){
        if(IsFull()){
            cout<<"Queue is full.";
        }
        else{
            
            if(front==-1){
                front=0;
            }
            rear++;
            p[rear]=data;
        }
    }
    T dequeue(){
        T ele;
        if(IsEmpty()){
            cout<<"Queue is empty.";
        }
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                ele=p[front];
                front++;
            }
            
        }
        return ele;
    }
    void display(){
        if(IsEmpty()){
            cout<<"Queue is Empty.";
        }
        else{
            for(int i=front;i<=rear;i++){
            cout<<p[i]<<" ";
            }
        }

    }
    
    void input(){
        int n;
        cout<<"Enter the size of the queue : ";
        cin>>n;
        max=n;
        p=new T[max];
    }

    T *p;
    int max;
    int front=-1;
    int rear=-1;
};