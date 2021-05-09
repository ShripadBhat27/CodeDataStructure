#include<stdio.h>
int main(){
    int i,j,k,n,max;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray Data :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i==0)
            max=arr[i];
        else if(arr[i]>max)
            max=arr[i];
    }
    int count[max+1];
    memset(count,0,(max+1)*sizeof(int));
    for(i=0;i<n;i++)
        count[arr[i]]++;
    i=0;k=0;
    while(i<=max){
        while(count[i]){
            arr[k++]=i;
            count[i]--;
        }
        i++;
    }
    printf("\nSorted Array :");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

}
