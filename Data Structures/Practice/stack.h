#include<iostream>
using namespace std;
class Stack{
    public:
    Stack(int max){
        size=max;
        p=new char[max];
    }
    void push(int data){
        if(top==size-1){
            cout<<"size if full";
        }
        else{
            p[++top]=data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Empty";
        }
        else{
            top--;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int top=-1;
    char *p;
    int size;
};