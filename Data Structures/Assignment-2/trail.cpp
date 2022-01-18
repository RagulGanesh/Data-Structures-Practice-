#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    Node *left;
    int data;
    Node *right;
};

queue<Node *> temp;
Node *BT(int a[][3])
{
    Node *root = new Node(a[0][0]);
    temp.push(root);
    int i = 0;
    while (!temp.empty())
    {
        Node *p = temp.front();
        temp.pop();
        Node *l = new Node(a[i][1]);
        Node *r = new Node(a[i][2]);
        if (l->data == -1)
        {
            l = NULL;
        }
        if (r->data == -1)
        {
            r = NULL;
        }
        p->left = l;
        p->right = r;
        if (l != NULL)
        {
            temp.push(l);
        }
        if (r != NULL)
        {
            temp.push(r);
        }
        i++;
    }
    return root;
}
void inOrder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}
void preOrder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
}
void postOrder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}
bool chkForBst(Node *root){
    int flag;
    if(root==NULL){
        return true;
    }
   if (root->left != NULL && root->left->data > root->data)
    return 0;
     
  /* false if right is < than node */
  if (root->right != NULL && root->right->data < root->data)
    return 0;
   
  /* false if, recursively, the left or right is not a BST */
  if (!chkForBst(root->left) || !chkForBst(root->right))
    return 0;
     
  /* passing all that, it's a BST */
  return 1;
}
int main()
{
    // Variables;
    int n;
    cout << "Enter no of vertices : ";
    cin >> n;
    int a[n][3];
    cout << "Enter key,left,right : \n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ":";
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    Node *r;
    r = BT(a);
        if(chkForBst(r)){
        cout<<"It is a BST\n";
    }
    else{
        cout<<"It is not a BST\n";
    }
    cout<<"InOrder : ";
    inOrder(r);
    cout<<"\n";
    cout<<"PostOrder : ";
    postOrder(r);
    cout<<"\n";
    cout<<"PreOrder : ";
    preOrder(r);

}