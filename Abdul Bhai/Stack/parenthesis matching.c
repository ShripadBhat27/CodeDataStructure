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
int isBalanced(char *st){
    int i=0;char ch;
    while(st[i]!='\0'){
        if(st[i]=='('||st[i]=='['||st[i]=='{')
            push(st[i]);
        else if(st[i]==')'){
            if(top==NULL) return 0;
            ch=pop();

            if(ch=!'(') return 0;
        }
        else if(st[i]==']'){
            if(top==NULL) return 0;
            ch=pop();
            if(ch!='[') return 0;
        }
        else if(st[i]=='}'){
            if(top==NULL) return 0;
            if(pop()!='{') return 0;
        }
        i++;
    }
    if(top==NULL) return 1;
    else return 0;
}
void main(){
    char s[100];
    printf("\nENTER Expression :");
    gets(s);
    if(isBalanced(s))
        printf("\nBALANCED EXPRESSION.");
    else
        printf("\nUNBALANCED EXPRESSION.");

}
