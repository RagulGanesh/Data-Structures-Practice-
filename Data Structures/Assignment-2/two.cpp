#include <iostream>
using namespace std;
void adjustH(int i, int size, int a[])
{
    int ci;
    ci = 2 * i + 1;
    while (ci <= size - 1)
    {
        if (ci < (size - 1) && (a[ci] > a[ci + 1]))
        {
            ci++;
        }
        if (a[i] > a[ci])
        {
            int temp = a[i];
            a[i] = a[ci];
            a[ci] = temp;
        }
        i = ci;
        ci = 2 * i + 1;
    }
}
void heapSort(int a[], int n)
{
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        adjustH(i, n, a);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjustH(0, i, a);
    }
}
void constructMinHeap(int a[], int n)
{
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        adjustH(i, n, a);
    }
}
void deleteRoot(int a[], int *n, int k)
{
    while (a[0] <= k)
    {
        cout << a[0] << " ";
        a[0] = a[*n - 1];
        *n = *n - 1;
        adjustH(0, *n, a);
    }
}
void deleteRoot(int a[], int *n)
{
    cout << "Deleted Element : " << a[0];
    int b[*n];
    for(int i=0;i<*n;i++){
        b[i]=a[i];
    }
    heapSort(b,*n);
    cout << "\nCurrent Minimum Element : " << b[*n-2];
    a[0] = a[*n - 1];
    *n = *n - 1;
    adjustH(0, *n, a);
}
void printArray(int a[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n, limit;
    cout << "Enter size of the array : ";
    cin >> n;
    int a[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    constructMinHeap(a, n);
    cout << "Min Heap Tree : ";
    printArray(a, &n);
    int choice;
    cout << "\nEnter 1 to get the current minimum element in the class after deletion else 2 to delete until a certain taget value : ";
    cin >> choice;
    if (choice == 1)
    {
        deleteRoot(a, &n);
    }
    else
    {
        cout << "Enter the limit until which you want to delete : ";
        cin >> limit;
        cout << "Deleted Elements : ";
        deleteRoot(a, &n, limit);
        cout << "\nRemaining Elements : ";
        printArray(a, &n);
    }
}
