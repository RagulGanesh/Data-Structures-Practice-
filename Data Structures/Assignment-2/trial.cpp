#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
    Node *left;
    int data;
    Node *right;
};
class BST{
    public:
    void insertNode(int a,int b,int c){
    }
    Node *root;
};
int main(){
    //Variables;
    int n;
    cout<<"Enter no of vertices : ";
    cin>>n;
    int a[3][n];
    cout<<"Enter key,left,right : \n";
    for(int i=0;i<n;i++){
        cout<<i+1<<":";
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    BST b;
    
}