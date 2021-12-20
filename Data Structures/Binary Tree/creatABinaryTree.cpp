// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     Node(int d){
//         data=d;
//         left=right=NULL;
//     }
//     static Node* createTree(int data){
//         int n;
//         Node *root=new Node(data);
//         if(data==-1){
//         }
//         else{
//             cout<<"Enter data for left of "<<data<<":";
//             cin>>n;
//             root->left=createTree(n);
//             cout<<"Enter data for right of "<<data<<":";
//             cin>>n;
//             root->right=createTree(n);
//         }
//         inOrder(root);          
//     }
//     static void inOrder(Node *p){
//         if(p==NULL){
//             return;
//         }
//         inOrder(p->left);
//         cout<<p->data<<" ";
//         inOrder(p->right);
//     }
//     Node *left;
//     int data;
//     Node *right;
// };
// int main(){
//     Node::createTree(2);
// }
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
    void preOrder(Node *p){
        if(p==NULL){
            return;
        }
        else{            
            cout<<p->data<<" ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }
    void postOrder(Node *p){
        if(p==NULL){
            return;
        }
        else{
            postOrder(p->left);            
            postOrder(p->right);
            cout<<p->data<<" ";
        }
    }
    Node *parent=NULL;
};
int main(){
    BT a;
    a.createTree(1);
    cout<<"Inorder : ";
    a.inOrder(a.parent);
    cout<<"\n";
    cout<<"Preorder : ";
    a.preOrder(a.parent);
    cout<<"\n";
    cout<<"Postorder : ";
    a.postOrder(a.parent);
    cout<<"\n";
}