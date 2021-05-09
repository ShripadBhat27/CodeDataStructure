#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;

node *head=NULL,*last=NULL;
void createList(){
    node *a;
    int d;
    printf("\n-1 to delete\nDATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        a=(node*)malloc(sizeof(node));
        a->data=d;
        a->next=NULL;
        if(head==NULL)
            head=last=a;
        else {
            last->next=a;
            last=a;
        }
    }
}
void display(){
    node *tr=head;
    printf("\n");
    while(tr!=NULL){
        printf("%d ",tr->data);
        tr=tr->next;
    }


}
void reverse(){
    node *p,*q,*r;
    p=head;
    q=r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;


}
void Rreverse(node *q,node* p){
    if(p!=NULL){
        Rreverse(p,p->next);
        p->next=q;
    }
    else
        head=q;


}
int main(){
    int opt;
    while(1){
        printf("\n1.Create\n2.Display\n3.Reverse\n4.Recursive Reverse\nOption :");
        scanf("%d",&opt);
        if(opt>4) break;
        if(opt==1) createList();
        else if(opt==2) display();
        else if(opt==3) reverse();
        else if(opt==4) Rreverse(NULL,head);
    }


}
