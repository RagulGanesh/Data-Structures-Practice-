#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    public:
    void push(int newData){
        Node *newNodePush=new Node();
        newNodePush->data=newData;
        if(top==NULL){
            newNodePush->next=NULL;
            top=newNodePush;
        }
        else{
            newNodePush->next=top;
            top=newNodePush;
        }
    }
    void pop(){
        Node *p=top,*temp;
        if(top==NULL){
            cout<<"Stack Underflow!!!";
        }
        else{
            temp=top;
            top=top->next;
            free(temp);
        }

    }
    void peak(){
        if(top==NULL){
            cout<<"Stack Underflow!!!";
        }
        else{
            cout<<"Peak value : "<<top->data<<"\n";
        }
    }
    void display(){
        Node *p=top;
        if(top==NULL){
            cout<<"Stack Underflow!!!";
        }
        else{
            while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
            
        }

        cout<<"\n";
    }
    private:
    Node *top=NULL;
};
int main(){
    Stack a;
    int choice=1,data,opt;
    cout<<"Enter elements in the stack : \n";
    cout<<"Press 1 to push / 0 to stop \n";
    while(true){
        cout<<"Data : ";
        cin>>data;
        a.push(data);
        cout<<"Choice : ";
        cin>>choice;
        if(choice==0){
            break;
        }
    }
    cout<<"Enter 1 to push, 2 to pop, 3 to know the peak value,4 to print, 5 to exit : \n";
    while(true){
        cout<<"Enter opt : ";
        cin>>opt;
        if(opt==1){
            cout<<"Enter data : ";
            cin>>data;
            a.push(data);
        }
        else if(opt==2){
            a.pop();
        }
        else if(opt==3){
            a.peak();
        }
        else if(opt==4){
            a.display();
        }
        else if(opt==5){
            break;
        }
    }
    /*cout<<"Push Concept.\n";
    a.push(3);
    a.push(100);
    a.push(500);
    a.push(600);
    a.display();
    cout<<"Pop Concept.\n";
    a.pop();
    a.display();
    cout<<"Peak Concept.\n";
    a.peak();*/
    return 0;
}
