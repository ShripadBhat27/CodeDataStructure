#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode{
    struct Tnode* lchild;
    int data;
    struct Tnode* rchild;
}tnode;
tnode* root=NULL;
void insert(int d){
    tnode *a,*tr,*b;
    a=(tnode*)malloc(sizeof(tnode));
    a->data=d;a->lchild=a->rchild=NULL;
    if(root==NULL)
        root=a;
    else{
        tr=root;
        while(tr){
                b=tr;
            if(d<tr->data)
                tr=tr->lchild;
            else if (tr->data<d)
                tr=tr->rchild;
            else
                return;
        }
        if(d<b->data)
            b->lchild=a;
        else
            b->rchild=a;


    }

}
void display(tnode *p){
    if(p){
        display(p->lchild);
        printf("%d ",p->data);
        display(p->rchild);
    }
}
tnode* search(int key){
    tnode *a=root;
    while(a){
        if(a->data==key) return a;
        else if(key<a->data)
            a=a->lchild;
        else
            a=a->rchild;
    }
    return NULL;

}
tnode* Rinsert(tnode* a,int d){
    tnode *b;
    if(a==NULL){
        b=(tnode*)malloc(sizeof(tnode));
        b->data=d;b->lchild=b->rchild=NULL;
        return b;
    }
    else if(d<a->data)
        a->lchild=Rinsert(a->lchild,d);
    else if(a->data<d)
        a->rchild=Rinsert(a->rchild,d);
    return a;

}
int height(tnode *p){
    if(p){
        int x,y;
        x=height(p->lchild);
        y=height(p->rchild);
        return x>y?x+1:y+1;
    }
    return 0;
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
    tnode* q;
    if(p==NULL) return NULL;

    //if else block below is for searching key
    if(key<p->data)
        p->lchild=del(p->lchild,key);
    else if(p->data<key)
        p->rchild=del(p->rchild,key);
    else if(p->data==key){
        if(p->lchild==NULL&&p->rchild==NULL){ //if leaf node
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
        }
        if(height(p->lchild)>height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=del(p->lchild,q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=del(p->rchild,q->data);
        }

    }return p;
}

int main(){
    int opt,key;
    while(1){
        printf("\n1.Insert\n2.Display\n3.Search\n4.Recursive Insert\n5.Delete\nOption :");
        scanf("%d",&opt);
        if(opt>5) break;
        switch(opt){
            case 1:
                printf("\nEnter Value :");scanf("%d",&key);
                insert(key);break;
            case 2:
                printf("\nHeight :%d",height(root));
                printf("\nDATA IN PREORDER :");
                display(root);printf("\n");break;
            case 3:
                printf("\nEnter Value to be search :");scanf("%d",&key);
                if(search(key)==NULL)
                    printf("\n<NOT FOUND>\n");
                else
                printf("\n<FOUND>\n");
                break;
            case 4:
                printf("\nEnter Value :");scanf("%d",&key);
                root=Rinsert(root,key);break;
            case 5:
                    printf("\nEnter Value to Delete :");scanf("%d",&key);
                    del(root,key);break;

        }
    }

}
