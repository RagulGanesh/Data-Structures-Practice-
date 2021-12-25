#include<iostream>
using namespace std;
class Node{
    public:
    Node(int d){
        data=d;
        left=right=NULL;
    }
    Node *left;
    int data;
    Node *right;
};
class BT{
    public:
    Node* createTree(int data){ 
        Node *root=new Node(data);
        if(data==0){
            return NULL;
        }
        else{
            cout<<"Enter left for "<<root->data<<" ";
            cin>>data;
            root->left=createTree(data);
            cout<<"Enter right for "<<root->data<<" ";
            cin>>data;
            root->right=createTree(data);
        }
        parent=root;
        return root;
    }
    Node *parent=NULL;
};