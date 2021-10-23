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

private:
    Node *head = NULL;
    int data;
};
int main()
{
    Sll obj;
    int n;
    while (true)
    {
        cout << "Enter 1 to append,2 to push,3 to insert,4 to print,5 to exit : \n";
        cin >> n;
        if (n == 1)
        {
            int data;
            cout << "Enter the number to be appended : ";
            cin >> data;
            obj.append(data);
        }
        else if (n == 2)
        {
            int data1;
            cout << "Enter the number to be pushed : ";
            cin >> data1;
            obj.push(data1);
        }
        else if (n == 3)
        {
            int data2, index;
            cout << "Enter the number to be inserted : ";
            cin >> data2;
            cout << "Enter the index number : ";
            cin >> index;
            obj.insert(index, data2);
        }
        else if (n == 4)
        {
            obj.printList();
        }
        else
        {
            break;
        }
    }

    return 0;
}