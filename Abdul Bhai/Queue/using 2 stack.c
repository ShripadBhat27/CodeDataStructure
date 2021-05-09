#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;
typedef struct STK{
    node* head;
}stk;
//2 stacks , s1 for insert and s2 for delete
stk s1,s2;
void init(stk *t1,stk* t2){
    t1->head=t2->head=NULL;
}
void push(stk *t,int d){
    node* a;
    a=(node*)malloc(sizeof(node));
    a->data=d;a->next=NULL;
    if(t->head==NULL)
        t->head=a;
    else{
        a->next=t->head;
        t->head=a;
    }

}
int pop(stk *t){
    node *a=t->head;
    t->head=a->next;
    int x=a->data;
    free(a);
    return x;
}
void enqueue(int d){
    push(&s1,d);
}
int dequeue(stk *t){
    if(t->head==NULL){ //is s2 is empty full it with s1 element
        while(s1.head)
            push(&s2,pop(&s1));
    }
    return pop(&s2);
}
void main(){
    int d,opt;
    init(&s1,&s2);
    while(1){
        printf("\n1.Insert\n2.Delete\nOption :");scanf("%d",&opt);
        if(opt>2) break;
        if(opt==1){
            printf("\nEnter Value :");scanf("%d",&d);
            enqueue(d);
        }
        else if(opt==2)
                printf("\nDeleted Element :%d",dequeue(&s2));
    }
}
