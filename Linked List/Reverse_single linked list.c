#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* head=NULL;

void createList(){
    node* last=NULL,*t;
    int d;
    printf("\n-1 to exit");
    printf("\nEnter DATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        t=(node*)malloc(sizeof(node));
        t->data=d;
        t->next=NULL;
        if(head==NULL)
            head=last=t;
        else {
            last->next=t;
            last=t;
        }
    }
}
void display(){
    node* tr=head;printf("\n");
    while(tr!=NULL){
        printf("%d ",tr->data);
        tr=tr->next;
    }

}
void reverse(){
    node *a=head,*b=NULL,*c;
    while(a!=NULL){
        c=a->next;
        a->next=b;
        b=a;
        a=c;
    }
    head=b;


}
void preverse(node*a){
    if(a==NULL)
        return;
    preverse(a->next);
    printf("%d ",a->data);

}
void main(){
    int opt;
    while(1){
    printf("\n1.Create List \n2.Display\n3.Reverse List\n4.Display Reverse\nOPtion :");
    scanf("%d",&opt);
    if(opt>4) break;
    if(opt==1) createList();
    else if(opt==2) display();
    else if(opt==3) reverse();
    else if(opt==4) {printf("\n");preverse(head);}
    }
}
