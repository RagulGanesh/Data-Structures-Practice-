// #include<iostream>
// #include "stack.h"
// using namespace std;
// int cp(char a){
//     if(a=='^'){
//         return 5;
//     }
//     else if(a=='*'||a=='/'){
//         return 4;
//     }
//     else if(a=='+'||a=='-'){
//         return 3;
//     }
//     else{
//         return 2;
//     }
// }
// string inToPost(string e){
//     string res;
//     Stack a;
//     for(int i=0;i<e.length();i++){
//         if(isdigit(e[i])){
//             res+=e[i];
//         }
//         else if(e[i]=='('){
//             a.push(e[i]);
//         }
//         else if(e[i]==')'){
//             while(a.peak()!='('){
//                 res+=a.pop();
//                 //a.pop();
//             }
//             a.pop();
//         }
//         else{
//             while(cp(a.peak())>=cp(e[i])){
//                 res+=a.pop();
//             }
//             a.push(e[i]);
//         }
//     }
//     while(a.peak()!=0){
//         res+=a.pop();
//     }
//     return res;
// }
// int cal(int a,int b,char c){
//     if(c=='/'){
//         return b/a;
//     }
//     else if(c=='*'){
//         return b*a;
//     }
//     else if(c=='+'){
//         return b+a;
//     }
//     else{
//         return b-a;
//     }
// }
// int evaluate(string e){
//     Stack a;
//     for(int i=0;i<e.length();i++){
//         if(isdigit(e[i])){
//             a.push(e[i]-'0');
//         }
//         else{
//             int x=a.pop();
//             int y=a.pop();
//             int z=cal(x,y,e[i]);
//             a.push(z);
//         }
//     }
//     return a.peak();
// }
// int main(){
//     cout<<"Enter an expression : ";
//     string inp;
//     cin>>inp;
//     cout<<inToPost(inp);
//     cout<<"\n";
//     cout<<evaluate(inToPost(inp));
// }
#include<iostream>
using namespace std;
class Node{
    public:
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
    int data;
    Node *left,*right;
};
class BST{
    public:
    Node *search(Node *root,int data){
        if(root==NULL){
            cout<<"No element found\n";
        }
        else if(data<root->data){
            search(root->left,data);
        }
        else if(data>root->data){
            search(root->right,data);
        }
        else{
            cout<<"Element found\n";
        }
    }
    
    Node *insert(Node *root,int data){
        if(root==NULL){
            Node *newNode=new Node(data);
            return newNode;
        }
        else if(data<root->data){
            root->left=insert(root->left,data);
        }
        else{
            root->right=insert(root->right,data);
        }

        return root;
    }
    Node *FindMax(Node *root){
        if(root==NULL){
            return NULL;
        }
        else if(root->right==NULL){
            return root;
        }
        else{
            FindMax(root->right);
        }
    }
    Node *deleteNode(Node *root,int data){
        Node *temp;
        if(root==NULL){
            cout<<"Element not present\n";
        }
        else if(data<root->data){
            root->left=deleteNode(root->left,data);
        }
        else if(data>root->data){
            root->right=deleteNode(root->right,data);
        }
        else{
            if(root->right&&root->left){
                temp=FindMax(root->left);
                root->data=temp->data;
                root->left=deleteNode(root->left,root->data);
            }
            else{
                temp=root;
                if(root->left==NULL){
                    root=root->right;
                }
                else{
                    root=root->left;
                }
                free(temp);
            }
        }

        return root;
    }
    void inOrder(Node *root){
        if(root==NULL){
            return;
        }
        else{
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
    }
};
int main(){
    BST a;
    Node *root=NULL;
    root=a.insert(root,4);
    a.insert(root,5);
    a.insert(root,6);
    a.insert(root,7);
    a.insert(root,3);
    a.insert(root,1);
    a.deleteNode(root,7);
    root=a.deleteNode(root,4);
    a.deleteNode(root,3);
    a.inOrder(root);
}