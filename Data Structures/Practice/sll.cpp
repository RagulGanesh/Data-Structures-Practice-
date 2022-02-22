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
class Sll{
    public:
    void append(int data){
        Node *newNode=new Node(data);
        if(head==NULL){
            newNode->next=NULL;
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->next=NULL;
            tail=NULL;
        }
    }
    void push(int data){
        Node *newNode=new Node(data);
        if(head==NULL){
            newNode->next=NULL;
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void insert(int pos,int data){
        if(pos==1){
            push(data);
        }
        else if(pos==count()+1){
            append(data);
        }
        else{
            int p=1;
            Node *q=head;
            Node *newNode=new Node(data);
            while(p<pos-1){
                q=q->next;
                p++;
            }
            newNode->next=q->next;
            q->next=newNode;
        }
    }
    int count(){
        int c=1;
        Node *p=head;
        while(p!=NULL){
            c++;
            p=p->next;
        }
        return c;
    }
    void deleteFirst(){
        Node *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
    void deleteLast(){
        Node *temp;
        Node *t=head;
        while(t->next->next!=NULL){
            t=t->next;
        }
        tail=t;
        tail->next=NULL;
        temp=t->next;
        free(temp);
    }
    void deletePos(int pos){
        int p=1;
        Node *ptr=NULL;
        Node *temp=head;
        while(p<pos){
            ptr=temp;
            temp=temp->next;
            p++;
        }
        ptr->next=temp->next;
        free(temp);
    }
    void display(){
        Node *p=head;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
    Node *head=NULL;
    Node *tail=NULL;
};
int main(){
    Sll a;
    a.append(3);
    a.push(4);
    a.append(5);
    a.insert(1,2);
    a.insert(5,2);
    a.insert(3,100);
    a.deleteFirst();
    a.deleteLast();
    a.deletePos(2);
    a.deletePos(2);
    a.display();
}