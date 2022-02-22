#include<iostream>
using namespace std;
void adjustH(int i,int size,int a[]){
    int ci;
    ci=2*i+1;
    while(ci<=size-1){
        if(ci<(size-1)&&(a[ci]<a[ci+1])){
            ci++;
        }
        if(a[i]<a[ci]){
            int temp=a[i];
            a[i]=a[ci];
            a[ci]=temp;
        }
        i=ci;
        ci=2*i+1;
    }
}
void heapSort(int a[],int n){
    for(int i=(n/2-1);i>=0;i--){
        adjustH(i,n,a);
    }
    for(int i=n-1;i>=1;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        adjustH(0,i,a);
    }
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter size of the array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a,n);
    printArray(a,n);
}


