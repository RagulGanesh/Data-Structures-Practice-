#include<iostream>
using namespace std;
template<class T>
class Node{    
    public:
    Node<T> *next;    
    T data;
};
template<class T>
class Stack{
    public:
    void push(T newData){
        Node<T> *newNodePush=new Node<T>();
        newNodePush->data=newData;
        if(top==NULL){
            newNodePush->next=top;
            top=newNodePush;
        }
        else{
            newNodePush->next=top;
            top=newNodePush;
        }
    }
    T pop(){
        T data;
        if(top==NULL){
            cout<<"Stack Underflow Error.";
        }
        else{
            
            Node<T> *p=top;
            data=p->data;
            top=top->next;
            free(p);
        }
        return data;
    }
    T peek(){
        if(top==NULL){
            cout<<"Stack Underflow Error.";
        }
        else{
            return top->data;
        }
    }
    void display(){
        if(top==NULL){
            cout<<"Stack Underflow.";
        }
        else{
            Node<T> *p=top;
            while(p!=NULL){
                cout<<p->data<<" ";
                p=p->next;
            }
        }
    }
    Node<T> *top=NULL;
    // void push(T newData){
    //     if(top==max-1){
    //         cout<<"Stack overflow error.";
    //     }
    //     else{
    //         p[++top]=newData;
    //     }
    // }
    // T pop(){
    //     if(top==-1){
    //         cout<<"Stack Underflow Error.";
    //     }
    //     else{
    //         return p[top--];
    //     }
    // }
    // T peak(){
    //     if(top==-1){
    //         cout<<"Stack Underflow error.";
    //     }
    //     else{
    //         return p[top];
    //     }
    // }
    // void display(){
    //     Node<T> *p=top;
    //     while(p!=NULL){
    //         cout<<p->data<<" ";
    //     }
    // }
    // void display(){
    //     for(int i=top;i>=0;i--){
    //         cout<<p[i]<<" ";
    //     }
    // }
    // T *p=new T[max];
    // int max;
    // int top=-1;
};
int main(){
    Stack<int> a;
    a.push(5);
    a.push(5);
    a.push(5);
    a.display();
}