/*
    OPEN HASHING : As it uses extra space

    LOADING FACTOR(lamda)=no of elements/size of hashtable
    it is assume that data gets distributed uniformly

    Avg Successful search= 1+ lamda/2 :::1 to find hash& max element in list
    can be lamda , so avg of 1 & lamda is lamda/2

    Avg Unsuccesful search =1+lamda
*/











#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

void SortedInsert(node **h,int d){
    node *t,*q=NULL,*p=*h;
    t=(node*)malloc(sizeof(node));
    t->data=d;
    t->next=NULL;
    if(*h==NULL)
        *h=t;
    else{
        while(p&&p->data<d){
            q=p;
            p=p->next;
        }
        if(p==*h){ //inserting at first position
            t->next=*h;
            *h=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
node* search(node* p,int d){
    while(p!=NULL){
        if(d==p->data)
            return p;
        p=p->next;
    }
    return NULL;

}
void del(node**head,int d){
    node *q,*p=*head;
    while(p!=NULL){
            q=p;
            if(p->data==d)
                break;
            p=p->next;
    }
    if(p!=NULL){
        if(p==*head)
            *head=NULL;
        else
            q->next=p->next;
        free(p);
    }
}


//HASHING
int hash(int key){
    return key%10;
}
void insert(node* h[],int key){
    int index=hash(key);
    SortedInsert(&h[index],key);
}
int hashsearch(node* h[],int key){
    int index=hash(key);
    node *p=search(h[index],key);
    return p!=NULL;
}
int main(){
    node* ht[10]; //hashtable
    int i,opt,d;
    for(i=0;i<10;i++)
        ht[i]=NULL;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Search\nOption :");
        scanf("%d",&opt);
        if(opt>3) break;
        if(opt==1) {
            printf("\nEnter Value to be added :");scanf("%d",&d);
            insert(ht,d);
        }
        else if(opt==3){
            printf("\nEnter value to be searched :");scanf("%d",&d);
            if(hashsearch(ht,d))
                printf("\n<FOUND>");
            else
                printf("\n<NOT FOUND>");
        }
    }

}
