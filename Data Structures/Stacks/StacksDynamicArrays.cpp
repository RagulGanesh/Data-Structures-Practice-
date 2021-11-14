#include<iostream>
using namespace std;
class Stack{
    public:
    void push(int newData){
        if(top==max-1){
            cout<<"Overflow Error!\n";
        }
        else{
            p[++top]=newData;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Underflow Error!\n";
        }
        else{
            cout<<p[top]<<" is removed from the stack.\n";
            top--;
        }
    }
    void peak(){
        if(top==-1){
            cout<<"Underflow Error!\n";
        }
        else{
            cout<<"Peak Value : "<<p[top]<<"\n";
        }
    }
    void display(){
        if(top==-1){
            cout<<"Underflow Error!\n";
        }
        else{
                for(int i=top;i>=0;i--){
                cout<<p[i]<<" ";
            }
            cout<<"\n";

        }        

    }
    void input(){
        int sizeOfStack;
        cout<<"Enter the size of the stack : ";
        cin>>sizeOfStack;
        max=sizeOfStack;
        p=new int[max];
    }
    int *p;
    int top=-1;
    int max;        
};
int main(){
    Stack a;
    a.input();
    int choice=1,data,opt;
    cout<<"Enter elements in the stack : \n";
    cout<<"Press 1 for push / 0 to exit : \n";
    while(true){
        cout<<"Enter data : ";
        cin>>data;
        a.push(data);
        cout<<"Enter choice : ";
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
    
    return 0;
}