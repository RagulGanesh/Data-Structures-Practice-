#include<iostream>
using namespace std;
#define MAX 5
int stack[MAX],top=-1;
void push(int newData){
    if(top==MAX-1){
        cout<<"Stack overflow Error!!!\n";
    }
    else{
        stack[++top]=newData;
    }
}
void pop(){
    if(top==-1){
        cout<<"Stack Underflow Error!!!\n";
    }
    else{
        cout<<stack[top]<<" is removed from the stack.\n";
        top--;
    }
}
void peak(){
    if(top==-1){
        cout<<"Stack Underflow Error!!!\n";
    }
    else{
        cout<<"Peak value : "<<stack[top];
    }
}
void display(){
    if(top==-1){
        cout<<"Stack Underflow Error!!!\n";
    }
    else{
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int choice=1,data,opt;
    cout<<"Enter elements in the stack : \n";
    cout<<"Press 1 for push / 0 to exit : \n";
    while(true){
        cout<<"Enter data : ";
        cin>>data;
        push(data);
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
            push(data);
        }
        else if(opt==2){
            pop();
        }
        else if(opt==3){
            peak();
        }
        else if(opt==4){
            display();
        }
        else if(opt==5){
            break;
        }
    }
    
    return 0;
    /*cout<<"Push Concept.\n";
    push(100);
    push(200);
    push(900);
    display();
    cout<<"Pop Concept.\n";
    pop();
    display();
    cout<<"Peak Concept.\n";
    peak();*/
}
