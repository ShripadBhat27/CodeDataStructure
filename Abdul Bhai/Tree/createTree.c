#include<stdio.h>
#include<stdlib.h>
#include"TreeIm.h"

tnode *root=NULL;
void create(){
    int d;
    tnode *p,*s;
    Queue q;
    init(&q);
    printf("\nEnter Root Data :");
    scanf("%d",&d);
    root=(tnode*)malloc(sizeof(tnode));
    root->data=d;root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(&q)){
        p=dequeue(&q);
        printf("\nEnter Left Child of %d :",p->data);
        scanf("%d",&d);
        if(d!=-1){
            s=(tnode*)malloc(sizeof(tnode));
            s->data=d;s->lchild=s->rchild=NULL;
            p->lchild=s;
            enqueue(&q,s);
        }
        printf("\nEnter Right Child of %d :",p->data);
        scanf("%d",&d);
        if(d!=-1){
            s=(tnode*)malloc(sizeof(tnode));
            s->data=d;s->lchild=s->rchild=NULL;
            p->rchild=s;
            enqueue(&q,s);
        }
    }
}


//Using Recursive Calls
void preorder(tnode* a){
    if(a!=NULL){
        printf("%d ",a->data);
        preorder(a->lchild);
        preorder(a->rchild);
    }
}
void inorder(tnode *a){
    if(a!=NULL){

        inorder(a->lchild);
        printf("%d ",a->data);
        inorder(a->rchild);
    }
}
void postorder(tnode *a){
    if(a!=NULL){

        postorder(a->lchild);

        postorder(a->rchild);
        printf("%d ",a->data);
    }
}
void levelOrder(tnode* a){
    Queue q;init(&q);
    printf("%d ",a->data);
    enqueue(&q,a);
    while(!isEmpty(&q)){
        a=dequeue(&q);
        if(a->lchild){
            printf("%d ",a->lchild->data);
            enqueue(&q,a->lchild);
        }

        if(a->rchild){
            printf("%d ",a->rchild->data);
            enqueue(&q,a->rchild);
        }
    }

}

int Count(tnode *p){
    int x,y;
    if(p){
        x=Count(p->lchild);
        y=Count(p->rchild);
        return x+y+1;
    }
    return 0;
}
int sum(tnode *p){
    int x,y;
    if(p){
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}
int height(tnode* p){
    int x,y;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}
int Leaf(tnode *p){
    int x,y;
    if(p){
        x=Leaf(p->lchild);
        y=Leaf(p->rchild);
        if(p->lchild==NULL&&p->rchild==NULL)
            return x+y+1;
        else return x+y;
    }
    return 0;
}
int twoDegree(tnode *p){
    int x,y;
    if(p){
        x=twoDegree(p->lchild);
        y=twoDegree(p->rchild);
        if(p->lchild!=NULL&&p->rchild!=NULL)
            return x+y+1;
        return x+y;
    }
    return 0;
}
int oneDegree(tnode *p){
    int x,y;
    if(p){
        x=oneDegree(p->lchild);
        y=oneDegree(p->rchild);
        if(p->lchild!=NULL^p->rchild!=NULL)
            return x+y+1;
        return x+y;
    }
    return 0;
}
void main(){
    printf("\n\n-1 to stop insert.\n");
    create();
    printf("\n\nDisplay In preorder :");
    preorder(root);printf("\nDisplay In preorder :");
    Spreorder(root);
    printf("\n\n");
    printf("\n\nDisplay In inorder :");
    inorder(root);printf("\nDisplay In Inorder :");Sinorder(root);
    printf("\n\n");
    printf("\n\nDisplay In postOrder :");postorder(root);
    printf("\n\n");
    printf("\n\nLevel Order :");levelOrder(root);
    printf("\n\n");
    printf("\nSUM :%d",sum(root));
    printf("\nHeight :%d",height(root));
    printf("\nTotal Nodes :%d",Count(root));
    printf("\nLeaf Node :%d",Leaf(root));
    printf("\n2 Degree Nodes :%d",twoDegree(root));
    printf("\n1 Degree Nodes :%d",oneDegree(root));
}
