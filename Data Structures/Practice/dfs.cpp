#include <iostream>
using namespace std;
class DFS
{
public:
    DFS(int size)
    {
        this->size = size;
        visited = new int[size];
        adjMat = new int *[size];
        for (int i = 0; i < size; i++)
        {
            adjMat[i]=new int[size];
        }
        for(int i=0;i<size;i++){
            visited[i]=0;
        }
        for(int a=0;a<size;a++){
            for(int b=0;b<size;b++){
                adjMat[a][b]=0;
            }
        }
    }

    void add_edge(int a,int b){
        adjMat[a][b]=1;
        adjMat[b][a]=1;
    }

    void input(){
        int num,key;
        for(int i=0;i<size;i++){
            cout<<"Enter number of vertices for "<<i<<"vertice : ";
            cin>>num;
            cout<<"Enter its value : ";
            int a[num];
            for(int i=0;i<num;i++){                
                cin>>a[i];
                //add_edge(i,key);
            }
            for(int j=0;j<num;j++){
                add_edge(i,a[j]);
            }
        }
    }

    void printMatrix(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<adjMat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void dfs(int a){
        visited[a]=1;
        cout<<a<<" ";
        for(int i=0;i<size;i++){
            if(adjMat[a][i]==1&&visited[i]==0){
                dfs(i);
            }
        }
    }

    int size;
    int *visited;
    int **adjMat;
};
int main(){
    DFS a(4);
    a.input();
    a.printMatrix();
    a.dfs(0);
}