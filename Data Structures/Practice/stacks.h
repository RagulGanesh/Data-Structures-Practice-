#include<iostream>
using namespace std;
class Stack{
    public:
    Stack(int max){
        size=max;
        p=new char[max];
        top=-1;
    }
    int push(int data){
        if(top==size-1){
            return 0;
        }
        else{
            p[++top]=data;
        }
    }
    int pop(){
        if(top==-1){
            return 0;
        }
        else{
            return p[top--];
        }
    }
    int peak(){
        if(top==-1){
            return 0;
        }
        else{
            return p[top];
        }
    }
    int isEmpty(){
        if(top==-1){
            return 1;
        }
        else{
            return false;
        }
    }
    char *p;
    int size;
    int top;
};
