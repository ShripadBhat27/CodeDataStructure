#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode{
    struct Tnode *lchild;
    int data;
    int bf; //balance factor
    struct Tnode* rchild;
}tnode;

tnode *root=NULL;

int height(tnode *p){
    int x=0,y=0;
    if(p==NULL) return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}

tnode* LL(tnode *p){
    int lbf,rbf;
    tnode *pl=p->lchild;
    pl->bf=0;
    p->lchild=pl->rchild;
    pl->rchild=p;
    lbf=height(p->lchild)+1;
    rbf=height(p->rchild)+1;
    p->bf=lbf-rbf;
    if(p==root) //if root is changed ,then update root
        root=pl;
    return pl;
}
tnode* LR(tnode *p){
    int lbf,rbf;
    tnode *pl=p->lchild;
    tnode *plr=pl->rchild;
    plr->bf=0;
    p->lchild=plr->rchild;
    pl->rchild=plr->lchild;
    plr->lchild=pl;
    plr->rchild=p;
    //updating height of p& pl
    lbf=height(p->lchild)+1;
    rbf=height(p->rchild)+1;
    p->bf=lbf-rbf;
    lbf=height(pl->lchild)+1;
    rbf=height(pl->rchild)+1;
    pl->bf=lbf-rbf;
    if(p==root) root=plr;
    return plr;

}
tnode *RR(tnode *p){
    int lbf,rbf;
    tnode *pr=p->rchild;
    pr->bf=0;
    p->rchild=pr->lchild;
    pr->lchild=p;
    lbf=height(p->lchild)+1;
    rbf=height(p->rchild)+1;
    p->bf=lbf-rbf;
    if(p==root) root=pr;
    return pr;
}
tnode *RL(tnode *p){
    int lbf,rbf;
    tnode *pr=p->rchild;
    tnode *prl=pr->lchild;
    prl->bf=0;
    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=p;
    prl->rchild=pr;
    lbf=height(p->lchild)+1;
    rbf=height(p->rchild)+1;
    p->bf=lbf-rbf;
    lbf=height(pr->lchild)+1;
    rbf=height(pr->rchild)+1;
    pr->bf=lbf-rbf;
    if(p==root) root=prl;
    return  prl;
}




tnode* Rinsert(tnode *p,int key){
    tnode *t;int lbf,rbf;
    if(p==NULL){
        t=(tnode*)malloc(sizeof(tnode));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->bf=0;
        return t;
    }
    if(key<p->data)
        p->lchild=Rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=Rinsert(p->rchild,key);
    lbf=height(p->lchild)+1; //left binary tree balance factor
    rbf=height(p->rchild)+1;
    p->bf=lbf-rbf;
    if(p->bf==2&&p->lchild->bf==1)
        return LL(p);
    if(p->bf==2&&p->lchild->bf==-1)
        return LR(p);
    if(p->bf==-2&&p->rchild->bf==-1)
        return RR(p);
    if(p->bf==-2&&p->rchild->bf==1)
        return RL(p);
    return p;
}


void inorder(tnode *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

int main(){
    int opt,d;
    while(1){
        printf("\n1.Insert\n2.DIsplay\n3.Height\nOption :");
        scanf("%d",&opt);
        if(opt>4) break;
        switch(opt){
        case 1:
            printf("\nEnter Value :");scanf("%d",&d);
            root=Rinsert(root,d);break;
        case 2:
            printf("\nDATA :");inorder(root);break;
        case 3:
            printf("\nHEIGHT is %d",height(root));break;


        }
    }

}
