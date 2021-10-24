#include<iostream>
using namespace std;
void merge(int a[],int temp[],int left,int mid,int right){
    int size,temp_pos,left_end,i,j;
    size=right-left+1;
    temp_pos=left;
    left_end=mid-1;
    while((left<=left_end)&&(mid<=right)){
        if(a[left]<a[mid]){
            temp[temp_pos]=a[left];
            left++;
            temp_pos++;
        }
        else{
            temp[temp_pos]=a[mid];
            mid++;
            temp_pos++;

        }
    }
    while(left<=left_end){
            temp[temp_pos]=a[left];
            left++;
            temp_pos++;
    }
    while(mid<=right){
            temp[temp_pos]=a[mid];
            mid++;
            temp_pos++;
    }
    for(i=0;i<size;i++){
        a[right]=temp[right];
        right--;
    }
}
void mergeSort(int a[],int temp[],int left,int right,int n){
    int mid;
    if (left<right){
        mid=(left+right)/2;
        mergeSort(a,temp,left,mid,n);
        mergeSort(a,temp,mid+1,right,n);
        merge(a,temp,left,mid+1,right);
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
        int a[n],b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        mergeSort(a,b,0,n-1,n);
        printArray(a, n);
    }
    else
    {
        cout<<"Array size is invalid.";
    }
}