#include<iostream>
#include "stack.h"
using namespace std;
void parenMatch(){
    string exp;
    cout<<"Enter an expression : ";
    cin>>exp;
    Stack a(exp.length());
    int flag=0;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('){
            a.push('(');
        }
        if(exp[i]==')'){
            if(a.top==-1){
                cout<<"Right is more";
                flag=1;
                break;
            }
            else{
                a.pop();
            }
        }
    }
    if(a.isEmpty()==false){
        cout<<"Left is more.";
        flag=1;
    }
    if(flag==0){
        cout<<"Valid expression.";
    }
}
int main(){
    parenMatch();
}