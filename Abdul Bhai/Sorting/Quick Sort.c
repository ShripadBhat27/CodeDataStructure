#include<stdio.h>
//lb lower bound & ub upper bound

void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}
int Parition(int a[],int lb,int ub){

    int pivot,i,j,tmp;
    pivot=a[lb];
    i=lb;
    j=ub;
    while(i<j){
        do{i++;}while(a[i]<pivot);

        while(a[j]>pivot&&j>=lb)
            j--;
        if(i<j){
            swap(&a[i],&a[j]);
        }

    }//swapping pivot element
    swap(&a[j],&a[lb]);
    return j; //sorted element position
}
void Quick(int arr[],int lb,int ub){
    if(lb<ub){
        int point;
        point=Parition(arr,lb,ub);
        Quick(arr,lb,point-1);//left list
        Quick(arr,point+1,ub);//right list
    }
    return;
}
int main(){
    int n;
    printf("\nEnter Size of Array :");
    scanf("%d",&n);
    int arr[n];
    printf("\nArray Data :");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    Quick(arr,0,n-1);
    printf("\nSorted List :");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
