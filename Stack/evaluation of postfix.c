#include<stdio.h>
struct Stack{
    int top;
    int arr[10];
}s;
void init(){s.top=-1;}
int isEmpty(){return s.top==-1;}
void push(int a){s.top++;s.arr[s.top]=a;}
int pop(){return s.arr[s.top--];}
int cmp(int a,int b,char opr){
    int res;
    switch(opr){
    case '+': res=a+b;break;
    case '-': res=a-b;break;
    case '*': res=a*b;break;
    case '/': res=a/b;break;
    }
    return res;
}
void main(){
    char post[50],ch;
    int a,b,res,index,i;
    static int val[26]; //initialize to 0
    init();
    printf("\nEnter POSTFiX :");scanf("%s",post);
    for(i=0;post[i]!='\0';i++){
        if(post[i]>=65&&post[i]<=90){
            index=post[i]-65;
            printf("\nValue of %c :",post[i]);scanf("%d",&val[index]);
        }
    }
    for(i=0;post[i]!='\0';i++){
        if(post[i]>=65&&post[i]<=90){
            index=post[i]-65;
            push(val[index]);
        }
        else{
            b=pop();a=pop();
            res=cmp(a,b,post[i]);
            push(res);
        }
    }
    printf("\nReSult :%d",pop());
    return;

}
