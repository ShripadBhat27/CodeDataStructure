#include<stdio.h>
#define M 10
typedef struct stack{
    int top;
    char arr[M];
}CSTK;
void init(CSTK *t){
    t->top=-1;
}
int isEmpty(CSTK *t){return t->top==-1;}
void push(CSTK *t,char ch){
    t->top++;
    t->arr[t->top]=ch;
}
char stacktop(CSTK *t){return t->arr[t->top];}
void pop(CSTK *t){ t->top--;}
void main(){
    char a[50];
    int i=0,flg=0;
    CSTK p; init(&p);
    printf("\nEnter Expression :");scanf("%s",a);
    while(a[i]!='\0'){
        if(a[i]=='('){
            push(&p,a[i]);flg=1;
           }
        else{
            if(a[i]==')'){
                if(isEmpty(&p)) break;
                pop(&p);
            }
        }
        i++;
    }
    if(a[i]=='\0'){
        if(isEmpty(&p)){
            if(flg==0) printf("\n\nNO PARENTHESIS.");
            else printf("\n\nBALANCED .");
        }
        else
            printf("\n\nUNBALANCED :LEFT EXTRA.");

    }
    else
           printf("\n\nUNBALANCED :RIGHT EXTRA.");

}
