#include<stdio.h>
#include<stdlib.h>
//tree Node
typedef struct Tnode{
    struct Tnode* lchild;
    int data;
    struct Tnode* rchild;
}tnode;
//Node for linked list for queue
typedef struct Node{
    tnode* data; //address of tree node
    struct Node* next;
}node;
typedef struct QUeue{
    node *head,*last;
}Queue;
void init(Queue *t){
    t->head=t->last=NULL;
}
void enqueue(Queue *t,tnode*  d){
    node *a;
    a=(node*)malloc(sizeof(node));
    a->data=d;a->next=NULL;
    if(t->head==NULL)
        t->head=t->last=a;
    else{
        t->last->next=a;
        t->last=a;
    }
}
tnode* dequeue(Queue *t){
    node *a;

    a=t->head;
    if(a->next)
    t->head=a->next;
    else
        t->head=NULL;
    return a->data;
}
int isEmpty(Queue *t){
    return t->head==NULL;
}
 struct SNODE{
    tnode* data;
    struct SNODE* next;
};

 struct Stack{
    struct SNODE* head;
};

void Sinit(struct Stack *t){
    t->head=NULL;
}
void push(struct Stack *t,tnode* d){
    struct SNODE* a;
    a=(struct SNODE*)malloc(sizeof(struct SNODE));
    a->data=d;a->next=NULL;
    if(t->head==NULL)
        t->head=a;
    else{
        a->next=t->head;
        t->head=a;
    }
}
tnode* pop(struct Stack *t){
    tnode* res;
    struct SNODE *a=t->head;
    t->head=a->next;
    res=a->data;
    free(a);
    return res;
}
void Spreorder(tnode *a){
    struct Stack s;Sinit(&s);
    while((s.head!=NULL)||a){
        if(a){
            printf("%d ",a->data);
            push(&s,a);
            a=a->lchild;
        }
        else{
            a=pop(&s);
            a=a->rchild;
        }
    }
}
void Sinorder(tnode *a){
    struct Stack s;Sinit(&s);
    while((s.head!=NULL)||a){
        if(a){

            push(&s,a);
            a=a->lchild;
        }
        else{
            a=pop(&s);
                   printf("%d ",a->data);
            a=a->rchild;
        }}}
/*
To implement we need stack of long int

void Spostorder(tnode *a){
    struct Stack s;Sinit(&s); long int tmp;
    while(a||(s.head!=NULL)){
       if(a){
            push(&s,a);a=a->lchild;
    }
    else{
            tmp=pop(&s);
            if(tmp>0){
                push(&s,-tmp);  //-ve value
                a=((tnode*)tmp)->rchild;  //typecast long int value to pointer

            }
            else{
                printf("%d ",((tnode*)tmp)->data);
                t=NULL;
            }
    }


*/
