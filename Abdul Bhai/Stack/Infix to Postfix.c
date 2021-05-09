/*
Concept -> copy operand directly to destination
push operator in stack
if next operator precedence is more than the one in stack push
    else pop the top and continue with new top
*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char data;
    struct Node* next;
}node;
node *top=NULL;
void push(char c){
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
char pop(){
    char c;node *a=top;
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
int precedence(char ch){
    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*'||ch=='/') return 2;
    return 0;
}
char* convert(char* infix){
    int i=0,j=0;
    int n=strlen(infix);
    char *postfix=(char*)malloc(sizeof(char)*(n+2));//extra for null char
    while(infix[i]!='\0'){
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(precedence(infix[i])>precedence(top->data)) //to avoid error for first operator ,insert random char in stack
                push(infix[i++]); //advance to next char
            else
                postfix[j++]=pop();
        }
    }
        while(top->next!=NULL)
            postfix[j++]=pop();
        postfix[j]='\0';
        return postfix;
}

void main(){
    char infix[100];
    char *postfix;
    printf("\nEnter Expression :");scanf("%s",infix);
    //pushing random char to stack
    push('#');
    postfix=convert(infix);
    printf("\nPOSTFIX :%s",postfix);
}
