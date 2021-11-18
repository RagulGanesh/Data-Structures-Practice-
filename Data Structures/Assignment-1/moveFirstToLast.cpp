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

    void moveLastToFirst()
    {
        Node *p = head, *q;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        p->next = head;
        head = p;
    }

    void deleteAllNode()
    {
        Node *p, *temp;
        p = head;
        while (p != NULL)
        {
            temp = p;
            p = p->next;
            free(temp);
        }
        head = NULL;
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
    int n, choice = 1;
    cout << "Enter non-zero number to continue else 0 to stop : \n";
    while (true)
    {
        int data;
        cout << "Enter data : ";
        cin >> data;
        obj.append(data);
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
    }

    cout << "Enter 1 to print, 2 to move last node to first, 3 to exit : \n";
    while (true)
    {
        cout << "Enter choice : ";
        cin >> n;
        if (n == 1)
        {
            obj.printList();
            cout << endl;
        }
        else if (n == 2)
        {
            obj.moveLastToFirst();
        }
        else if (n == 3)
        {
            obj.deleteAllNode();
            break;
        }
    }

    return 0;
}
