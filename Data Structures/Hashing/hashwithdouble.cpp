#include <iostream>
using namespace std;
class Hash
{
public:
    int *hashT;
    bool *empty;
    int size;
    Hash(int size)
    {
        this->size = size;
        hashT = new int[size];
        empty = new bool[size];
        for (int i = 0; i < size; i++)
        {
            hashT[i] = 0;
            empty[i] = true;
        }
    }
    void insert(int e)
    {
        int h1,h2,p=7;
        h1=e%size;
        if(empty[h1]){
            hashT[h1]=e;
            empty[h1]=false;
            return;
        }
        else{
            h2=p-(e%p);
            for(int i=0;i<size;i++){
                int j=(h1+i*h2)%size;
                if(empty[j]){
                    hashT[j]=e;
                    empty[j]=false;
                    return;
                }
            }
        }
    }
    int search(int e)
    {
        int i = e % size;
        int j = i;
        do
        {
            if (hashT[i] == e && !empty[i])
                return i;
            i = (i + 1) % size;
        } while (i != j);
        return -1;
    }
    void Delete(int ele)
    {
        int i = search(ele);
        if (i != -1)
        {
            hashT[i] = 0;
            empty[i] = true;
            cout << "Deleted element is :" << ele << "\n";
        }
        else
            cout << "Element does not exist\n";
    }
    void display()
    {
        cout << "Hash Table elements are : \n";
        for (int i = 0; i < size; i++)
            if (hashT[i] == 0)
            {
                continue;
            }
            else
            {
                cout << hashT[i] << " ";
            }
    }
};
int main()
{
    Hash a(11);
    cout << "Enter 1 for Insert, 2 for delete, 3 for display, 4 for search, 5 for exit : \n";
    int op, val;
    while (true)
    {
        cout << "Enter option : ";
        cin >> op;
        if (op == 1)
        {
            cout << "Enter ele for insert : ";
            cin >> val;
            a.insert(val);
        }
        else if (op == 2)
        {
            cout << "Enter ele for delete : ";
            cin >> val;
            a.Delete(val);
        }
        else if (op == 3)
        {
            a.display();
        }
        else if (op == 4)
        {
            cout << "Enter ele for search : ";
            cin >> val;
            if (a.search(val)==-1)
            {
                cout << "Element not found\n";
            }
            else
            {
                cout << "Element found\n";
            }
        }
        else
        {
            break;
        }
    }
}