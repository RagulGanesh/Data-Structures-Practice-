#include<iostream>
using namespace std;
class Stack{
    public:
    void push(int newData){
        if(top==max-1){
            cout<<"Overflow Error!\n";
        }
        else{
            p[++top]=newData;
        }
    }
    int pop(){
        if(top==-1){
            cout<<"Underflow Error!\n";
        }
        else{
            //cout<<p[top]<<" is removed from the stack.\n";
            return p[top--];
        }
    }
    int peak(){
        if(top==-1){
            cout<<"Underflow Error!\n";
        }
        else{
            //cout<<"Peak value  : "<<p[top]<<"\n";
            return p[top];
        }
    }
    void display(){
        if(top==-1){
            cout<<"Underflow Error!\n";
        }
        else{
            for(int i=top;i>=0;i--){
            cout<<p[i]<<" ";
            } 
            
            cout<<"\n";
            
        }

    }
    //private:
    char *p=new char[max];
    int top=-1;
    int max;
};