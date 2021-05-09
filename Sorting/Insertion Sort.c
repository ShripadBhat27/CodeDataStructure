#include<stdio.h>
int main(){
    int i,j,n,val;
    printf("\nEnter No of Element :");
    scanf("%d",&n);
    int arr[n];
    printf("\nARRAY DATA :");
    for(i=0;i<n;i++){
        scanf("%d",&val);
        for(j=i-1;j>=0&&val<arr[j];j--)
            arr[j+1]=arr[j];
        arr[j+1]=val;
    }
    printf("\nSORTED DATA :");
    for(i=0;i<n;i++)
        printf(" %d",arr[i]);
    printf("\n");
    return 0;
}
