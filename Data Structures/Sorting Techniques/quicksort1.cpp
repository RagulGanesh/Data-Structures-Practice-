#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int a[], int low, int high)
{
    int left, right, piv_val;
    left = low;
    right = high;
    piv_val = a[left];
    while (left < right)
    {
        while (a[left] <= piv_val)
        {
            left++;
        }
        while (a[right] > piv_val)
        {
            right--;
        }
        if (left < right)
        {
            swap(&a[left], &a[right]);
        }
    }
    int temp = a[right];
    a[right] = a[low];
    a[low] = temp;
    return right;
}
void quickSort(int a[], int left, int right)
{
    int pivot;
    if (left < right)
    {
        pivot = partition(a, left, right);
        quickSort(a, left, pivot);
        quickSort(a, pivot + 1, right);
    }
}
void printArray(int a[], int n)
{
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    if (n >= 0)
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        quickSort(a, 0, n - 1);
        printArray(a, n);
    }
    else
    {
        cout << "Array size is invalid.";
    }
}