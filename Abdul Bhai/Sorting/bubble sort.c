#include<stdio.h>

void bubble(int a[],int n){
    int i,j,tmp,flg;
    for(i=0;i<n-1;i++){
        flg=0;
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                flg=1;
            }
        }
        if(flg==0) return;
    }
    return;
}
int main(){
    int n;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Array Data :");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubble(arr,n);
    printf("\nSorted Data :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
