#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Csll{
    public:
    void append(int newData){
        Node *newNodeAppend=new Node();
        newNodeAppend->data=newData;
        if(head==NULL){
            head=newNodeAppend;
            head->next=head;
            tail=newNodeAppend;
        }
        else{
            Node *p=head;
            do{
                p=p->next;
            }while(p->next!=head);
            p->next=newNodeAppend;
            newNodeAppend->next=head;
            tail=newNodeAppend;
            /*while(p->next!=head){
                p=p->next;
            }
            p->next=newNodeAppend;
            newNodeAppend->next=head;*/
        }
    }
    void push(int newData){
        Node *newNodePush=new Node();
        newNodePush->data=newData;
        newNodePush->next=head;
        tail->next=newNodePush;
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
            cout<<"Lis Index out of Range.\n";
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
            p->next=newNodeInsert;
        }

    }
    void deleteFirst(){
        Node *p=head;
        tail->next=p->next;
        head=head->next;
        free(p);
    }
    void deleteLast(){
        Node *p=head;
        while(p->next->next!=head){
            p=p->next;
        }
        tail=p;
        p=p->next;
        tail->next=head;
        free(p);
        
    }
    void deleteNode(int pos){
        if(pos==1){
            deleteFirst();
        }
        else if(pos==count()){
            deleteLast();
        }
        else if(pos<=0||pos>count()){
            cout<<"List Index out of Range.\n";
        }
        else{
            Node *temp,*p=head;
            int i=1;
            while(i<pos){
                temp=p;
                p=p->next;
                i++;
            }
            temp->next=p->next;
            free(p);
        }
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
    int count(){
        int count=0;
        Node *p=head;
        do{
            count++;
            p=p->next;
        }while(p!=head);
        return count;
    }
    void printList(){
        Node *p=head;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
    }
    private:
    Node *head=NULL;
    Node *tail=NULL;
};

int main(){
    Csll a;
    cout<<"Append Concept.\n";
    a.append(8);
    a.append(9);
    a.append(10);
    a.printList();
    cout<<endl;
    cout<<"Push Concept.\n";
    a.push(3);
    a.push(2);
    a.printList();
    cout<<"\n";
    cout<<"Insert Concept.\n";
    a.insert(3,4);
    a.insert(4,5);
    a.insert(1,9);
    a.insert(9,100);
    a.insert(10,0);
    a.insert(5,183);
    a.printList();
    cout<<"\n";
    cout<<"Delete First Concept.\n";
    a.deleteFirst();
    a.deleteFirst();
    a.printList();
    cout<<endl;
    cout<<"Delete Last Concept.\n";
    a.deleteLast();
    a.deleteLast();
    a.printList();
    cout<<endl;
    cout<<"Delete Anywhere Concept.\n";
    a.deleteNode(2);
    a.deleteNode(3);
    a.deleteNode(1);
    a.deleteNode(4);
    a.printList();
    cout<<endl;
    cout<<"Search Concept.\n";
    a.search(9);
}
