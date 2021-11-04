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
    void deleteAllNode(){
        Node *temp=NULL,*p=head;
        while(p!=NULL){
            temp=p;
            p=p->next;
            free(temp);
        }
        head=NULL;
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
    int choice=1,data,opt,pos;
    while(true){
        cout<<"Enter elements in the DLL : ";
        cin>>data;
        a.append(data);
        cout<<"Enter choice : ";
        cin>>choice;
        if(choice==0){
            break;
        }
    }
    cout<<"Enter 1 to append, 2 to push, 3 to insert, 4 to delete, 5 to print, 6 to count, 7 to search, 8 to exit : "<<endl;
    while(true){
        cout<<"Enter choice : ";
        cin>>opt;
        if(opt==1){
            cout<<"Enter the data to be appended : ";
            cin>>data;
            a.append(data);
        }
        else if(opt==2){
            cout<<"Enter the data to be pushed : ";
            cin>>data;
            a.push(data);
        }
        else if(opt==3){
            cout<<"Enter the position to be inserted : ";
            cin>>pos;
            cout<<"Enter the data to be inserted : ";
            cin>>data;
            a.insert(pos,data);
        }
        else if(opt==4){
            cout<<"Enter the position to be deleted : ";
            cin>>pos;
            a.deleteNode(pos);
        }
        else if(opt==5){
            a.printList();
            cout<<endl;
        }
        else if(opt==6){
            cout<<"There are a total of "<<a.count()<<" nodes in the list.\n";
        }
        else if(opt==7){
            cout<<"Enter the data to be searched : ";
            cin>>data;
            a.search(data);
        }
        else{
            a.deleteAllNode();
            break;
        }
    }
    /*cout<<"\n";
    a.printList();
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
    a.printList();*/
}