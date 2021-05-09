#include<stdio.h>
#define M 5
typedef struct queue{
    int fr,rr;
    int arr[M];
}QUE;
void init(QUE *t){
    t->fr=0;t->rr=-1;
}
int isEmpty(QUE *t){
    return t->rr<t->fr;
}
void insert(QUE *t,int d){
    if(t->rr==M-1){printf("\n<FULL>");return;}
    t->rr++;
    t->arr[t->rr]=d;
}
void del(QUE *t){
    if(isEmpty(t)) printf("\n<UNDERFLOW>");
    else
        t->fr++;
    return;
}
void display(QUE *t){printf("\n");
    for(int i=t->fr;i<=t->rr;i++)
        printf("%5d",t->arr[i]);
}
void menu(QUE *t){
    int opt,d;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\nOption :");
        scanf("%d",&opt);
        if(opt>3) break;
        switch(opt){
        case 1:
            printf("\nEnter Value :");scanf("%d",&d);
            insert(t,d);break;
        case 2:
            del(t);break;
        case 3:
            display(t);break;
        }
    }
}
void main(){
    QUE q;
    init(&q);menu(&q);
}
