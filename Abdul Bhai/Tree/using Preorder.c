#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode{
    struct Tnode* lchild;
    int data;
    struct Tnode* rchild;
}tnode;
tnode* root=NULL;
struct Snode{
    tnode* data;
    struct Snode* next;
};
typedef struct STK{
    struct Snode *top;
}stk;

void init(stk*t){
    t->top=NULL;
}

void push(stk *t,tnode *d){
    struct Snode *a;
    a=(struct Snode*)malloc(sizeof(struct Snode));
    a->data=d;a->next=NULL;
    if(t->top==NULL)
        t->top=a;
    else{
        a->next=t->top;
        t->top=a;
    }
}
void pop(stk *t){
    struct Snode* a=t->top;
    t->top=a->next;
    free(a);
    return ;
}
tnode* stktop(stk *t){
    return t->top;
}
int isEmpty(stk *t){
    return t->top==NULL;
}
/*
    if preorder is given, then finding element greater than node data means we never have to come to lchild of node
        so while moving left push address in stack
        otherwise not needed

*/
void create(int a[],int n){
    stk s;init(&s);
    tnode *tmp,*p;int i=0;
    root=(tnode*)malloc(sizeof(tnode));
    root->data=a[i++];root->lchild=root->rchild=NULL;
    p=root;
    while(i<n){
        if(a[i]<p->data){
            tmp=(tnode*)malloc(sizeof(tnode));
            tmp->data=a[i++];tmp->lchild=tmp->rchild=NULL;
            p->lchild=tmp;
            push(&s,p);
            p=tmp;
        }
        else{
            if(a[i]>p->data&&(isEmpty(&s)||a[i]<(stktop(&s)->data))){
            tmp=(tnode*)malloc(sizeof(tnode));
            tmp->data=a[i++];tmp->lchild=tmp->rchild=NULL;
            p->rchild=tmp;
            p=tmp;
            }
            else{
                p=stktop(&s);
                pop(&s);
            }
        }

    }
}
void Inorder(tnode *a){
    if(a){
        Inorder(a->lchild);
        printf("%d ",a->data);
        Inorder(a->rchild);
    }
}
int main(){
    int n=6,preoder[6] ={10,5,1,7,40,50};
    create(preoder,n);
    printf("\nDATA :");
    Inorder(root);

}
