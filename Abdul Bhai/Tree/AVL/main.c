/*
Algo :
Using Recursive Call ->
key is inserted by comparing(smaller & larger)
and accordingly inserted in leaf node

while returning it checks balance factor of every node
    so it is check from leaf node backwards

first unbalanced node(first unbalanced ancestor of inserted leaf node) encounter-> rotation is performed
Rotation depend upon first 2 direction from unbalanced node to leaf node

BF(Balance Factor)

if BF is +ve > it is heavy on left side
if BF is -ve -> it is heavy on right side

NOTE : BF should never exceed 2 or decreased below -2; i.e |BF|<=2
This is done to maintain Balanced tree &Thus Rotation are not delayed
and are performed as soon as UNbalanced Node is Encounter


In Rotation :
appropriate changes are done
height of node which moves is updated
if rotation involves root node
then root is updated to new root


*/



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
tnode* InPre(tnode *p){
    while(p&&p->rchild!=NULL)
        p=p->rchild;
    return p;

}
tnode * InSucc(tnode* p){
    while(p&&p->lchild!=NULL)
        p=p->lchild;
    return p;

}

tnode* del(tnode* p,int key){
    if(p==NULL) //not found
        return NULL;
    if(p->lchild==NULL&&p->rchild==NULL){ //leaf node
        if(root==p)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=del(p->lchild,key);
    else if(key>p->data)
        p->rchild=del(p->rchild,key);
    else{   //if found
        tnode *q;
        if(height(p->lchild)>height(p->rchild)){
            q=InPre(p->rchild);
            p->data=q->data;
            p->lchild=del(p->lchild,q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=del(p->rchild,q->data);
        }
        //update height
        int lbf,rbf;
        lbf=height(p->lchild)+1; //left binary tree balance factor
        rbf=height(p->rchild)+1;
        p->bf=lbf-rbf;
        if(p->bf==2&&p->lchild&&p->lchild->bf==1) //L1
            return LL(p);
        else if(p->bf==2&&p->lchild&&p->lchild->bf==-1) //L-1
            return LR(p);
        else if(p->bf==-2&&p->rchild&&p->rchild->bf==-1) //R-1
            return RR(p);
        else if(p->bf==-2&&p->rchild&&p->rchild->bf==1) //R1
            return RL(p);
        else if(p->bf==2&&p->lchild&&p->lchild->bf==0) //L0
            return LL(p);
        else if(p->bf==2&&p->rchild&&p->rchild->bf==0) //R0
            return RR(p);
    }
    return p;
}










int main(){
    int opt,d;
    while(1){
        printf("\n1.Insert\n2.DIsplay\n3.Height\n4.Root Value\n5.Delete\nOption :");
        scanf("%d",&opt);
        if(opt>5) break;
        switch(opt){
        case 1:
            printf("\nEnter Value :");scanf("%d",&d);
            root=Rinsert(root,d);break;
        case 2:
            printf("\nDATA :");inorder(root);break;
        case 3:
            printf("\nHEIGHT is %d",height(root));break;
        case 4:
            printf("\nROOT VALUE :%d",root->data);break;
        case 5:
            printf("\nEnter Value to Delete :");scanf("%d",&d);
            root=del(root,d);break;

        }
    }

}
