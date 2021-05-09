#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *next;
}node;
node *top=NULL;
void push(int d){
    node *a;
    a=(int*)malloc(sizeof(node));
    if(a==NULL) printf("\nSTACK OVERFLOW");
    else{
        a->data=d;
        a->next=top;
        top=a;
    }
}
int pop(){
    int val=-1;node *a=top;
    if(top==-1) printf("\nStack Under Flow");
    else{
    val=a->data;
    top=top->next;
    free(a);
    }
    return val;
}
void display(){
    node *tr=top;
    if(top==NULL) {printf("\nEMPRTY ");return;}
    printf("\n");
    while(tr!=NULL){
        printf("%d ",tr->data);
        tr=tr->next;
    }printf("\n");
}
int peek(int pos){
    node *tr;int i=1;
    if(i<1) {printf("\nInvaid ");return -1;}
    for(i=1,tr=top;tr!=NULL&&i<pos;i++)
        tr=tr->next;
    if(tr!=NULL) return tr->data;
    return -1;

}
int getTop(){
    return top?top->data:-1;
}
int isEmpty(){
    return top==NULL;
}
int isFull(){
    node *a;int x;
    a=(node*)malloc(sizeof(node));
    if(a==NULL)
        x=1;
    else x=0;
    free(a);
    return x;
}
int main(){
    int opt,val;
    while(1){

        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Get Top\n6.Is Empty \n7.Is Full\nOption :");
        scanf("%d",&opt);
        if(opt>8) break;
        switch(opt){
        case 1: printf("\nENTER VALUE :");scanf("%d",&val);
        push(val);break;
        case 2:
            printf("\nPopped Element :%d",pop());break;
        case 3:
            display();break;
        case 4:
            printf("\nPosition :");scanf("%d",&val);
            printf("\nElement is %d",peek(val));break;
        case 5:
            printf("\nTop Element is %d",getTop());break;
        case 6:
            if(isEmpty()) printf("\nEMPTY ");
            else printf("\nNOT EMPTY");break;
        case 7:
            if(isFull()) printf("\nFULL");
            else printf("\nNOT FULL");break;
        }
    }
}
