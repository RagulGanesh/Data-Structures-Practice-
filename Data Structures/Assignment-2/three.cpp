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
    queue<Node*> temp;
    void add(int a[][]){
        Node *root=new Node(a[0][0]);
        temp.push(root);
        int i=0;
        while(!temp.empty()){
            Node *p=temp.front();
            temp.pop();
            Node *l=new Node(a[i][1]);
            Node *r=new Node(a[i][2]);
            if(l->data==-1){
                l=NULL;
            }
            if(r->data==-1){
                r=NULL;
            }
            p->left=l;
            p->right=r;
            if(l!=NULL){
                temp.push(l);
            }
            if(r!=NULL){
                temp.push(r);
            }
            i++;
        }
    }
    
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
    b.add(a);
    
}