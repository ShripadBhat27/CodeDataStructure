/*
Concept -> copy operand directly to destination
push operator in stack
if next operator precedence is more than the one in stack push
    else pop the top and continue with new top
*/
/*
    Symbol        Out of stack            Inside of Stack
                  precedence                precedence

    +,-             1                           2
    *,/             3                           4
    ^               6                           5
    (               7                           0
     )              0                           -

Observation: for operator (L-R association ) precedence out to in increase
            for operator (R-L association ) precedence out to in increase

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
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='('||c==')')  return 0;
    return 1;
}
int outprecedence(char ch){
    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*'||ch=='/') return 3;
    else if(ch=='^') return 6;
    else if(ch=='(') return 7;
    else if(ch==')') return 0;

}
int inprecedence(char ch){
    if(ch=='+'||ch=='-') return 2;
    else if(ch=='*'||ch=='/') return 4;
    else if(ch=='^') return 5;
    else if(ch=='(') return 0;

    return -1;//for starting garbage
}
char* convert(char* infix){
    int i=0,j=0;char t;
    int n=strlen(infix);
    char *postfix=(char*)malloc(sizeof(char)*(n+2));//extra for null char
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
                if(infix[i]==')') postfix[j++]=pop();
                else
                postfix[j++]=infix[i++];
        }
        else{
            if(outprecedence(infix[i])>inprecedence(top->data)) //to avoid error for first operator ,insert random char in stack
                push(infix[i++]); //advance to next char
            else{
                t=pop();
                if(t!='(') postfix[j++]=t;
            }
        }
    }
        while(top->next!=NULL)
            {
                t=pop();
                if(t!='('&&t!=')') postfix[j++]=t;
            }
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
