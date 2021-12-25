#include <iostream>
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
class BST
{
public:
    Node *insertNode(Node *p, int data)
    {
        if (p == NULL)
        {
            Node *root = new Node(data);
            return root;
        }
        else if (data < p->data)
        {
            p->left = insertNode(p->left, data);
        }
        else if (data > p->data)
        {
            p->right = insertNode(p->right, data);
        }
        return p;
    }

    bool search(Node *p, int key)
    {
        if (p == NULL)
        {
            return false;
        }
        else if (key < p->data)
        {
            search(p->left, key);
        }
        else if (key > p->data)
        {
            search(p->right, key);
        }
        else
        {
            return true;
        }
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
    Node *FindMax(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->right == NULL)
        {
            return root;
        }
        else
        {
            return FindMax(root->right);
        }
    }
    Node *deleteNode(Node *root, int key)
    {
        Node *temp;
        if (root == NULL)
        {
            cout << "Element not Found\n";
        }
        else if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {

            if (root->left && root->right)
            {
                temp = FindMax(root->left);
                root->data = temp->data;
                root->left = deleteNode(root->left, root->data);
            }
            else
            {
                temp = root;

                if (root->left == NULL)
                {
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
                free(temp);
            }
        }
        return root;
    }
};

int main()
{
    BST a;
    Node *root = NULL;
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = a.insertNode(root, data);
    int choice = 1;
    cout << "Enter any non-zero number to continue or zero to stop : \n";
    while (true)
    {
        cout << "Enter data : ";
        cin >> data;
        a.insertNode(root, data);
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
    }

    cout << "Enter 1 to search, 2 to print inorder, 3 to delete, 4 to insert, 5 to exit : \n";

    int key;
    while (true)
    {
        cout << "Enter option : ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter element to be searched : ";
            cin >> key;
            if (a.search(root, key))
            {
                cout << "Found\n";
            }
            else
            {
                cout << "Not Found\n";
            }
        }
        else if (choice == 2)
        {
            if (root == NULL)
            {
                cout << "No elements in the tree\n";
            }
            a.inOrder(root);
            cout << "\n";
        }
        else if (choice == 3)
        {
            cout << "Enter the element to be deleted : ";
            cin >> key;
            if (root == NULL)
            {
                cout << "No elements in the tree\n";
            }
            else if (key == root->data)
            {
                root = a.deleteNode(root, key);
            }
            else
            {
                a.deleteNode(root, key);
            }
        }
        else if (choice == 4)
        {
            cout << "Enter the element to be inserted : ";
            cin >> data;
            if (root == NULL)
            {
                root = a.insertNode(root, data);
            }
            else
            {
                a.insertNode(root, data);
            }
        }
        else
        {
            break;
        }
    }
}
