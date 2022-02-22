#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int key;
    Node **forward;
    Node(int key, int level)
    {
        this->key = key;
        forward = new Node *[level + 1];
        for (int i = 0; i < level + 1; i++)
        {
            forward[i] = NULL;
        }
    }
};
class SkipList
{
public:
    float P;
    int level;
    int maxlevel;
    Node *header;
    SkipList(int maxlevel, float P)
    {
        this->maxlevel = maxlevel;
        this->P = P;
        level = 0;
        header = new Node(-1, maxlevel);
    }
    int randomlevel()
    {
        float a = (float)rand() / RAND_MAX;
        int lvl = 0;
        while (a < P && lvl < maxlevel)
        {
            lvl++;
            a = (float)rand() / RAND_MAX;
        }
        return lvl;
    }
    void search(int key)
    {
        Node *current = header;
        for (int i = 0; i <= level; i++)
        {
            while (current->forward[i] != NULL && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
        }
        current = current->forward[0];
        if (current && current->key == key)
        {
            cout << "Found";
        }
        else
        {
            cout << "Not Found";
        }
    }
    void insertKey(int key)
    {
        Node *current = header;
        Node *update[maxlevel + 1];
        for (int i = 0; i <= level; i++)
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
            int rlevel = randomlevel();
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
            cout<<"Inserted "<<key<<"\n";
        }
        return;
    }
    void display()
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
};
int main(){
    SkipList a(4,0.5);
    a.insertKey(3);
    a.insertKey(78);
    a.insertKey(82);
    a.insertKey(-56);
    a.insertKey(1);
    a.insertKey(6);
    a.display();
}