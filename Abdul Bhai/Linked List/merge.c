//merge two list in one list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;

typedef struct SLIST{
    node *head;
}slist;

void createList(slist *t){
    node *last=t->head,*a;
    int d;
    printf("\nDATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        a=(node*)malloc(sizeof(node));
        a->data=d;
        a->next=NULL;
        if(t->head==NULL)
            t->head=last=a;
        else {
            last->next=a;
            last=a;
        }
    }

}
void display(slist *t){
    node *tr=t->head;

    while(tr!=NULL){
        printf("%d ",tr->data);
        tr=tr->next;
    }


}
void merge(slist *d,slist *p, slist *q){
    node *last,*first=p->head,*second=q->head;
    if(first->data<second->data){
        d->head=last=first;
        first=first->next;
        last->next=NULL;
    }
    else {

        d->head=last=second;
        second=second->next;
        last->next=NULL;
    }
    while(first!=NULL&&second!=NULL){
        if(first->data<second->data){
        last->next=first;
        last=first;
        first=first->next;
        last->next=NULL;
    }
    else{
        last->next=second;
        last=second;
        second=second->next;
        last->next=NULL;


    }
    }
    if(first!=NULL) last->next=first;
    else last->next=second;
}





int main(){
    slist l1,l2,l3;
    l1.head=NULL;
    l2.head=NULL;
    l3.head=NULL;
    int opt;
    while(1){
        printf("\n1.Create L1\n2.Create L2\n3.Display L1\n4.Display L2\n5.Merge\n6.Display L3\nOption :");
        scanf("%d",&opt);
        if(opt>6) break;
        switch(opt){
        case 1:
            createList(&l1);break;
        case 2:
            createList(&l2);break;
        case 3:
            display(&l1);break;
        case 4:
            display(&l2);break;
        case 5:
            merge(&l3,&l1,&l2);break;
        case 6:
            display(&l3);break;
        }
    }

}
