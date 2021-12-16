#include<iostream>
#include "stack.h"
using namespace std;
int cp(char a){
    if(a=='^'){
        return 5;
    }
    else if(a=='*'||a=='/'){
        return 4;
    }
    else if(a=='+'||a=='-'){
        return 3;
    }
    else{
        return 2;
    }
}
string inToPost(string e){
    string res;
    Stack a;
    for(int i=0;i<e.length();i++){
        if(isdigit(e[i])){
            res+=e[i];
        }
        else if(e[i]=='('){
            a.push(e[i]);
        }
        else if(e[i]==')'){
            while(a.peak()!='('){
                res+=a.pop();
                //a.pop();
            }
            a.pop();
        }
        else{
            while(cp(a.peak())>=cp(e[i])){
                res+=a.pop();
            }
            a.push(e[i]);
        }
    }
    while(a.peak()!=0){
        res+=a.pop();
    }
    return res;
}
int cal(int a,int b,char c){
    if(c=='/'){
        return b/a;
    }
    else if(c=='*'){
        return b*a;
    }
    else if(c=='+'){
        return b+a;
    }
    else{
        return b-a;
    }
}
int evaluate(string e){
    Stack a;
    for(int i=0;i<e.length();i++){
        if(isdigit(e[i])){
            a.push(e[i]-'0');
        }
        else{
            int x=a.pop();
            int y=a.pop();
            int z=cal(x,y,e[i]);
            a.push(z);
        }
    }
    return a.peak();
}
int main(){
    cout<<"Enter an expression : ";
    string inp;
    cin>>inp;
    cout<<inToPost(inp);
    cout<<"\n";
    cout<<evaluate(inToPost(inp));
}
