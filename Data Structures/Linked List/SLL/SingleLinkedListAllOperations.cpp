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
        else if (pos > count() + 1 || pos<0 )
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
                i++;
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
        else if (pos > count() || pos<=0)
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
        }
    }
    void deleteAllNode(){
        Node *p,*temp;
        p=head;
        while(p!=NULL){
            temp=p;
            p=p->next;
            free(temp);
        }
        head=NULL;
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
    int n,choice=1;
    while(true){
        int data;
        cout<<"Enter data : ";
        cin>>data;
        obj.append(data);
        cout<<"Enter choice : ";
        cin>>choice;
        if (choice==0){
            break;
        }
    }
    cout << "Enter 1 to append,2 to push,3 to insert,4 to print,5 to delete,6 to count,7 to search,8 to exit : \n";
    while (true)
    {
        
        cin >> n;
        if (n == 1)
        {
            int data;
            cout << "Enter the number to be appended : ";
            cin >> data;
            obj.append(data);
            cout<<"Enter choice : ";
        }
        else if (n == 2)
        {
            int data1;
            cout << "Enter the number to be pushed : ";
            cin >> data1;
            obj.push(data1);
            cout<<"Enter choice : ";
        }
        else if (n == 3)
        {
            int data2, index;
            cout << "Enter the number to be inserted : ";
            cin >> data2;
            cout << "Enter the index number : ";
            cin >> index;
            obj.insert(index, data2);
            cout<<"Enter choice : ";
        }
        else if (n == 4)
        {
            obj.printList();
            cout<<"Enter choice : ";
        }
        else if(n==5){
            int pos;
            cout<<"Enter the position to be deleted.";
            cin>>pos;
            obj.deleteNode(pos);
            cout<<"Enter choice : ";
        }
        else if(n==6){
            cout<<"Total nodes are : "<<obj.count();
            cout<<"Enter choice : ";
        }
        else if(n==7){
            int data4;
            cout<<"Enter the element to be searched : ";
            cin>>data4;
            obj.search(data4);
            cout<<"Enter choice : ";
        }
        else if(n==8)
        {
            break;
        }
    }
    

    cout<<"No. of nodes : "<<obj.count()<<"\n";
    obj.deleteAllNode();
    cout<<"No. of nodes : "<<obj.count()<<"\n";
    obj.printList();
    return 0;
}


