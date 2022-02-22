#include<iostream>
using namespace std;
class Hash{
    public:
    Hash(int size){
        this->size=size;
        hashT=new int[size];
        empty=new bool[size];
        for(int i=0;i<size;i++){
            hashT[i]=0;
            empty[i]=0;
        }
    }
    void insert(int e){
        int n=e%size;
        int j;
        if(empty[n]){
            hashT[n]=e;
            empty[n]=false;
        }
        else{
            j=(n+1)%size;
            do{
                if(empty[j]){
                    hashT[j]=e;
                    empty[j]=false;
                    return;
                }
                j=(j+1)%size;
            }while(n!=j);
        }
    }
    int search(int e){
        int i=e%size;
        int j=i;
        do{
            if(hashT[j]==e&&!empty[j]){
                return;
            }
            j=(j+1)%size;
        }while(j!=i);
    }
    int *hashT;
    bool *empty;
    int size;
};