#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
    T data;
    Node *next;
};
template<class T>
class Queue{
    public:
    void enqueue(int data){
        Node<T> *newNodeInsert=new Node<T>();
        newNodeInsert->data=data;
        if(front==NULL){
            newNodeInsert->next=NULL;
            front=newNodeInsert;
            rear=newNodeInsert;
        }
        else{
            newNodeInsert->next=NULL;
            rear->next=newNodeInsert;
            rear=rear->next;
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
    T dequeue(){
        T ele;
        if(front==NULL){
            cout<<"Queue is empty.";
        }
        else{
            Node<T> *temp;
            ele=front->data;
            temp=front;
            front=front->next;
            free(temp);
        }

        return ele;
    }
    void display(){
        Node<T>* temp;
        if(front==NULL){
            cout<<"Queue is empty.";
        }
        else{
                for(temp=front;temp!=NULL;temp=temp->next){
                    cout<<temp->data<<" ";
            }
        }

    }
    private:
    Node<T> *front=NULL;
    Node<T> *rear=NULL;
    
};