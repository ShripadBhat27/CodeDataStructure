/*
x=6+3+9*8;
first operation performed by complier is not multiplication
x=((6+3)+(9*8))
so '+' is first operation performed
NOTE :precedence & association is only of parenthesis expression
*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;
node *top=NULL;
void push(int c){
    node* a;
    a=(node*)malloc(sizeof(node));
    a->data=c;a->next=NULL;
    if(top==NULL)
        top=a;
    else{
        a->next=top;
        top=a;
    }
}
int pop(){
    int  c;node *a=top;
    c=top->data;
    top=top->next;
    free(a);
    return c;
}
int isEmpty(){
    return top==NULL;
}
//check is operand or operator
int isOperand(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/')  return 0;
    return 1;
}

int evalue(char *postfix){
    int r,x1,x2,i;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i]))
        push(postfix[i]-'0');
        else {
            x2=pop();x1=pop();
            switch(postfix[i]){
            case '+': r=x1+x2;push(r);break;
            case '-': r=x1-x2;push(r);break;
            case '*': r=x1*x2;push(r);break;
            case '/': r=x1/x2;push(r);break;
            }
        }

    }
    return pop();

}

void main(){
    char postfix[100];
    printf("\nEnter Postfix Expression :");scanf("%s",postfix);
    //pushing random char to stack

    int result=evalue(postfix);
    printf("\nExpression Result :%d",result);
}

