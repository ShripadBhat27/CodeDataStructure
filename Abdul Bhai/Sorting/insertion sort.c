#include<stdio.h>

void insert(int a[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=a[i];
        while(j>-1&&a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }

}
int main(){
    int n;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray Data :");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    insert(arr,n);
    printf("\nSorted Data :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

}
