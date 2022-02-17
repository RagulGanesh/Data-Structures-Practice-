#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Queue
{
public:
    void enqueue(int data)
    {
        Node *newNodeInsert = new Node();
        newNodeInsert->data = data;
        if (front == NULL)
        {
            newNodeInsert->next = newNodeInsert;
            front = newNodeInsert;
            rear = newNodeInsert;
        }
        else
        {
            rear->next = newNodeInsert;
            newNodeInsert->next = front;
            rear = rear->next;
        }
    }
    int dequeue()
    {
        int ele;
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
            Node *temp;
            temp = front;
            ele = temp->data;
            rear->next = front->next;
            front = front->next;
            free(temp);
        }
        return ele;
    }
    int count(){
        Node *temp=front;
        int count=0;
        do{
            count++;
            temp=temp->next;
        }while(temp!=front);

        return count;        

    }
    void display()
    {
        Node *temp = front;
        if (front == NULL)
        {
            cout << "Queue is empty";
        }
        else
        {
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != front);
        }
    }

private:
    Node *front = NULL;
    Node *rear = NULL;
};

int main()
{
    Queue a;
    int choice = 1, data, opt;
    cout << "Enter non-zero number to continue else zero to stop\n";
    while (true)
    {
        cout << "Enter data : ";
        cin >> data;
        a.enqueue(data);
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
    }
    cout << "Enter 1 to insert, 2 to remove, 3 to print, 4 to exit.\n";
    while (true)
    {
        cout << "Enter option : ";
        cin >> opt;
        if (opt == 1)
        {
            cout << "Enter data : ";
            cin >> data;
            a.enqueue(data);
        }
        else if (opt == 2)
        {
            a.dequeue();
        }
        else if (opt == 3)
        {
            a.display();
        }
        else if (opt == 4)
        {
            break;
        }
    }
}
