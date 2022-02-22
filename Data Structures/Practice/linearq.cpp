#include<iostream>
using namespace std;
class Queue{
    public:
    Queue(int max){
        this->max=max;
        p=new int[max];
        front=rear=-1;
    }
    void enqueue(int data){
        if(rear==max-1){
            cout<<"Full";
        }
        else{
            if(front==-1){
                front++;
            }
            rear++;
            p[rear]=data;
        }
    }
    int dequeue(){
        if(front==-1||front>rear){
            cout<<"Empty";
        }
        else{
            if(front==rear){
                front=rear=-1;
            }
            int e=p[front];
            front--;
        }
    }
    int *p;
    int front,rear,max;
};