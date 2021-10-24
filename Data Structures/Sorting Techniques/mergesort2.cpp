//mergeSort without recursion
#include<iostream>
using namespace std;
void merge(int a[],int temp[],int left,int mid,int right){
    int i,left_end,temp_pos,size;
    left_end=mid-1;
    size=right-left+1;
    temp_pos=left;
    while((left<=left_end)&&(mid<=right)){
        if(a[left]<=a[mid]){
        temp[temp_pos]=a[left];
        temp_pos++;
        left++;
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
void mergeSort(int a[],int temp[],int n){
    int c_size,left_start,mid,right;
    for(c_size=1;c_size<=n-1;c_size=2*c_size){
        for(left_start=0;left_start<n-1;left_start+=2*c_size){
            mid=min(left_start+c_size-1,n-1);
            right=min(left_start+2*c_size-1,n-1);
            merge(a,temp,left_start,mid+1,right);
        }

    }
}
void printArray(int a[],int n){
    cout<<"Sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter size of the array : ";
    cin>>n;
    if(n<=0){
        cout<<"Array size is invalid.";
    }
    else{
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    mergeSort(a,b,n);
    printArray(a,n);

    }

    return 0;
}



