#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    public:
    void push(int data){
        Node *nn=new Node();
        nn->data=data;
        if(top==NULL){
            nn->next=NULL;
            top=nn;
        }
        else{
            nn->next=top;
            top=nn;
        }
    }
    int pop(){
        if(top==NULL){
            return 0;
        }
        else{
            Node *t=top;
            int x=t->data;
            top=top->next;
            free(t);
            return x;
        }
    }
    int peak(){
        if(top==NULL){
            return 0;
        }
        else{
            return top->data;
        }
    }
    Node *top=NULL;
};