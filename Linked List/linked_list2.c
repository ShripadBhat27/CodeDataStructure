//linked list using local head pointer
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* createNode(int d){
    node* a;
    a=(node*)malloc(sizeof(node));
    a->data=d;
    a->next=NULL;
    return a;
}

node* getLastNode(node*a){
    while(a->next!=NULL)
        a=a->next;
    return a;
}

void addEnd(node**a,int d){

    node* b=createNode(d);
    if(*a==NULL)
        *a=b;
    else {
            node *c=getLastNode(*a);
            c->next=b;
    }
}
void addBegin(node**a,int d){
    node *b=createNode(d);
    b->next=*a;
    *a=b;

}

void display(node *tr){
    while(tr!=NULL){
        printf("%5d",tr->data);
        tr=tr->next;
    }
}
int sum(node *tr){
    int tot=0;
    while(tr!=NULL){
       tot+=tr->data;
       tr=tr->next;
    }
    return tot;
}
int count(node*tr){
    int cnt=0;
    while(tr!=NULL){
        cnt++;
        tr=tr->next;
    }
    return cnt;

}
int max(node *tr){
    int maxi=tr->data;
    tr=tr->next;
    while(tr!=NULL){
        if(maxi<tr->data)
            maxi=tr->data;
        tr=tr->next;

    }return maxi;


}
int min(node *tr){
    int mini=tr->data;
    tr=tr->next;
    while(tr!=NULL){
        if(tr->data<mini)
            mini=tr->data;
        tr=tr->next;
    }return mini;

}
void delEnd(node **a){
    node *b=*a,*c;
    if(b==NULL){
        printf("\nEMPTY LIST.");return;
    }
    if(b->next==NULL)  //1 element
        *a=NULL;
    else{
    while(b->next!=NULL){
        c=b;
        b=b->next;
    }
    c->next=NULL;
    }
    free(b);


}
void delbegin(node **a){
    node *b=*a;
    if(*a==NULL){
        printf("\nEMPTY LIST.");return;
    }
    *a=b->next;
    free(b);


}

int main(){
    node *head=NULL;
    int opt,d;
    while(1){
        printf("\nMENU\n1.Add end\n2.Add Begin\n3.Display\n4.Sum\n5.Count\n6.Max\n7.Min\n8.Delete Last\n9.Delete Begin\n10.Exit\noption:");
        scanf("%d",&opt);
        if(opt>9) break;
        switch(opt){
        case 1:
            printf("\nEnter DATA to insert at End :");scanf("%d",&d);
            addEnd(&head,d);break;
        case 2:
            printf("\nEnter DATA to insert at Begin :");scanf("%d",&d);
            addBegin(&head,d);break;
        case 3:
            display(head);break;
        case 4:

            printf("Sum of list : %d",sum(head));break;
        case 5:
            printf("Elements count : %d",count(head));break;
        case 6:
            printf("Maximum : %d",max(head));break;
        case 7:
            printf("Minimum : %d",min(head));break;
        case 8:
            delEnd(&head);break;
        case 9:
            delbegin(&head);break;



        }

    }
    return 0;

}
