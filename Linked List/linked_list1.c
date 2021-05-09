#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node *st=NULL; //head Pointer
node* createNode(int d){
    node *a;
    a=malloc(sizeof(node));
    a->data=d;
    a->next=NULL;
    return a;
}
void display(){
    node *a=st;
    if(st==NULL)
        printf("\nEmpty List");
    else{
        printf("\nDATA\n");
        while(a!=NULL){
            printf("%5d",a->data);
            a=a->next;
        }
        return ;
    }


}
node* getLastElement(){
    node* a=st;
    while(a->next!=NULL)
        a=a->next;
    return a;


}
int count(){
    int cnt=0;
    node *a=st;
    while(a!=NULL){
        cnt++;
        a=a->next;
    }
    return cnt;

}
int sum(){
    int sum=0;
    node* a=st;
    while(a!=NULL){
        sum+=a->data;
        a=a->next;

    }
    return sum;


}

int max(){
    int max =-1;
    node *a=st;
    if(a==NULL){
        printf("\nEmpty list");
    }
    else{
        max=a->data;
        a=a->next;

        while(a!=NULL){
            if(max<(a->data))
                max=a->data;
            a=a->next;
        }


    }
    return max;



}
void addEnd(int d){
    node *a,*b;
    a=createNode(d);
    if(st==NULL)
        st=a;
    else{
    b=getLastElement();
    b->next=a;
    }

}
void addBegin(int d){
    node *a=createNode(d);
    a->next=st;
    st=a;



}


int main(){
 int d,res,opt;
 printf("\nLINKED LIST\n============================\n");
 while(1){
    printf("\n\nMENU\n1.Add at End\n2.Add at Begin\n3.Display\n4.Count\n5.Sum\n6.Max\nOPTION :");
    scanf("%d",&opt);
    if(opt>6)
        break;
    else{
        switch(opt){
    case 1:
        printf("\nEnter No to add at end :");scanf("%d",&d);addEnd(d);break;
    case 2:
        printf("\nEnter No to add at begin :");scanf("%d",&d);addBegin(d);break;
    case 3:
        display();break;
    case 4:
        res=count();
        printf("\nNo of Nodes are %d",res);break;
    case 5:
        res=sum();
        printf("\nSum of list :%d",res);break;
    case 6:
        res=max();
        printf("Max of list is %d",res);break;

        }
    }

 }


}
