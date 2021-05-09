#include<iostream>
using namespace std;

class graph{
    int n;
    int **a;
public:
    graph(int n);
    void addedge();
    void display();

};

graph::graph( int y){
    n=y;
    a=new int*[n];
    for(int i=0;i<=n;i++)
        a[i]=new int[n];
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

int main(){
    int n,opt;
    cout<<"\nEnter Number of vertices :";cin>>n;
    graph g(n);
    while(1){
        cout<<"\n1.Add Egde\n2.Display\nOption :";
        cin>>opt;
        if(opt==1)
            g.addedge();
        else if(opt==2)
            g.display();
        else
            break;
    }

}
