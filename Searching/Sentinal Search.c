#include<stdio.h>
void main(){
    int n,i;
    printf("\nenter size of array :");scanf("%d",&n);
    int arr[n+1];
    printf("\nDATA :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nSearch Value :");
    scanf("%d",&arr[n]);
    i=0;
    while(arr[i]!=arr[n])
        i++;
    if(i==n) printf("\n< NOT FOUND >\n");
    else printf("\n<FOUND.>");

}
