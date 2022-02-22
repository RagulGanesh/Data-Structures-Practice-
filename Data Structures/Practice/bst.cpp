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
class BST{
    public:
    Node *insertNode(Node *p,int data){
        if(p==NULL){
            Node *root=new Node(data);
            return root;
        }
        else if(data<p->data){
            p->left=insertNode(p->left,data);
        }
        else if(data>p->data){
            p->right=insertNode(p->right,data);
        }
        return p;
    }
    bool search(Node *p,int data){
        if(p==NULL){
            return false;
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
        if(p!=NULL){
            inOrder(p->left);
            cout<<p->data<<" ";
            inOrder(p->right);
        }
    }
    Node *findMax(Node *root){
        if(root==NULL){
            return NULL;
        }
        else if(root->right==NULL){
            return root;
        }
        else{
            findMax(root->right);
        }
    }
    Node *deleteNode(Node *p,int data){
        Node *temp;
        if(p==NULL){
            cout<<"No elements";
        }
        else if(data<p->data){
            p->left=deleteNode(p->left,data);
        }
        else if(data>p->data){
            p->right=deleteNode(p->right,data);
        }
        else{
            if(p->left&&p->right){
                temp=findMax(p->left);
                p->data=temp->data;
                p->left=deleteNode(p->left,p->data);
            }
            else{
                temp=p;
                if(p->left==NULL){
                    p=p->right;
                }
                else{
                    p=p->right;
                }
                free(temp);
            }
        }
        return p;
    }
};
int main(){
    BST a;
    int num;
    cout<<"Enter the value of root node : ";
    cin>>num;
    Node *root=NULL;
    root=a.insertNode(root,num);
    int choice=1;
    while (true)
    {
        cout<<"Enter data : ";
        cin>>num;
        a.insertNode(root,num);
        cout<<"Enter choice : ";
        cin>>choice;
        if(choice==0){
            break;
        }
    }
    int op,num1;
    cout<<"ENter 1,2,3,4,5";

    while(true){
            cout<<"Enter option : ";
    cin>>op;
        if(op==1){
            cout<<"Enter data : ";
            cin>>num1;
            a.insertNode(root,num1);
        }
        else if(op==2){
            cout<<"Enter element to be searched : ";
            cin>>num1;
            if(a.search(root,num1)){
                cout<<"Element found";
            }
            else{
                cout<<"Element not found";
            }
        }
        else if(op==3){
            cout<<"Enter the element to be deleted : ";
            cin>>num1;
            if(num1==root->data){
                root=a.deleteNode(root,num1);
            }
            else{
                a.deleteNode(root,num1);
            }
        }
        else if(op==4){
            a.inOrder(root);
        }
        else if(op==5){
            break;
        }
    }
    
}