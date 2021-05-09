#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;
node* createNode(int d){
    node* a=(node*)malloc(sizeof(node));
    a->data=d;
    a->next=NULL;
    return a;


}
node* st=NULL;  //points last node
void addEnd(int d){
    node *a=createNode(d);
    if(st==NULL)
        a->next=a;
    else{
        a->next=st->next;
        st->next=a;
    }
    st=a;

}
void addBeg(int d){
 node*a =createNode(d);
 if(st==NULL)
    {a->next=a;st=a;}
 else{

    a->next=st->next;
    st->next=a;
 }

}

void display(){

    if(st==NULL)
            printf("\nEMpty");

    else{
        node* a=st->next;
    while(1){

        printf("%d ",a->data);
        if(a==st) break;

        a=a->next;
    }printf("\n");
    }
}
void delfirst(){
    if(st==NULL) {printf("\nEMPTY LIST");return;}

    node* a=st->next;
    if(a==st)
        st=NULL;
    else
    st->next=a->next;
    free(a);


}
void delEnd(){

    node *a=st,*b;
    if(st==NULL) printf("\nEmpTy");
    else if(a==a->next)
        st=NULL;
    else{
        b=a->next;
        while(b->next!=a)
            b=b->next;
        b->next=a->next;
        st=b;
    }
    free(a);
}
void main(){
    int opt,val;
    while(1){
        printf("\n1.Add end\n2.Add begin\n3.Display\n4.Del first\n5.Del Last\nOption :");scanf("%d",&opt);
        if(opt>5) break;
        switch(opt){
        case 1:
        printf("\nEnter value to add End :");scanf("%d",&val);
        addEnd(val);break;

        case 2:
        printf("\nEnter value to add Begin :");scanf("%d",&val);
        addBeg(val);break;
        case 3:
            display();break;
        case 4:
            delfirst();break;
        case 5:
            delEnd();break;

        }
    }

}
