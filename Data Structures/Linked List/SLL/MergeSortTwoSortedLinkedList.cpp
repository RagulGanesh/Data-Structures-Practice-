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
        Node *newAppendNode=new Node();
        newAppendNode->data=newData;
        newAppendNode->next=NULL;
        if(head==NULL){
            head=newAppendNode;
        }
        else{
            Node *q;
            q=head;
            while(q->next!=NULL){
                q=q->next;
            }
            q->next=newAppendNode;
        }
    }

    void printList(){
        Node *p;
        for(p=head;p!=NULL;p=p->next){
            cout<<p->data<<" ";
        }
    }

    Node *head=NULL;
};
void compare(Sll a,Sll b){
        Node *p,*q;
        Sll obj3;
        p=a.head;
        q=b.head;
        while((p!=NULL)&&(q!=NULL)){
            if(p->data<q->data){
                obj3.append(p->data);
                p=p->next;
            }   
            else{
                obj3.append(q->data);
                q=q->next;
            }         
        } 
        while((p!=NULL)){
            obj3.append(p->data);
            p=p->next;
        }  
        while((q!=NULL)){
            obj3.append(q->data);
            q=q->next;
        } 

        obj3.printList();
        
}

int main(){
    Sll obj1,obj2;
    int n1,n2;
    obj1.append(3);
    obj1.append(7);
    obj1.append(10);
    obj2.append(-1);
    obj2.append(0);
    obj2.append(6);
    compare(obj1,obj2);
    return 0;
}