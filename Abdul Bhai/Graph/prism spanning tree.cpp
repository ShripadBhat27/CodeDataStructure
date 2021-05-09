#include<iostream>
#define I INT_MAX

using namespace std;

int cost[][8]={  //cost graph
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,9,I,I,I,6},
    {I,I,9,I,10,I,I,I},
    {I,I,I,10,I,12,I,11},
    {I,I,I,I,12,I,18,16},
    {I,5,I,I,I,18,I,I},
    {I,I,6,I,11,16,I,I}

};
int near[8]={I,I,I,I,I,I,I,I}; //for storing near vartices

int t[2][7]; //prism tree

int main(){
    int i,j,k,u,v,n=7,mini=I;
    for(i=1;i<=n;i++){ //finding minimum cost edge
        for(j=i;j<=n;j++){
            if(cost[i][j]<mini){
                mini=cost[i][j];
                u=i;v=j;
            }
        }
    }
    t[0][0]=u;t[1][0]=v;//assign to o/p
    near[u]=near[v]=0;

    for(i=1;i<=n;i++){
        if(near[i]!=0){
        if(cost[i][u]<cost[i][v])
            near[i]=u;
        else
            near[i]=v;
        }
    }
    //repeative procedure
    for(i=1;i<n-1;i++){
            mini=I;
        for(j=1;j<=n;j++){ //finding minimum nearest vertices

            if(near[j]!=0&&cost[j][near[j]]<mini){
                k=j;
                mini=cost[j][near[j]];
            }
        }
        t[0][i]=k;t[1][i]=near[k];
        near[k]=0;
        //update
        for(j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][k]<cost[j][near[j]])
                near[j]=k;
        }
    }
    cout<<"PRISM MINIMUM SPANNING TREE :"<<endl;
    for(i=0;i<n-1;i++)
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;

    return 0;
}
