#include <iostream>
using namespace std;
void countSort(int a[], int div, int n)
{
    int cnt[10], temp[n], i;
    for (i = 0; i < 10; i++)
    {
        cnt[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cnt[(a[i] / div) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        temp[cnt[(a[i] / div) % 10] - 1] = a[i];
        cnt[(a[i] / div) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
}
void radixSort(int a[], int n)
{
    int max = a[0];
    int i, q;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    i = 1;
    q = max / i;
    while (q > 0)
    {
        countSort(a, i, n);
        i *= 10;
        q = max / i;
    }
}
void printArray(int a[], int n)
{
    cout << "Sorted array : ";
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
    int a[n];
    if (n >= 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        radixSort(a, n);
        printArray(a, n);
    }
    else
    {

        cout << "Array size is invalid.";
    }

    return 0;
}