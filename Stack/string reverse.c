#include<stdio.h>
#define Size 101
typedef struct STK{
    int top;
    char s[Size];
}stk;
void init(stk* t){
    t->top=-1;
}
void push(stk *t,char c){
    t->top++;
    t->s[t->top]=c;
}
char pop(stk *t){
    return t->s[t->top--];
}
int isEmpty(stk *t){
    return t->top==-1;
}
void main(){
    int i;
    stk rev; init(&rev);
    char st[100],r[100];
    printf("\nEnter string :");gets(st);
    for(i=0;st[i]!='\0';i++)
        push(&rev,st[i]);
    for(i=0;isEmpty(&rev)==0;i++)
        r[i]=pop(&rev);
    r[i]='\0';
    printf("\nREVERSE :");puts(r);
}
