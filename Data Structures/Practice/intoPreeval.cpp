#include<iostream>
#include "stacks.h"
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
    Stack a(exp.length());
    string result="";
    for(int i=exp.length()-1;i>=0;i--){
        if(isalpha(exp[i])){
            result+=exp[i];
        }
        else if(exp[i]==')'){
            a.push(')');
        }
        else if(exp[i]=='('){
            while(a.peak()!=')'){
                result+=a.pop();
            }
            a.pop();
        }
        else{
            while(precedence(exp[i])<precedence(a.peak())){
                result+=a.pop();
            }
            a.push(exp[i]);
        }
    }
    while(!a.isEmpty()){
        result+=a.pop();
    }
    return result;
}
int evaluate(string exp){
    Stack b(exp.length());
    int num;
    for(int i=exp.length()-1;i>=0;i--){
        if(isalpha(exp[i])){
            cout<<"Enter the value of "<<exp[i]<<" ";
            cin>>num;
            b.push(num);
        }
        else{
            int x=b.pop();
            int y=b.pop();
            switch(exp[i]){
                case '*':
                b.push(x*y);
                break;
                case '/':
                b.push(x/y);
                break;
                case '+':
                b.push(x+y);
                break;
                case '-':
                b.push(x-y);
                break;
                default :
                break;
            }
        }
    }
    return b.peak();
}
int main(){
    string e;
    cout<<"Enter an expression : ";
    cin>>e;
    string r=inToPost(e);
    string c;
    for(int i=r.length()-1;i>=0;i--){
        c+=r[i];
    }
    int result=evaluate(c);
    cout<<"Result is "<<result;
}