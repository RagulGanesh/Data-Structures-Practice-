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
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.printList();
    return 0;
} 