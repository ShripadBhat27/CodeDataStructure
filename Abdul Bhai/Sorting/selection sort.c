#include<stdio.h>
void selection(int a[],int n){
    int i,j,k,tmp;
    for(i=0;i<n-1;i++){
        j=k=i;
        for(;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        if(a[i]!=a[k]){
            tmp=a[i];
            a[i]=a[k];
            a[k]=tmp;
        }
    }
    return;
}

int main(){
    int n;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray data :");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selection(arr,n);
    printf("\nSorted Array :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
