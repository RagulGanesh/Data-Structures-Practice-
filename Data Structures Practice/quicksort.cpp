#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int a[],int low,int high,int n){
    int left,right,piv_val;
    left=low;
    right=high;
    piv_val=a[low];
    while(left<right){
        while(a[left]<=piv_val){
            left++;
        }
        while(a[right]>piv_val){
            right--;
        }
        if(left<right){
            swap(&a[left],&a[right]);
        }
    }
    int temp=a[right];
    a[low]=a[right];
    a[right]=piv_val;
    return right;
}
void quickSort(int a[],int low,int high,int n){
    int pivot;
    if(low<high){
    pivot=partition(a,low,high,n);
    quickSort(a,low,pivot,n);
    quickSort(a,pivot+1,high,n);
    }
}
void printArray(int a[],int n){
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1,n);
    printArray(a,n);
    return 0;
}