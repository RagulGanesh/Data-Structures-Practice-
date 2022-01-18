#include<iostream>
using namespace std;
class DFS{
    public:
    DFS(int size){
        this->size=size;
        visited=new int[size];
        adjMat=new int*[size];
        for(int i=0;i<size;i++){
            adjMat[i]=new int[size];
        }
        for(int i=0;i<size;i++){
            visited[i]=0;
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
        int num,ver;
        for(int i=0;i<size;i++){
            cout<<"Enter the number of connections for "<<i<<" vertice : ";
            cin>>num;
            int a[num];
            cout<<"Enter its value : ";
            for(int j=0;j<num;j++){                
                cin>>a[j];                
            }
            for(int j=0;j<num;j++){
                add_edge(i,a[j]);
            }
        }
    }
    
    void depthFirstSearch(int a){
        visited[a]=1;
        cout<<a<<" ";
        for(int i=0;i<size;i++){
            if(adjMat[a][i]==1&&visited[i]==0){
            depthFirstSearch(i);
            }
        }
    }
    
    int size;
    //int adjMat[size][size];
    int *visited;
    int **adjMat;
    //int adjMat[size][size];
};
int main(){
    int n;
    cout<<"Enter the number of vertices in the graph : ";
    cin>>n;
    DFS a(n);
    a.input();
    a.depthFirstSearch(0);
    
    
}
