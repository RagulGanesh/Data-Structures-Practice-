#include<iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
class Cdll{
    public:
    void append(int newData){
        Node *newNodeAppend=new Node();
        newNodeAppend->data=newData;
        if(head==NULL){
            newNodeAppend->next=newNodeAppend;
            newNodeAppend->prev=newNodeAppend;
            head=newNodeAppend;
        }
        else{
            Node *p=head;
            do{
                p=p->next;
            }while(p->next!=head);
            
            newNodeAppend->next=head;
            newNodeAppend->prev=head->prev;
            head->prev->next=newNodeAppend;
            head->prev=newNodeAppend;
        }
    }
    void push(int newData){
        Node *newNodePush=new Node();
        newNodePush->data=newData;
        newNodePush->next=head;
        newNodePush->prev=head->prev;
        head->prev->next=newNodePush;
        head->prev=newNodePush;
        head=newNodePush;
    }
    void insert(int pos,int newData){
        if(pos==1){
            push(newData);
        }
        else if(pos==count()+1){
            append(newData);
        }
        else if(pos<=0||pos>count()+1){
            cout<<"List Index Out Of Range.\n";
        }
        else{
            Node *newNodeInsert=new Node();
            newNodeInsert->data=newData;
            Node *p=head;
            int i=1;
            while(i<pos-1){
                p=p->next;
                i++;
            }
            
            newNodeInsert->next=p->next;
            newNodeInsert->prev=p;
            p->next->prev=newNodeInsert;
            p->next=newNodeInsert;
        }
    }
    void deleteFirst(){
        Node *temp=head;
        temp->prev->next=head->next;
        temp->next->prev=head->prev;
        head=head->next;
        free(temp);
    }
    void deleteLast(){
        Node *temp=head->prev;
        temp->prev->next=head;
        head->prev=temp->prev;
        free(temp);
    }
    void deleteNode(int pos){
        if(pos==1){
            deleteFirst();
        }
        else if(pos==count()){
            deleteLast();
        }
        else if(pos<=0||pos>count()+1){
            cout<<"List Index Out of Range.\n";
        }
        else{
            int i=1;
            Node *temp,*p=head;
            while(i<pos){
                temp=p;
                p=p->next;
                i++;
            }
            temp->next=p->next;
            p->next->prev=temp;
            free(p);
        }
    }
    void deleteAllNode(){
        cout<<"In deleteall node\n";
        Node *p=head;
        Node *temp=NULL;
        do{
            temp=p;
            p=p->next;
            p->prev=temp->prev;
            temp->prev->next=p;
            head=p;
            free(temp);
        }while(p!=head);
        head=NULL;
    }
    int count(){
        Node *p=head;
        int count=0;
        if(head!=NULL){
            
        do{
            count++;
            p=p->next;
        }while(p!=head);
        }
        
        
        return count;
    }
    void search(int element){
        Node *p=head;
        int flag=0;
        do{
            if(p->data==element){
                flag=1;
                break;
            }
            p=p->next;
        }while(p!=head);
        if(flag==1){
            cout<<"Found.\n";
        }
        else{
            cout<<"Not Found.\n";
        }
    }
    void printList(){
        Node *p=head;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
        
        cout<<"\n";
    }
    private:
    Node *head=NULL;
};
int main(){
    Cdll a;
    cout<<"Append Concept.\n";
    a.append(3);
    a.append(5);
    a.append(7);
    a.printList();
    cout<<"Push Concept.\n";
    a.push(5);
    a.push(98);
    a.printList();
    cout<<"Insert Concept.\n";
    a.insert(1,101);
    a.insert(2,99);
    a.insert(3,100);
    a.insert(9,101);
    a.printList();
    cout<<"Search Concept.\n";
    a.search(-99);
    cout<<"Delete First Concept.\n";
    a.deleteFirst();
    a.printList();
    cout<<"Delete Last Concept.\n";
    a.deleteLast();
    a.printList();
    cout<<"Delete Anywhere Concept.\n";
    a.deleteNode(2);
    a.deleteNode(4);
    a.deleteNode(1);
    a.deleteNode(4);
    a.printList();
    cout<<a.count()<<"\n";
    cout<<"Before : "<<a.count();
    a.deleteAllNode();
    cout<<"After : "<<a.count();

}


