#include<stdio.h>
#define M 5
typedef struct cqueue{
    int fr,rr;
    int arr[M];
}CQUE;
void init(CQUE *t){
    t->fr=t->rr=M-1;
    for(int i=0;i<M;i++)
        t->arr[i]=-1;
}
int cnt(CQUE *t){
    int i=0,c=0;
    while(i<M){
        if(t->arr[i]==-1) c++;
        i++;
    }
    return c;
}
void insert(CQUE *t,int d){
    if(cnt(t)==0) {printf("\n<OVERFLOW");return;}
    if(t->rr==M-1)
        t->rr=0;
    else t->rr++;
    t->arr[t->rr]=d;
}
void del(CQUE *t){

    if(cnt(t)==M){
        printf("<UNDERFLOW>");return;
    }
     if(t->fr==M-1)
        t->fr=0;
    else t->fr++;
    t->arr[t->rr]=-1;
}
void display(CQUE *t){printf("\n");
    if(cnt(t)==M){
        printf("\nEMPTY,");return;
    }
    else{
        if(t->fr<t->rr){
            for(int i=t->fr++;i<=t->rr;i++)
                printf("%5d",t->arr[i]);
        }
        else{
            int i;
            for(i=t->fr++;i<M;i++)
                printf("%5d",t->arr[i]);
            for(i=0;i<=t->rr;i++)
                printf("%5d",t->arr[i]);
        }
    }
}
void menu(CQUE *t){
    int opt,d;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\nOption :");
        scanf("%d",&opt);
        if(opt>3) break;
        switch(opt){
        case 1:
            printf("\nEnter Value :");scanf("%d",&d);
            insert(t,d);break;
        case 2:
            del(t);break;
        case 3:
            display(t);break;
        }
    }
}
void main(){
    CQUE q;
    init(&q);menu(&q);
}
