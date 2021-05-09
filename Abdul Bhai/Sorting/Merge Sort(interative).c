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
void MergeSort(int arr[],int n){
    int p,l,mid,h,i;
    for(p=2;p<=n;p*=2){
        for(i=0;i+p-1<n;i+=p){
            //merging various list of size p
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(arr,l,mid,h);
        }
    }
    //if some list is remaining at last
    if(p/2<n)
        merge(arr,0,p/2-1,n-1);
}
int main(){
    int n;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray Data :");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    MergeSort(arr,n);
    printf("\nSorted Array :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;


}
