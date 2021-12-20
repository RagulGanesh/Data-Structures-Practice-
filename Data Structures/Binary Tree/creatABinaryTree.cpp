#include<iostream>
using namespace std;
class Node{
    public:
    Node(int d){
        data=d;
        left=right=NULL;
    }
    static Node* createTree(int data){
        int n;
        Node *root=new Node(data);
        if(data==-1){
        }
        else{
            cout<<"Enter data for left of "<<data<<":";
            cin>>n;
            root->left=createTree(n);
            cout<<"Enter data for right of "<<data<<":";
            cin>>n;
            root->right=createTree(n);
        }
        inOrder(root);          
    }
    static void inOrder(Node *p){
        if(p==NULL){
            return;
        }
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
    Node *left;
    int data;
    Node *right;
};
int main(){
    Node::createTree(2);
}