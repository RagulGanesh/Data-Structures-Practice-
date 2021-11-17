#include<iostream>
#include "stack.h"
using namespace std;
int chkPrecedence(char ch){
    if(ch=='^'){
        return 5;
    }
    else if(ch=='*'||ch=='/'){
        return 4;
    }
    else if(ch=='+'||ch=='-'){
        return 3;
    }
    else{
        return 0;
    }
}
string infixToPostfix(string exp){
    cout<<"in func";
    Stack obj;
    obj.max=exp.length();
    cout<<"created obj";
    string result;
    cout<<"created result";
    char ch;
    for(int i=0;i<exp.length();i++){
        ch=exp[i];
        if(isalpha(ch)){
            result+=ch;
        }
        else if(ch=='('){
            obj.push('(');
        }
        else if(ch==')'){
            while(obj.peak()!='('){
                result+=obj.pop();
            }
            obj.pop();
        }
        else{
            while(chkPrecedence(ch)<=chkPrecedence(obj.peak())){
                result+=obj.pop();
            }
            obj.push(ch);
        }
    }
    while(obj.isEmpty()){
        result+=obj.pop();
    }

    return result;
}
int main(){
    string infix,r;
    cout<<"Enter an infix expression : ";
    cin>>infix;
    r=infixToPostfix(infix);
    cout<<"PostFix Expression : "<<r;
}