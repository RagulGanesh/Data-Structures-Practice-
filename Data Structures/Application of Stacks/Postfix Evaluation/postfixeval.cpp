#include<iostream>
#include "stack.h"
int chkPrecedence(int ch){
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
    Stack obj;
    string result;
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
int evaluated(int a,int b,char c){
    if(c=='+'){
        return b+a;
    }
    else if(c=='-'){
        return b-a;
    }
    else if(c=='*'){
        return b*c;
    }
    else if(c=='/'){
        return b/c;
    }
}
int postFixEval(string res){
    int len=res.length();
    Stack a;
    char c;
    int result;    
    for(int i=0;i<len;i++){
        c=res[i];
        if(isalpha(c)){
            a.push(c);
        }        
        else{
            int top1,top2;
            top1=a.pop();
            top2=a.pop();
            result=evaluated(top1,top2,c);
            a.push(result);
        }
    }
    return a.peak();
}
int main(){
    string infix,r;
    cout<<"Enter an infix expression : ";
    cin>>infix;
    r=infixToPostfix(infix);
    cout<<postFixEval(r);    

}