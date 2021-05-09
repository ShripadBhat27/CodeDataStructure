#include<stdio.h>
void merge(int A[],int l,int mid,int h){
    int i,j,k;
    int B[h-l+1]; //auxiliary array
    i=l;
    j=mid+1;
    k=0;
    while(i<=mid&&j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    while(i<=mid)
        B[k++]=A[i++];
    while(j<=h)
        B[k++]=A[j++];
    for(i=l,k=0;i<=h;i++) //copying back sorted element to A
        A[i]=B[k++];
}
void MergeSort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        merge(a,l,mid,h);
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
    MergeSort(arr,0,n-1);
    printf("\nSorted Array :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;


}
