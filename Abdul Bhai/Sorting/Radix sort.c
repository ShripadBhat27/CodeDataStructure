#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* bin[10];
void init(){
    for(int i=0;i<10;i++)
        bin[i]=NULL;
}
node* createNode(int d){
    node *a;
    a=(node*)malloc(sizeof(node));
    a->data=d;
    a->next=NULL;
    return a;
}
void insert(int index,int val){
    node *a=createNode(val);
    node *tr=bin[index];
    if(tr==NULL)
        bin[index]=a;
    else{
        while(tr->next!=NULL){
            tr=tr->next;
        }
        tr->next=a;
    }
    return;
}
//delete at begin
int del(int index){
    node *a=bin[index];
    int x=a->data;
    bin[index]=a->next;
    free(a);
    return x;
}

void radixsort(int a[],int n){
    int dig=1,i,j,index,div=1;
    init();
    while(dig<=3){

        for(i=0;i<n;i++){
            index=(a[i]/div)%10;
            insert(index,a[i]);
        }
        j=0;
        //copying back element
        for(i=0;i<10;i++){

            while(bin[i])
                a[j++]=del(i);

        }

        div*=10;
        dig++;
    }

}

int main(){
    int n,i,index;
    printf("\nEnter size of array :");
    scanf("%d",&n);
    int arr[n];
    init();
    printf("\nArray Data :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++){
            index=arr[i]%10;
            insert(index,arr[i]);
        }

    radixsort(arr,n);
    printf("\nSorted Array :");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
return;
}
