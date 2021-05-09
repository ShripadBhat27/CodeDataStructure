#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coe;
    int man;
    struct poly* next;
}NODE;

typedef struct Poly{
    NODE* st;
}POLY;

void init(POLY *t){
    t->st=NULL;
}
NODE* createNode(int c,int m){
    NODE *a=(NODE*)malloc(sizeof(NODE));
    a->coe=c;a->man=m;
    a->next=NULL;
    return a;
}
void display(POLY *t){
    NODE *a=t->st;
    if(a==NULL) {printf("\nEMPTY ");return;}
    printf("\n POLYNOMIAL:");
    while(a!=NULL){
        if(a->coe>0) printf("+");
        printf("%dx%d",a->coe,a->man);a=a->next;
    }
}

void createList(POLY *t){
    int c,m;
    NODE *a=t->st,*b;
    while(t->st!=NULL){ // empty the list
        t->st=a->next;
        free(a);
        a=t->st;
    }
    while(1){
        printf("\nCoefficient & Mantissa :");
        scanf("%d %d",&c,&m);
        if(c==0&&m==0) break;
        if(c==0) continue;
        if(t->st==NULL)
            t->st=a=createNode(c,m);
        else{
            if(m>=b->man) {
                printf("\nINVALID , PLEASE FOLLOW ORDER");continue;
            }
            a=createNode(c,m);
            b->next=a;
        }
        b=a;
    }
}

void sort(POLY *t){
    int co,mo;
    NODE *a=t->st,*b,*c;
    while(a->next!=NULL){
        b=a;
        c=a->next;
        while(c!=NULL){
            if(c->man>b->man)
                b=c;
            c=c->next;
        }
        if(a!=b){
            co=a->coe;
            a->coe=b->coe;
            b->coe=co;
            mo=a->man;
            a->man=b->man;
            b->man=mo;
        }
        a=a->next;
    }
}
void add(POLY *r,POLY *p,POLY *q){
    NODE *a=p->st,*b=q->st,*c,*d;
    int co,ma;
    delAll(r);
    while(a!=NULL&&b!=NULL){
        if(a->man==b->man){
            co=a->coe+b->coe;
            ma=a->man;
            a=a->next;b=b->next;
        }
        else{
            if(a->man>b->man){
                co=a->coe;ma=a->man;a=a->next;
            }
            else{
                co=b->coe;ma=b->man;b=b->next;
            }
        }
        if(r->st==NULL)
            r->st=c=createNode(co,ma);
        else{
            c=createNode(co,ma);
            d->next=c;
        }
        d=c;
    }
    while(a!=NULL){c=createNode(a->coe,a->man);d->next=c;d=c;a=a->next;}
    while(b!=NULL){c=createNode(b->coe,b->man);d->next=c;d=c;b=b->next;}

}
void sub(POLY *r,POLY *p,POLY *q){
    NODE *a=p->st,*b=q->st,*c,*d;
    int co,ma;
    delAll(r);
    while(a!=NULL&&b!=NULL){
        if(a->man==b->man){
            co=a->coe-b->coe;
            ma=a->man;
            a=a->next;b=b->next;
        }
        else{
            if(a->man>b->man){
                co=a->coe;ma=a->man;a=a->next;
            }
            else{
                co=-b->coe;ma=b->man;b=b->next;
            }
        }
        if(r->st==NULL)
            r->st=c=createNode(co,ma);
        else{
            c=createNode(co,ma);
            d->next=c;
        }
        d=c;
    }
    while(a!=NULL){c=createNode(a->coe,a->man);d->next=c;d=c;a=a->next;}
    while(b!=NULL){c=createNode(-b->coe,b->man);d->next=c;d=c;b=b->next;}

}
void delAll(POLY *r){
    NODE *a=r->st;
    while(r->st!=NULL){
        r->st=a->next;
        free(a);
        a=r->st;
    }
}
void multiply(POLY *r,POLY *p,POLY *q){
    NODE *a=p->st,*b=q->st,*c,*d;
    int co,ma;
    delAll(r);
    while(b!=NULL){
        a=p->st;
        while(a!=NULL){
            co=a->coe*b->coe;
            ma=a->man+b->man;
            if(r->st==NULL)
                r->st=c=createNode(co,ma);
            else{
                c=createNode(co,ma);
                d->next=c;
            }d=c;
            a=a->next;
        }
        b=b->next;
    }
    sort(r);
    a=r->st;
    for(b=a,a=a->next;a!=NULL;)
        {
        if(a->man==b->man){
            b->coe=a->coe+b->coe;b->next=a->next;
            free(a);a=b->next;
        }
        else{
            b=a;
            a=a->next;
        }
    }
}
void main(){
    int opt; POLY a,b,c;
    init(&a);init(&b);init(&c);
    while(1){
        printf("\n1.Create Poly 1\n2.Create Poly 2\n3.Display Poly 1\n4.Display Poly 2\n5.Display Poly 3.\n6.Add\n7.Subtract\n8.Multiply \n9.Exit\nOption : ");
        scanf("%d",&opt);
        if(opt>9) break;
        switch(opt){
        case 1: createList(&a);break;
        case 2: createList(&b);break;
        case 3: display(&a);break;
        case 4: display(&b);break;
        case 5: display(&c);break;
        case 6: add(&c,&a,&b);break;
        case 7: sub(&c,&a,&b);break;
        case 8: multiply(&c,&a,&b);break;
        }
    }
}
