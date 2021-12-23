#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
};
class Queue{
    public:
    void enqueue(int data){
            Node *newNode=new Node();
            newNode->data=data;
            if(front==NULL){
                front=newNode;
                rear=newNode;
            }
            else{
                newNode->next=NULL;
                rear->next=newNode;
                rear=newNode;
            }              
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue underflow";
        }
        else{
            Node *temp=front;
            int ele=temp->data;
            front=front->next;
            return ele;
        }
    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    Node *front=NULL;
    Node *rear=NULL;
};
class Stack{
    public:
    Queue a,b;
    void push(int data){
        if(a.front==NULL){
            a.enqueue(data);
        }
        else{
            while(!a.isEmpty()){
                b.enqueue(a.dequeue());
            }
            a.enqueue(data);
            while(!b.isEmpty()){
                a.enqueue(b.dequeue());
            }
        }
    }
    int pop(){
        if(a.front==NULL){
            cout<<"Stack Underflow";
        }
        else{
            Node *temp=a.front;
            int ele;
            ele=temp->data;
            a.front=a.front->next;
            free(temp);
            return ele;
        }
    }    
    void display(){
        for(Node *p=a.front;p!=NULL;p=p->next){
            cout<<p->data<<" ";
        }
    }
};
int main(){
    Stack a;
    a.push(3);
    a.push(4);
    a.push(5); 
    a.push(6); 
    a.pop();
    a.pop();
    a.pop();
    a.push(7);
    a.display();
}