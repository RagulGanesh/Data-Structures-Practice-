#include <iostream>
using namespace std;
void selectionSort(int a[], int i, int n)
{
    if (i < n)
    {
        int min = i;
        for (int key = i + 1; key < n; key++)
        {
            if (a[key] < a[min])
            {
                min = key;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        i++;
        selectionSort(a, i, n);
    }
}

void PrintArray(int a[], int n)
{
    cout<<"Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    if (n < 0)
    {
        printf("Array size is invalid");
    }

    else
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        selectionSort(a, 0, n);
        PrintArray(a, n);
    }
    return 0;
}
