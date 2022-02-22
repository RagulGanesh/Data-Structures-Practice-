#include <iostream>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node *next;
};

template <class T>
class stack{
    public:
        void push(T val){
            node <T> *n = new node <T> ();
            n->data = val;
            if(top==NULL){
                top = n;
            }
            else{
                n->next = top;
                top = n;
            }
            
        }

        T pop(){
            if(top==NULL){
                cout << "stack underflow" << endl;
                return 0;
            }
            else{
                T d = top->data;
                top = top->next;
                return d;
            }
        }

        T peek(){
            return top->data;
        }

        void Display(){
            if(top==NULL){
                cout << "stack underflow" << endl;
            }
            else{
                node <T> *ptr = top;
                while(ptr!=NULL){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
                cout << endl;
            }
        }

        bool isempty(){
            if(top==NULL)
                return true;
            else
                return false;
        }
    
    private:
        node <T> *top = NULL;
};
