#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Sll
{
public:
void push(int newData)
    {
        Node *newNodePush = new Node();
        newNodePush->data = newData;
        newNodePush->next = head;
        head = newNodePush;
    }
void insert(int index, int newData)
    {
        Node *newNodeInsert = new Node();
        int count = 1;
        if (index == 0)
        {
            push(newData);
        }
        else
        {
            Node *r = head;
            while (r != NULL)
            {
                if (count == index)
                {
                    newNodeInsert->data = newData;
                    newNodeInsert->next = r->next;
                    r->next = newNodeInsert;
                    break;
                }
                count++;

                r = r->next;
            }
        }
    }
    void printList()
    {
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

private:
    Node *head = NULL;
    int data;
};
int main()
{
    Sll obj;
    obj.insert(0,2);
    obj.insert(1,3);
    obj.insert(2,4);
    obj.printList();
    return 0;
}    