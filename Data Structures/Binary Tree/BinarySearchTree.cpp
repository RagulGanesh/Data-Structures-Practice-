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
    Node* insertNode(Node *p,int data){
        if(p==NULL){
            Node *root=new Node(data);
            return root;
        }
        else{
            if(data<p->data){
                p->left=insertNode(p->left,data);
            }
            else{
                p->right=insertNode(p->right,data);
            }

        }   

        return p;     
                
    }
    void inOrder(Node *p){
        if(p==NULL){
            return;
        }
        else{
            inOrder(p->left);
            cout<<p->data<<" ";
            inOrder(p->right);
        }
    }
};
int main(){
    BT a;
    Node *root=NULL;
    root=a.insertNode(root,10);
    a.insertNode(root,8);
    a.insertNode(root,12);
    a.insertNode(root,6);
    a.insertNode(root,9);
    a.insertNode(root,11);
    a.insertNode(root,13);
    a.inOrder(root);
}