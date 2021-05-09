#include<stdio.h>
int main(){
    int n,i,j,tmp,flg;
    printf("\nNo of Elements :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray DATA :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++){
        flg=1;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
        if(flg==1) break;
    }
    printf("\nSORTED DATA :");
    for(i=0;i<n;i++)
        printf(" %d",arr[i]);
    printf("\n");
    return 0;
}
