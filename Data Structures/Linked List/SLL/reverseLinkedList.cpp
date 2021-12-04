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
    void append(int newData)
    {
        Node *newNode = new Node();
        Node *q = head;
        newNode->data = newData;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = newNode;
        }
    }
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
    void reverseLinkedList()
    {
        Node *p = head, *q, *r = NULL;
        while (p != NULL)
        {
            q = p->next;
            p->next = r;
            r = p;
            p = q;
        }

        head = r;

    }

private:
    Node *head = NULL;
    int data;
};
int main()
{
    Sll a;
    a.append(10);
    a.append(20);
    a.append(30);
    a.append(40);
    a.append(50);
    a.reverseLinkedList();
    a.printList();
}