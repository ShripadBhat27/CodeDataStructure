#include<stdio.h>
#define M 5
int fibosearch(int *a,int sv){
    int f1,f2,mid,first,index;
    f1=1;f2=0;
    mid=2;
    while(f1<M){
        f1=f1+f2;
        f2=f1-f2;
        mid++;
    }
    f2=f1-f2;
    f1=f1-f2;
    mid--;
    first=0;
    while(mid>0){
        index=first+1;
        if(index>=M||sv<a[index]){
            mid--;
            f2=f1-f2;
            f1=f1-f2;
        }
        else{
            if(sv==a[index]) break;
            else{
                first=index;
                mid=mid-2;
                f1=f1-f2;
                f2=f2-f1;
            }
        }
    }
    return (mid>0)?index:-1;
}
int main(){
    int arr[M],i,sv;
    printf("\nDATA :");
    for(i=0;i<M;i++)
        scanf("%d",&arr[i]);
    printf("\nSearch Value :");
    scanf("%d",&sv);
    if(fibosearch(arr,sv)==-1)
        printf("\nNOT FOUND.");
    else
        printf("\nFOUND.");


}
