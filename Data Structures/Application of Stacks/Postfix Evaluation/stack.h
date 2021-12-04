#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    public:
    void push(int newData){
        Node *newNodePush=new Node();
        newNodePush->data=newData;
        if(top==NULL){
            newNodePush->next=NULL;
            top=newNodePush;
        }
        else{
            newNodePush->next=top;
            top=newNodePush;
        }
    }
    int pop(){
        Node *p=top,*temp;
        int x;
        if(top==NULL){
            //cout<<"Stack Underflow!!!";
            return 0;
        }
        else{
            temp=top;
            x=temp->data;
            top=top->next;
            free(temp);
            return x;
        }

    }
    int peak(){
        if(top==NULL){
            //cout<<"Stack Underflow!!!";
            return 0;
        }
        else{
            //cout<<"Peak value : "<<top->data<<"\n";
            return top->data;
        }
    }
    int isEmpty(){
        if(top==NULL){
            return 0;
        }
        else{
            return 1;
        }
    }
    void display(){
        Node *p=top;
        if(top==NULL){
            cout<<"Stack Underflow!!!";
        }
        else{
            while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
            
        }

        cout<<"\n";
    }
    private:
    Node *top=NULL;
};