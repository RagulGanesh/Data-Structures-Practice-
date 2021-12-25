#include<iostream>
#include "createBT.h"
#include "limits.h"
using namespace std;
int calMax(Node *root){
    if(root==NULL){
        return INT_MIN;
    }
    else{
        return max(max(root->data,calMax(root->left)),max(root->data,calMax(root->right)));        
    }
}
int calMin(Node *root){
    if(root==NULL){
        return INT_MAX;
    }
    else{
        return min(min(root->data,calMin(root->left)),min(root->data,calMin(root->right)));        
    }
}
int main(){
    BT a;
    a.createTree(1);
    cout<<"Maximum is : ";
    cout<<calMax(a.parent);
    cout<<"\nMinimum is : "<<calMin(a.parent);
}