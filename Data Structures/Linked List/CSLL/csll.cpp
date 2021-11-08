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
        if(head!=NULL){
        do{
            count++;
            p=p->next;
        }while(p!=head);
        }
        return count;
    }
    void printList(){
        Node *p=head;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
    }
    void deleteAllNode(){
        Node *p=head,*temp;
        do{
            temp=p;
            p=p->next;
            free(temp);
        }while(p!=head);
        head=NULL;
        
    }
    private:
    Node *head=NULL;
    Node *tail=NULL;
};

int main(){
    Csll a;
    int choice=1,data,opt,pos;
    while(true){
        cout<<"Enter elements in the CSLL : ";
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
    
    return 0;
    
    /*cout<<"Append Concept.\n";
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
    a.search(9);*/
}


