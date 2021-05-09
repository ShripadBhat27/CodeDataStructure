#include"BinTree.h"
#include<stdio.h>

void preorder(NODE *a){
    if(a!=NULL){
        printf("%c ",a->data);
        preorder(a->left);
        preorder(a->right);
    }
}

void inorder(NODE *a){
    if(a!=NULL){
        inorder(a->left);
        printf("%c ",a->data);
        inorder(a->right);
    }
}

void postorder(NODE *a){
    if(a!=NULL){
        postorder(a->left);
        postorder(a->right);
        printf("%c ",a->data);
    }
}

void main(){
    int opt;
    while(1){
        printf("\n1.Create tree\n2.Preorder\n3.Inorder\n4.Postorder\nOption :");
        scanf("%d",&opt);
        if(opt>4) break;
        switch(opt){
    case 1:
        createTree();break;
    case 2:
        printf("\nPreorder :");preorder(rt);break;
    case 3:
        printf("\nInorder :");inorder(rt);break;
    case 4:
        printf("\nPostorder :");postorder(rt);break;
        }
    }
    return ;

}
