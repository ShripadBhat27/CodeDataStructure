#include<stdio.h>
struct Stack{
    int top;
    char opr[50];
}s;
void init(){s.top=-1;}
void push(char ch){
    s.opr[++s.top]=ch;
}
void pop(){s.top--;}
int isEmpty(){return s.top==-1;}
int preced(char top,int opr){
    if(top!='('&&opr==')') return 1;
    return 0;
}
void main(){
    char in[50],po[50];
    int i=0,j=0;
    init();
    printf("\nEnter Infix Expression :");scanf("%s",in);
    while(in[i]!='\0'){
        if(in[i]>=65&&in[i]<=90)
            po[j++]=in[i];
        else{
            while(!isEmpty()&&preced(s.opr[s.top],in[i])){
                po[j++]=s.opr[s.top];
                pop();
            }
            if(isEmpty()||in[i]!=')')
                push(in[i]);
            else
                pop();
        }
        i++;
    }
    while(!isEmpty()){
        po[j++]=s.opr[s.top];
        pop();
    }
    po[j]='\0';
    printf("\nPOSTFIX : %s",po);
    return;
}
