#include<iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
class Dll{
    public:
    void append(int newData){
        Node *newNodeAppend=new Node();
        newNodeAppend->data=newData;
        if(head==NULL&&tail==NULL){
            head=newNodeAppend;
            tail=newNodeAppend;
            newNodeAppend->next=NULL;
            newNodeAppend->prev=NULL;
        }
        else{
            Node *p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            newNodeAppend->prev=p;
            newNodeAppend->next=NULL;
            p->next=newNodeAppend;
            tail=newNodeAppend;
        }
    }
    void push(int newData){
        Node *newNodePush=new Node();
        newNodePush->data=newData;
        newNodePush->prev=NULL;
        newNodePush->next=head;
        head=newNodePush;
    }
    void insert(int pos,int newData){
        Node *newNodeInsert=new Node();
        newNodeInsert->data=newData;
        if(pos==1){
            push(newData);
        }
        else if(pos==count()+1){
            append(newData);
        }
        else if(pos>count()+1||pos<=0){
            cout<<"List Index out of Range.\n";
        }
        else{
            Node *p=head;
            for(int i=1;i<pos-1;i++){
                p=p->next;
            }
            newNodeInsert->next=p->next;
            newNodeInsert->prev=p;
            p->next->prev=newNodeInsert;
            p->next=newNodeInsert;
        }

    }
    void deleteFirst(){
        Node *p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    void deleteLast(){
        Node *p=tail;
        tail=tail->prev;
        tail->next=NULL;
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
            cout<<"List Index Out of Range.\n";
        }
        else{
            Node *temp=NULL,*p=head;
            int i=1;
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
    int count(){
        Node *p;
        int count=0;
        for(p=head;p!=NULL;p=p->next){
            count++;
        }
        return count;
    }
    void search(int element){
        Node *p;
        int flag=0;
        for(p=head;p!=NULL;p=p->next){
            if(p->data==element){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"Found.\n";
        }
        else{
            cout<<"Not Found.\n";
        }
    }
    void printList(){
        Node *p;
        for(p=head;p!=NULL;p=p->next){
            cout<<p->data<<" ";
        }
    }
    private:
    Node *head=NULL;
    Node *tail=NULL;
};
int main(){
    Dll a;
    cout<<"Append Concept.\n";
    a.append(5);
    a.append(6);
    a.append(7);
    a.append(8);
    a.printList();
    cout<<endl;
    cout<<"Push Concept.\n";
    a.push(100);
    a.push(200);
    a.push(300);
    a.printList();
    cout<<"\n";
    cout<<"Insert Concept.\n";
    a.insert(1,13);
    a.insert(9,13);
    a.insert(5,13);
    a.printList();
    cout<<"\n";
    cout<<"Delete First.\n";
    a.deleteFirst();
    a.printList();
    cout<<"\n";
    cout<<"Delete Last Concept.\n";
    a.deleteLast();
    a.printList();
    cout<<"\n";
    cout<<"Delete Anywhere Concept.\n";
    a.deleteNode(2);
    a.deleteNode(3);
    a.deleteNode(1);
    a.deleteNode(5);
    a.deleteNode(2);
    a.printList();
    cout<<endl;
    cout<<"Search Concept.\n";
    a.search(100);
    a.printList();
}