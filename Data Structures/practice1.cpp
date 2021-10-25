#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
void printList(Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
        cout<<"In print list";
    }
}
int main(){

    Node *head=NULL;
    printList(head); 



    /*Node *head;
    head=new Node();
    Node b,tail;
    head->data=10;
    head->next=&b;
    b.data=13;
    b.next=&tail;
    tail.data=19;
    tail.next=NULL;
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }*/

    /*Node *head,*second,*tail;
    head=new Node();
    second=new Node();
    tail=new Node();
    head->data=14;
    head->next=second;
    second->data=15;
    second->next=tail;
    tail->data=189;
    tail->next=NULL;
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }*/

    /*Node *head;
    head=new Node();
    Node b,c,*p;
    head->data=7;
    p=&b;
    head->next=p;
    p->data=10;
    p->next=&c;
    p=&c;
    p->data=90;
    p->next=NULL;
    p=head;

    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }*/
    
    //Inserting a node at the beginning
    /*Node *head;
    head=new Node();
    Node b,tail;
    head->data=10;
    head->next=&b;
    b.data=13;
    b.next=&tail;
    tail.data=19;
    tail.next=NULL;
    Node *p=head;
    cout<<"Before : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    Node new_node;
    new_node.data=1678;
    new_node.next=head;
    head=&new_node;

    p=head;

    cout<<"\nAfter : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }*/
     
    // Inserting a node at the end
    /*Node *head;
    head=new Node();
    Node b,tail;
    head->data=10;
    head->next=&b;
    b.data=13;
    b.next=&tail;
    tail.data=19;
    tail.next=NULL;
    Node *p=head;
    cout<<"Before : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

    Node newNode;
    tail.next=&newNode;
    newNode.data=106;
    newNode.next=NULL;

    p=head;
    cout<<"\nAfter : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }*/
    
    //Inserting a node in the between
    /*Node *head;
    head=new Node();
    Node b,tail;
    head->data=10;
    head->next=&b;
    b.data=13;
    b.next=&tail;
    tail.data=19;
    tail.next=NULL;
    Node *p=head;
    cout<<"Before : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    Node newNode;
    b.next=&newNode;
    newNode.data=106;
    newNode.next=&tail;

    p=head;
    cout<<"\nAfter : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }*/




    return 0;

}