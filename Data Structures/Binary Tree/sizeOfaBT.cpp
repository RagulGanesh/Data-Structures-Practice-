#include<iostream>
#include "createBT.h"
using namespace std;
int size(Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int left=size(root->left);
        int right=size(root->right);
        return left+right+1;
    }
}
int main(){
    BT a;
    a.createTree(1);
    cout<<"Size of a Binary Tree is : \n";
    cout<<size(a.parent);
}