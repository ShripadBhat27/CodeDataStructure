#include<iostream>
using namespace std;

class graph{
    int n;
    int **a;

public:
    graph(int n);
    void addedge();
    void display();
    friend void dfs(graph&,int);

};

graph::graph( int y){
    n=y;
    a=new int*[n+1];
    for(int i=0;i<=n;i++)
        a[i]=new int[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    }

}
void graph::addedge(){
    int i,j;
    cout<<"\nEnter edge between i,j :";cin>>i>>j;
    a[i][j]=1;
    a[j][i]=1;
}
void graph::display(){
    cout<<"\nAdjacency Matrix :"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void dfs(graph&x,int start){

    static int visited[100];
    if(visited[start]==0){
        cout<<start<<" ";visited[start]=1;
        for(int v=1;v<=x.n;v++)
            if(x.a[start][v]==1&&visited[v]==0)
                dfs(x,v);
    }
    return;
}
int main(){
    int no,opt;
    cout<<"\nEnter Number of vertices :";cin>>no;
    graph g(no);
    while(1){
        cout<<"\n1.Add Egde\n2.Display\n3.DFS :\nOption :";
        cin>>opt;
        if(opt==1)
            g.addedge();
        else if(opt==2)
            g.display();
        else if(opt==3)
        {
            int d;cout<<"\nEnter Starting Vertice :";cin>>d;
            dfs(g,d);
        }
        else
            break;
    }

}
