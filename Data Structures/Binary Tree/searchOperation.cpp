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
    bool search(Node *p,int data){
        if(p==NULL){
            false;
        }
        else if(data<p->data){
            search(p->left,data);
        }
        else if(data>p->data){
            search(p->right,data);
        }
        else{
            return true;
        }
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
    int n,c;
    cout<<"Enter data : ";
    cin>>n;
    root=a.insertNode(root,n);
    cout<<"Enter 1 to continue else 0 to stop : \n";
    while(true){
        cout<<"Enter data : ";
        cin>>n;
        a.insertNode(root,n);
        cout<<"Enter choice : ";
        int c;
        cin>>c;
        if(c==0){
            break;
        }

    }    
    // a.insertNode(root,8);
    // a.insertNode(root,12);
    // a.insertNode(root,6);
    // a.insertNode(root,9);
    // a.insertNode(root,11);
    // a.insertNode(root,13);
    cout<<"InOrder : ";
    a.inOrder(root);
    int key;
    cout<<"\nEnter an element you want to search for : ";
    cin>>key;
    if(a.search(root,key)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}