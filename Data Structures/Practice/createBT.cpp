#include<iostream>
using namespace std;
class Node{
    public:
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
    Node *left,*right;
    int data;
};
class BT{
    public:
    Node *createTree(int data){
        Node *root=new Node(data);
        if(data==0){
            return NULL;
        }
        int key;
        cout<<"Enter left of "<<root->data<<":";
        cin>>key;
        root->left=createTree(key);
        cout<<"Enter right of "<<root->data<<":";
        cin>>key;
        root->right=createTree(key);
        parent =root;
        return root;
    }
    void inOrder(Node *p){
        if(p!=NULL){
            inOrder(p->left);
            cout<<p->data<<" ";
            inOrder(p->right);
        }
    }
    Node *parent=NULL;
};
int main(){
    BT a;
    a.createTree(4);
    a.inOrder(a.parent);
}