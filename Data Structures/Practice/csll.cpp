#include<iostream>
using namespace std;
class Node{
    public:
    Node(int data){
        this->data=data;
    }
    int data;
    Node *next;
};
class Csll{
    public:
    void append(int data){
        if(head==NULL){
            Node *newNode= new Node(data);
            newNode->next=newNode;
            head=tail=newNode;
        }
        else{
            Node *newNode= new Node(data);
            Node *p=head;
            do{
                p=p->next;
            }while(p->next!=p);
            p->next=newNode;
            newNode->next=head;
            tail=newNode;
        }
    }
    Node *head=NULL;
    Node *tail=NULL;
};