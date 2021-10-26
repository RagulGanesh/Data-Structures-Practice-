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
    void insert(int pos, int newData)
    {
        Node *newNodeInsert = new Node();
        newNodeInsert->data = newData;
        if (pos == 1)
        {
            push(newData);
        }
        else if (pos == count() + 1)
        {
            append(newData);
        }
        else if (pos > count() + 1)
        {
            cout << "List index out of range.\n";
        }
        else
        {
            int i = 1;
            Node *p = head;
            while (i < pos - 1)
            {
                p = p->next;
            }
            newNodeInsert->next = p->next;
            p->next = newNodeInsert;
        }
    }
    int count()
    {
        Node *p;
        int count = 0;
        for (p = head; p != NULL; p = p->next)
        {
            count++;
        }
        return count;
    }
    void search(int element)
    {
        Node *p;
        int flag = 0;
        for (p = head; p != NULL; p = p->next)
        {
            if (p->data == element)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "Found";
        }
        else
        {
            cout << "Not Found";
        }
    }
    void deleteFirst()
    {
        Node *ptr;
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
    void deleteLast()
    {
        Node *ptr, *temp;
        ptr = head;
        temp = NULL;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
    }
    void deleteNode(int pos)
    {
        Node *p, *temp;
        temp = NULL;
        p = head;
        int i = 1;
        if (pos == 1)
        {
            deleteFirst();
        }
        else if (pos == count())
        {
            deleteLast();
        }
        else if (pos > count())
        {
            cout << "Can't be deleted.";
        }
        else
        {
            while (i < pos)
            {
                temp = p;
                p = p->next;
                i++;
            }
            temp->next = p->next;
            free(p);
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