#include<iostream>
#include "queue.h"
using namespace std;
class BST{
    public:
    BST(int size){
        this->size=size;
        visited=new int[size];
        adjMat=new int*[size];
        for(int i=0;i<size;i++){
            visited[i]=0;
        }
        for(int i=0;i<size;i++){
            adjMat[i]=new int[size];
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                adjMat[i][j]=0;
            }
        }

    }
    void add_edge(int a,int b){
        adjMat[a][b]=1;
        adjMat[b][a]=1;
    }
    void input(){
        int num;
        for(int i=0;i<size;i++){
            cout<<"Enter the number of vertices for "<<i<<"vertice : ";
            cin>>num;
            int a[num];
            cout<<"Enter the connections : ";
            for(int i=0;i<num;i++){
                cin>>a[i];
            }
            for(int j=0;j<num;j++){
                add_edge(i,a[j]);
            }
        }
    }
    void bfs(int a){
        visited[a]=1;
        Queue<int> b;
        b.enqueue(a);
        int k;
        while(!b.isEmpty()){
            a=b.dequeue();
            cout<<a<<" ";
            for(int i=0;i<size;i++){
                if(adjMat[a][i]==1&&visited[i]==0){
                    b.enqueue(i);
                    visited[i]=1;
                }
            }
        }
    }
    int size;
    int *visited;
    int **adjMat;
};
int main(){
    BST a(4);
    a.input();
    a.bfs(0);

}