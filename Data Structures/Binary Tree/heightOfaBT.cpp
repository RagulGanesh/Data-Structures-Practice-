#include<iostream>
#include "createBT.h"
using namespace std;
int heightOfBT(Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(heightOfBT(root->left),heightOfBT(root->right))+1;
    }
}
int main(){
    BT a;
    a.createTree(1);
    cout<<"Height of Binary Tree is : \n";
    cout<<heightOfBT(a.parent);
}