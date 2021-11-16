#include<iostream>
#include "stack.h"
using namespace std;
void parenMatch(){
    Stack a;
    string e;
    int flag=0;
    cout<<"Enter the expression : ";
    cin>>e;
    a.max=e.length();
    //Parentheses Matching
    for(int i=0;i<e.length();i++){
        //cout<<"In for loop";
        if(e[i]=='('){
            if(a.top==a.max-1){
                cout<<"Overflow Error";
            }
            else{
                a.push('(');
            }
        }
        if(e[i]==')'){
            if(a.top==-1){
                cout<<"Right Parentheses are more! :(";
                flag=1;
                break;
            }
            else{
                a.pop();
            }
        }
    }
    
    if(a.top!=-1){
        cout<<"Left Parentheses are more! :(";
        flag=1;
    }
    if(flag==0){
        cout<<"Valid Expression :)";
    }
    
}
int main(){
    parenMatch();
}