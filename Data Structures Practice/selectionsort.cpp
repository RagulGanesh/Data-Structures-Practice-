#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int a[],int n){
    int i,j,min_ind;
    for(i=0;i<n-1;i++){
        min_ind=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min_ind]){
                min_ind=j;
            }
        }
        swap(&a[i],&a[min_ind]);
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
    selectionSort(a,n);
    printArray(a,n);
    return 0;
}
