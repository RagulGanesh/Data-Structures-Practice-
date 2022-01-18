#include <iostream>
#include<stdio.h>
#include <cstdlib>
using namespace std;
class Node
{
public:
    Node(int key, int level)
    {
        //cout<<"In Node";
        this->key = key;
        forward = new Node *[level + 1];
        for (int i = 0; i < level + 1; i++)
        {
            forward[i] = NULL;
        }
    }
    int key;
    Node **forward;
};
class SkipList
{
public:
    SkipList(int maxLevel, float P)
    {
        //cout<<"In constructor";
        this->maxLevel = maxLevel;
        this->P = P;
        level = 0;
        header = new Node(-1, maxLevel);
    }
    int randomLevel()
    {
        float a = (float)rand() / RAND_MAX;
        int lvl = 0;
        while (a < P && lvl < maxLevel)
        {
            lvl++;
            a = (float)rand() / RAND_MAX;
        }
        return lvl;
    }
    int searchKey(int key)
    {
        Node *current = header;
        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != NULL && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
        }
        current = current->forward[0];
        if (current && current->key == key)
        {
            cout << key << " Found\n";
        }
        else
        {
            cout << key << " not found\n";
        }
    }
    void insertKey(int key)
    {
        //cout<<"In insert key";
        Node *current = header;
        Node *update[maxLevel + 1];
        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != NULL && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }
        current = current->forward[0];
        if (current == NULL || current->key != key)
        {
            int rlevel = randomLevel();
            if (rlevel > level)
            {
                for (int i = level + 1; i < rlevel + 1; i++)
                {
                    update[i] = header;
                }
                level = rlevel;
            }
            Node *n = new Node(key, rlevel);
            for (int i = 0; i <= rlevel; i++)
            {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
            cout << "Successfully Inserted key " << key << "\n";
        }
        return;
    }
    void displayList()
    {
        for (int i = 0; i <= level; i++)
        {
            Node *nn = header->forward[i];
            cout << "Level " << i << ":";
            while (nn != NULL)
            {
                cout << nn->key << " ";
                nn = nn->forward[i];
            }
            cout << "\n";
        }
    }
    int level;
    Node *header;
    float P;
    int maxLevel;
};

int main()
{
    //srand((unsigned)time(0));
    //cout<<"Hello";
    int l;
    float pro;
    int opt,key,data;
    cout<<"Enter skip list level : ";
    cin>>l;
    cout<<"Enter skip list probability : ";
    cin>>pro;
    SkipList a(l,pro);
    cout<<"Enter 1 to insert,2 to search,3 to print,4 to exit :\n";
    while(1){
        cout<<"Enter option : ";
        cin>>opt;
        if(opt==1){
            cout<<"Enter data : ";
            cin>>data;
            a.insertKey(data);
        }
        else if(opt==2){
            cout<<"Enter search key : ";
            cin>>key;
            a.searchKey(key);
        }
        else if(opt==3){
            a.displayList();
        }
        else{
            break;
        }
    }
    
    return 0;
    //a.insertKey(7);
    //a.insertKey(8);
    //a.insertKey(9);
    //a.insertKey(15);
    //a.searchKey(9);
    //a.searchKey(10);
    //a.displayList();
}

