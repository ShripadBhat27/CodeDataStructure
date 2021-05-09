#include<iostream>
#include<queue>

using namespace std;

class graph{
    int n;
    int **a;
public:
    graph(int n);
    void addedge();
    void display();
    void bfs(int);
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

void graph::bfs(int start){
    int i=start,j;
    int visited[n+1] ={0};
    queue<int> q;
    cout<<"\nBFS :"<<i<<" ";
    q.push(i);
    visited[i]=1;
    while(!q.empty()){
        i=q.front();
        q.pop();
        for(int j=1;j<=n;j++){
            if(a[i][j]==1&&visited[j]==0){
                cout<<j<<" ";visited[j]=1;
                q.push(j);
            }
        }
    }
}

int main(){
    int n,opt;
    cout<<"\nEnter Number of vertices :";cin>>n;
    graph g(n);
    while(1){
        cout<<"\n1.Add Egde\n2.Display\n3.BFS :\nOption :";
        cin>>opt;
        if(opt==1)
            g.addedge();
        else if(opt==2)
            g.display();
        else if(opt==3){
            int start;cout<<"\nEnter Starting Index :";cin>>start;
            g.bfs(start);
        }
        else
            break;
    }

}
