#include<stdio.h>
#include<stdlib.h>
typedef struct NOde{
    int data;
    struct NOde* next;
}node;

node *head=NULL,*last=NULL;
void enqueue(int d){
    node*a;
    a=(node*)malloc(sizeof(node));a->data=d;a->next=NULL;
    if(head==NULL){
        head=last=a;
    }
    else{
        last->next=a;
        last=a;
    }
}
int dequeue(){
    node *a=head;
    head=head->next;
    int x=a->data;
    free(a);
    return x;

}
void display(){
    node* tr=head;printf("\nDATA :");
    while(tr){
        printf("%d ",tr->data);tr=tr->next;
    }
}
//reverse queue
void reverse(){
    if(head!=NULL){
        int x=dequeue();
        reverse();
        enqueue(x);
    }
}
int main(){
    int opt,d;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Reverse\nOption :");scanf("%d",&opt);
        if(opt>4) break;
        switch(opt){
        case 1: printf("\nVALUE :");scanf("%d",&d);enqueue(d);break;
        case 2: printf("\nDeleted Element :%d",dequeue());break;
        case 3: display();break;
        case 4: reverse();break;
        }
    }

}
