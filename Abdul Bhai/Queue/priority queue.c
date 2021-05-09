/*Priority queue : dont follow FIFO
One with highest priority is deleted  First
Lower Priority value, Higher priority
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    char data;
    int pvalue; //priority value
    struct NODE* next;
}node;
node* head=NULL;
node* createNode(char d,int p){
    node*a;
    a=(node*)malloc(sizeof(node));
    a->data=d;a->pvalue=p;a->next=NULL;
    return a;
}
void enqueue(char d,int p){
    node *a=createNode(d,p),*tr=head;
    if(head==NULL)
        head=a;
    else{
        if(a->pvalue<=head->pvalue){
            a->next=head;head=a;
        }
        else{
            while(tr->next!=NULL&&tr->next->pvalue<a->pvalue)
                tr=tr->next;

            a->next=tr->next;
            tr->next=a;
        }
    }
}

void display(){
    node *tr=head;
    printf("\nDATA     :  ");
    while(tr){
        printf("%3c ",tr->data);tr=tr->next;
    }
    printf("\nPriority :  ");tr=head;
    while(tr){
        printf("%3d ",tr->pvalue);tr=tr->next;
    }
}
void dequeue(){
    node *a=head;
    head=head->next;
    free(a);

}

int main(){
    int opt,pvalue;char ch;
    while(1){
        printf("\n1.Insert \n2.Delete\n3.Display\nOption :");scanf("%d",&opt);
        if(opt>3) break;
        switch(opt){
        case 1: printf("\nEnter Char  :");scanf("\n%c",&ch);printf("\nPriority value :");scanf("%d",&pvalue);
                enqueue(ch,pvalue);break;
        case 3:
            display();break;
        case 2:
            dequeue();break;
        }
    }

}
