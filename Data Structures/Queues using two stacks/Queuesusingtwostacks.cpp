#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
};
class Stack{
    public:
    void push(int data){
        Node *newNode=new Node();
        newNode->data=data;
        if(top==NULL){
            newNode->next=NULL;
            top=newNode;
        }
        else{
            newNode->next=top;
            top=newNode;            
        }
    }
    int pop(){
        int ele;
        Node *temp;
        temp=top;
        ele=temp->data;
        top=top->next;
        free(top);
        return ele;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    Node *top=NULL;
};
class Queue{
    public:
    Stack a,b;
    void enqueue(int ele){
        if(a.top==NULL){
            a.push(ele);
        }
        else{
            while(!a.isEmpty()){
                b.push(a.pop());
            }
            a.push(ele);
            while(!b.isEmpty()){
                a.push(b.pop());
            }
        }
    }
    int dequeue(){
        if(a.top==NULL){
            cout<<"Underflow Condition";
        }
        else{
            Node *temp=a.top;
            int ele=temp->data;
            a.top=a.top->next;
            free(temp);
            return ele;
        }
    }
    void display(){
        Node *p;
        if(a.top==NULL){
            cout<<"Underflow Condition";
        }
        else{
        for(p=a.top;p!=NULL;p=p->next){
            cout<<p->data<<" ";
        }
        }
    }
};
int main(){
    Queue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
}