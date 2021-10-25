#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Sll{
    public:
    void append(int newData){
        Node *newNodeAppend=new Node();
        Node *p=head;
        newNodeAppend->data=newData;
        newNodeAppend->next=NULL;
        if(head==NULL){
            head=newNodeAppend;
        }
        else{
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=newNodeAppend;
        }
    }
    void push(int newData){
        Node *newNodePush=new Node();
        newNodePush->data=newData;
        newNodePush->next=head;
        head=newNodePush;
    }
    void insert(int pos,int newData){
        int i=1;
        Node *newNodeInsert=new Node();
        newNodeInsert->data=newData;
        Node *p=head;
        while(i<pos-1){
            if(p->next==NULL){
                break;
            }
            p=p->next;
            i++;
        }
        if(pos-1>i){
            cout<<"List index out of range.\n";
            return;
        }
        newNodeInsert->next=p->next;
        p->next=newNodeInsert;
    }
    void search(int element){
        Node *p;
        int flag=0;
        for(p=head;p!=NULL;p=p->next){
            if(element==p->data){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"Element Found.";
        }
        else{
            cout<<"Element not found.";
        }
    }
    void printList(){
        Node *ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
    void count(){
        Node *p;
        int count=0;
        for(p=head;p!=NULL;p=p->next){
            count++;            
        }
        cout<<"Total number of elements are "<<count<<"\n";
    }
    private:
    Node *head=NULL;
};
int main(){
    Sll obj;
    obj.append(3);
    obj.append(4);
    obj.push(9);
    obj.push(9);
    obj.push(10);
    obj.insert(10,190);
    obj.printList();
    obj.count();
}