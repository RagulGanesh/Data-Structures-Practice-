#include<iostream>
#include "createBT.h"
using namespace std;
Node *head=NULL;
Node *tail=NULL;
void convertToDLL(Node *root){
    if(root==NULL){
        return;
    }
    convertToDLL(root->left);
    if(tail==NULL){
        head=root;
    }
    else{
        root->left=tail;
        tail->right=root;
    }
    tail=root;
    convertToDLL(root->right);
}
void display(){
    for(Node *p=head;p!=NULL;p=p->right){
        cout<<p->data<<" ";
    }
}
int main(){
    BT a;
    a.createTree(1);
    convertToDLL(a.parent);
    display();
}