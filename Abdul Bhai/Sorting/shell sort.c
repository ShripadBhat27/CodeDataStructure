#include<stdio.h>
void shellsort(int a[],int n){
    int i,j,gap,tmp;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            j=i-gap;
            tmp=a[i];
            while(j>=0&&a[j]>tmp){
                a[j+gap]=a[j];
                j=j-gap;
            }
            a[j+gap]=tmp;
        }
    }
    return;


}









int main(){
    int n;
    printf("\nEnter size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray Data :");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    shellsort(arr,n);
    printf("\nSorted Array :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

}
