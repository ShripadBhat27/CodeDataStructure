#include<stdio.h>
void main(){
    int n,i,j;
    printf("\nEnter Size of Array :");scanf("%d",&n);
    int arr[n];
    printf("\nDATA :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int sv;
    printf("\nEnter Search Value :");scanf("%d",&sv);
    for(i=0;i<n;i++)
        if(arr[i]==sv)
            break;
    if(i==n) printf("\n<NOT FOUND>");
    else printf("\n<FOUND>");

    return ;

}
