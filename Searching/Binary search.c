#include<stdio.h>

int main(){
    int n,i,mid,l,r,sv;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nDATA :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nSearch Value :");
    scanf("%d",&sv);

    l=0; //left
    r=n-1; //right
     //middle
    while(l<=r){
        mid=(l+r)/2;
        if(sv==arr[mid]) break;

        if(sv<arr[mid])
            r=mid-1;
        else
            l=mid+1;

    }
    if(l>r) printf("\n<NOT FOUND>");
    else printf("\n<FOUND>");

    return;

}
