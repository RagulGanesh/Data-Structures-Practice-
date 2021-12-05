#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
    T data;
    Node *next;
};
template<class T>
class Queue{
    public:
    void enqueue(int data){
        Node<T> *newNodeInsert=new Node<T>();
        newNodeInsert->data=data;
        if(front==NULL){
            newNodeInsert->next=NULL;
            front=newNodeInsert;
            rear=newNodeInsert;
        }
        else{
            newNodeInsert->next=NULL;
            rear->next=newNodeInsert;
            rear=rear->next;
        }
    }
    T dequeue(){
        int ele;
        if(front==NULL){
            cout<<"Queue is empty.";
        }
        else{
            Node<T> *temp;
            ele=front->data;
            temp=front;
            front=front->next;
            free(temp);
        }

        return ele;
    }
    void display(){
        Node<T>* temp;
        if(front==NULL){
            cout<<"Queue is empty.";
        }
        else{
                for(temp=front;temp!=NULL;temp=temp->next){
                    cout<<temp->data<<" ";
            }
        }

    }
    private:
    Node<T> *front=NULL;
    Node<T> *rear=NULL;
    
};

int main(){
    Queue<int> a;
    int choice=1,data,opt;
    cout<<"Enter non-zero number to continue else zero to stop\n";
    while(true){
        cout<<"Enter data : ";
        cin>>data;
        a.enqueue(data);
        cout<<"Enter choice : ";
        cin>>choice;
        if(choice==0){
            break;
        }
    }
    cout<<"Enter 1 to insert, 2 to remove, 3 to print, 4 to exit.\n";
    while(true){
        cout<<"Enter option : ";
        cin>>opt;
        if(opt==1){
            cout<<"Enter data : ";
            cin>>data;
            a.enqueue(data);
        }
        else if(opt==2){
            a.dequeue();
        }
        else if(opt==3){
            a.display();
        }
        else if(opt==4){
            break;
        }
    }
}


