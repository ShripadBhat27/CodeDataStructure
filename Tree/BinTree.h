#include<stdlib.h>
#include<math.h>
#include<stdio.h>
typedef struct node{
    struct node* left;
    struct node* right;
    int data;
}NODE;

NODE *rt=NULL; //root
NODE **ptr;
int depth,cnt;

NODE* createNode(char ch){
    NODE *a;
    a=(NODE*)malloc(sizeof(NODE));
    a->data=ch;
    a->left=a->right=NULL;
    return a;
}

void createArray(){
    printf("\nDepth of Binary tree :");scanf("%d",&depth);
    cnt=(pow(2,depth));
    cnt=(int)cnt;
    ptr=(NODE**)malloc(cnt*sizeof(NODE*));

}


void createTree(){
    int i=1,pos;
    char ch;
    NODE *p,*q;
    createArray();
    while(i<cnt){
        printf("\nData :");scanf("%c",&ch);
        if(ch=='#') ptr[i]=NULL;
        else{
            pos=i/2;
            if(pos==0)
                rt=ptr[i]=createNode(ch);
            else{
                p=ptr[i];
                if(p==NULL)
                    ;
                else{
                    q=createNode(ch);
                    if(p->left==NULL)
                        p->left=q;
                    else
                        p->right=q;
                }
                ptr[i]=q;
            }

        }
        i++;
    }
}
