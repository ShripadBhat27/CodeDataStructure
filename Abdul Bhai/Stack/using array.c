#include<stdio.h>
#include<stdlib.h>
typedef struct STACK{
    int size;
    int top;	
    int* arr;
}stack;
void init(stack *t){
    printf("\nEnter size of Array :");scanf("%d",&t->size);
    t->top=-1;
    t->arr=(int*)malloc(sizeof(int)*t->size);
}
void push(stack *t,int d){
    if(t->top==t->size-1)
        printf("\nSTACK OVERFLOW");
    else{
        t->top++;

        t->arr[t->top]=d;

    }
}
int  pop(stack *t){
    int i=-1;
    if(t->top==-1)
        printf("\nSTACK UNDERFLOW");
    else
        i=t->arr[t->top--];
    return i;
}
void display(stack *t){
    if(t->top==-1){printf("\nEMPTY");return;}
    printf("\n DATA :");
    for(int i=t->top;i>=0;i--)
        printf("%d ",t->arr[i]);
    printf("\n");
}
int peek(stack t,int pos){
    if(pos<1||pos>t.size) return -1;
    else return t.arr[t.top-pos+1];

}
int isEmpty(stack t){
    return (t.top==-1);
}
int isFull(stack t){
    return (t.top==t.size-1);
}
int getTop(stack t){
    return t.arr[t.top];
}
int main(){
    stack st;
    int opt,val;
    while(1){
        printf("\n1.Create\n2.Push\n3.Pop\n4.Display\n5.Peek\n6.Get Top\n7.Is Empty \n8.Is Full\nOption :");
        scanf("%d",&opt);
        if(opt>8) break;
        switch(opt){
        case 1:
            init(&st);break;
        case 2:
            printf("\nENTER VALUE :");scanf("%d",&val);
            push(&st,val);break;
        case 3:
            val=pop(&st);
            if(val!=-1) printf("\nPopped Element :%d",val);break;
        case 4:
            display(&st);break;
        case 5:
            printf("\nPosition of Element from Top :");scanf("%d",&val);
            printf("\nElement is %d",peek(st,val));break;


        case 6:
            printf("\nTop Element :%d",getTop(st));break;
        case 7:
            if(isEmpty(st))
                printf("\n EMPTY");
            else printf("\nNOT EMPTY");break;
        case 8:
            if(isFull(st))
                printf("\n FULL");
            else printf("\nNOT FULL");break;

        }

    }

}
