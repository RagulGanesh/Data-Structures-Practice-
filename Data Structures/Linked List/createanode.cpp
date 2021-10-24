#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();
    head->data=13;
    head->next=second;
    second->data=14;
    second->next=third;
    third->data=15;
    third->next=NULL;
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

}
