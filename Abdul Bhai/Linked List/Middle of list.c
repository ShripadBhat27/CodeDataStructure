#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

node* head=NULL;
void create(){
    node *last=head,*a;int d;
    printf("\n-1 to exit\n DATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        a=(node*)malloc(sizeof(node));
        a->data=d;a->next=NULL;
        if(head==NULL)
            head=last=a;
        else{

        last->next=a;
        last=a;
        }
    }


}
void display(){
    node *tr=head;
    printf("\nDATA :");
    while(tr!=NULL){
        printf("%d ",tr->data);tr=tr->next;
    }
}
/*MAKE a pointer move twice as speed as a another pointer ,
 so when a pointer reach last node, another pointer will be at middle
 ,due to speed difference
*/
void middle(){
    node *a,*b;
    a=b=head;
    while(b!=NULL){

        b=b->next;
        if(b!=NULL) {
            b=b->next;
        a=a->next;
        }
    }

    printf("\n MIDDLE ELEMENT : %d",a->data);

}
int main(){
    int opt,res;
    while(1){
        printf("\n1.Create\n2.Display\n3.MIDDLE ELEMENT\nOption :");
        scanf("%d",&opt);
        if(opt>3) break;
        if(opt==1) create();
        else if(opt==2) display();
        else if(opt==3) middle();

    }
}
