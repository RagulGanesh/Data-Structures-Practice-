#include<iostream>
using namespace std;
class Stack{
    public:
    void push(char newData){
        if(top==max-1){
            cout<<"Overflow Error!\n";
        }
        else{
            p[++top]=newData;
        }
    }
    int pop(){
        if(top==-1){
            //cout<<"Underflow Error!\n";
            return 0;
        }
        else{
            
            return p[top--];
            //cout<<p[top]<<" is removed from the stack.\n";
            //top--;
        }
    }
    int peak(){
        if(top==-1){
            //cout<<"Underflow Error!\n";
            return 0;
        }
        else{
            //cout<<"Peak Value : "<<p[top]<<"\n";
            return p[top];
        }
    }
    int isEmpty(){
        if(top==-1){
            return 0;
        }
        else{
            return 1;
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
    char *p=new char[max];
    int top=-1;
    int max;        
};