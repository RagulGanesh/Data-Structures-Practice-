#include<iostream>
#include "stack1.h"
using namespace std;
int precedence(char ch){
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
string inToPost(string exp){
    string result="";
    Stack a(exp.length());
    for(int i=0;i<exp.length();i++){
        if(isalpha(exp[i])){
            result+=exp[i];
        }
        else if(exp[i]=='('){
            a.push('(');
        }
        else if(exp[i]==')'){
            while(a.peak()!='('){
                result+=a.pop();
            }
            a.pop();
        }
        else{
            while(precedence(exp[i])<=precedence(a.peak())){
            result+=a.pop();
        }
        a.push(exp[i]);

        } 
    }
    //if(!a.isEmpty()){
        while(!a.isEmpty()){
            result+=a.pop();
        }
    //}
    return result;
}
int main(){
    cout<<"Enter an expression : ";
    string name;
    cin>>name;
    cout<<inToPost(name);
}
