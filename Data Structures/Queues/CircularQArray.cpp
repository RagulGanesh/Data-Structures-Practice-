#include <iostream>
using namespace std;
template<class T>
class Queue
{
public:
    Queue(int s)
    {
        front = -1;
        rear = -1;
        size = s;
        p = new T[size];
    }
    void enqueue(T data)
    {
        if (front == (rear + 1) % size)
        {
            cout << "Queue is full";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            p[rear] = data;
        }
    }
    T dequeue()
    {
        T ele;
        if (front == -1)
        {
            cout << "Queue is empty";
        }
        if (front == rear)
        {
            ele = p[front];
            front = -1;
            rear = -1;
        }
        else
        {
            ele = p[front];
            front = (front + 1) % size;
        }

        return ele;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty";
        }
        else{
            if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << p[i] << " ";
            }
        }
        else
        {
            for (int i = front; i > rear; i = (i + 1) % size)
            {
                cout << p[i] << " ";
            }
            cout<<p[rear];
        }

        }
        
    }

private:
    int front, rear, size;
    int *p;
};
int main()
{
    int n;
    cout << "Enter the size of the queue : ";
    cin >> n;
    Queue<int> a(n);
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