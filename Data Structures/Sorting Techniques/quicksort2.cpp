#include<iostream>
using namespace std;
void PrintArray(int a[], int n){
    cout<<"Soretd Array is : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int partition(int a[], int start, int end){

    int pivot = start;
    int left=1;

    while(1){
        if (left){
            if(pivot==end){
                return pivot;
            }
            else if(a[pivot] > a[end]){
                int temp = a[pivot];
                a[pivot] = a[end];
                a[end] = temp;
                start = pivot +1;
                pivot =end;
                left = 0;
            }
            else{
                end--;
            }
        }
        else{
            if(pivot==start){
                return pivot;
            }
            else if(a[start] > a[pivot]){
                int temp = a[pivot];
                a[pivot] = a[start];
                a[start] = temp;
                end = pivot-1;
                pivot = start;
                left = 1;
            }
            else{
                start++;
            }
        }
    }
}

int main(){
    int val,num;
    cout<<"Enter number of elements: ";
    scanf("%d", &num);
    if (num<0)
        cout<<"Enter only +ve numbers";
    else{
        int arr[num];
        cout<<"Enter elements : ";
        for (int i=0;i<num;i++){
            cin>>arr[i];
        }
        //PrintArray(arr,num);
        
        int half = num/2;
        int lower[half];
        int upper[half];
        int top=0;
        int start,end;
        lower[0] = 0;
        upper[0] = num-1;
        while(top > -1){
            start = lower[top];
            end = upper[top];
            int part_ind = partition(arr,start,end);
            top--;

            if(start < part_ind-1){
                top++;
                lower[top] = start;
                upper[top] = part_ind-1;
            }

            if(part_ind+1 < end){
                top++;
                lower[top] = part_ind+1;
                upper[top] = end;
            }
            //PrintArray(arr,num);

        }
        PrintArray(arr,num);
    }
}
