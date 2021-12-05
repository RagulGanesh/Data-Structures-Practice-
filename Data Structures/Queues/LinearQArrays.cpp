#include<iostream>
using namespace std;
template<class T>
class Queue{
    public:
    bool IsEmpty(){
        if(front==-1||front>rear){
            return true;
        }
        else{
            return false;
        }
    }
    bool IsFull(){
        if(rear==max-1&&front==0){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(T data){
        if(IsFull()){
            cout<<"Queue is full.";
        }
        else{
            
            if(front==-1){
                front=0;
            }
            rear++;
            p[rear]=data;
        }
    }
    T dequeue(){
        T ele;
        if(IsEmpty()){
            cout<<"Queue is empty.";
        }
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                ele=p[front];
                front++;
            }
            
        }
        return ele;
    }
    void display(){
        if(IsEmpty()){
            cout<<"Queue is Empty.";
        }
        else{
            for(int i=front;i<=rear;i++){
            cout<<p[i]<<" ";
            }
        }

    }
    
    void input(){
        int n;
        cout<<"Enter the size of the queue : ";
        cin>>n;
        max=n;
        p=new T[max];
    }

    T *p;
    int max;
    int front=-1;
    int rear=-1;
};
int main(){
    Queue<int> a;
    a.input();
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
