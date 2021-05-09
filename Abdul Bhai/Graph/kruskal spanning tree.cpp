#include<iostream>
#define I INT_MAX
using namespace std;
//representation of graph
int edge[3][9]={
    {1,1,2,2,3,4,4,5,5}, //vertex 1
    {2,6,3,7,4,5,7,6,7},  //vertex 2
    {25,5,12,10,8,16,14,20,18} //edge cost between vertex 1&2
};

int Set[8]={-1,-1,-1,-1,-1,-1,-1,-1}; //set to check cycle
int included[9] ={0}; //to check if included earlier
int t[2][6]; //o/p  kruskal tree


//union of two sets
void Union(int u,int v){
    if(Set[u]<Set[v]){
        Set[u]+=Set[v];
        Set[v]=u;
    }
    else{
        Set[v]+=Set[u];
        Set[u]=v;
    }
}

int Find(int u){ //collapsing find
    int x=u,v=0;
    while(Set[x]>0)
        x=Set[x];
    //connecting vertices directly to parent coming along path
    while(u!=x){
        v=Set[u];
        Set[u]=x;
        u=v;
    }
    return x;
}


int main(){
    int i=0,j,k,u,v,mini=I,n=7,e=9;
    while(i<n-1){
        mini=I;
        //find minimum cost edge
        for(j=0;j<e;j++){
            if(edge[2][j]<mini&&included[j]==0){
                mini=edge[2][j];
                u=edge[0][j];
                v=edge[1][j];
                k=j;
            }
        }
        //check if forming cycle
        if(Find(u)!=Find(v)){
            t[0][i]=u;
            t[1][i]=v;
            Union(Find(u),Find(v));
            i++;
        }
        included[k]=1;

    }

    cout<<"Kruskal's tree :"<<endl;
    for(i=0;i<n-1;i++)
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    return 0;

}
