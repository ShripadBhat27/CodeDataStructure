#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    struct NODE* prev;
    int data;
    struct NODE* next;
}node;

node *head=NULL,*last=NULL;

void createlist(){
    int d;
    node* a;
    printf("\n-1 to Exit\nDATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        a=(node*)malloc(sizeof(node));
        a->data=d;
        a->prev=NULL;a->next=NULL;
        if(head==NULL)
            head=last=a;
        else {
            a->next=last->next;
            last->next=a;
            a->prev=last;
            last=a;

        }
    }

}
void displayReverse(){
    node *a=last;
    printf("\n");
    while(a!=NULL){
        printf("%d ",a->data);
        a=a->prev;
    }

}
void displayFront(){
    node *tr=head;
    while(tr!=NULL){
        printf("%d ",tr->data);
        tr=tr->next;
    }
}
void insert(int value,int pos){
    int i=1; node*a,*p=head;
    a=(node*)malloc(sizeof(node));
    a->data=value;a->next=a->prev=NULL;
    if(pos==1){
        head->prev=a;
        a->next=head;
        head=a;
    }
    else {
        for(i=1;i<pos-1;i++) //we have to reach a node before
                p=p->next;
        a->next=p->next;
        a->prev=p;
        if(a->next) a->next->prev=a;
        p->next=a;
    }

}
void deleteAt(int pos){
    int i=1;node *a;
    if(pos==1){
        a=head;
        head=a->next;
        head->prev=NULL;free(a);
    }
    else {
            a=head;
        for(i=1;i<pos;i++) //we have to reach to that node
            a=a->next;
        if(a->next)
        a->next->prev=a->prev;
        a->prev->next=a->next;
        free(a);
    }

}
void REVERSE(){
    node *a=head,*tmp;
        while(a!=NULL){
            tmp=a->next;
            a->next=a->prev;
            a->prev=tmp;
            a=a->prev;
        }
        tmp=head;
        head=last;
        last=tmp;


}
int main(){
    int opt,val,index;
    while(1){
        printf("\n1.Create\n2.Display Reverse\n3.Display straight\n4.Insert \n5.Delete \n6.Reverse LIST\nOPTION :");
        scanf("%d",&opt);
        if(opt>7) break;
        switch(opt){
            case 1: createlist();break;
            case 2: displayReverse ();break;
            case 3: displayFront();break;
            case 4: printf("\nENTER VALUE &INDEX:");scanf("%d %d",&val,&index);
                    insert(val,index);break;
            case 5: printf("\nINDEX :");scanf("%d",&index);deleteAt(index);break;
            case 6: REVERSE();break;
        }
    }

}
