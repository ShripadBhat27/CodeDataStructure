#include<stdio.h>

int main(){
    int n,i,j,pos,tmp;
    printf("\nNumber of Array Element :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray DATA :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++){
        pos=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[pos])
                pos=j;
        if(pos!=i){
            tmp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=tmp;
        }
    }

    printf("\nSORTED DATA :");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;

}
