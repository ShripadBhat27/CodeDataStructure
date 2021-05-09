//D4 SHRIPAD BHAT
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}NODE;

typedef struct slist{
    NODE *st;
}SLIST;
//fn to initialize SLIST
void init(SLIST *t){
    t->st=NULL;
}
//fn to create Node
NODE* createNode(int d){
    NODE *a;
    a=(NODE*)malloc(sizeof(int));
    a->data=d;
    a->next=NULL;
    return a;
}
NODE* getLastNode(SLIST *t){
    NODE *a=t->st;
    while(a->next!=NULL)
        a=a->next;
    return a;

}

void addEnd(SLIST *t,int d){
    NODE *a=createNode(d),*b;
    if(t->st==NULL)
        t->st=a;
    else{
        b=getLastNode(t);
        b->next=a;
    }

}

void addBeg(SLIST *t,int d){
    NODE *a=createNode(d);
    a->next=t->st;
    t->st=a;
}

void display(SLIST *t){
    NODE *a=t->st;
    if(t->st==NULL)
        printf("\nEMPTY LIST");
    else {
        while(a!=NULL){
            printf("%d ",a->data);
            a=a->next;
        }
    }

}
//fn to check if list is ordered,yes (1) ,no (0)
int isOrdered(SLIST *t){
    NODE *a=t->st,*b;
    while(a!=NULL){
            if(a!=t->st){
                if(a->data<b->data)
                    break;
            }
            b=a;
            a=a->next;

    }
    return (a==NULL);
}
int count(SLIST *t){
    int cnt=0;
    NODE *a=t->st;
    while(a!=NULL){
        cnt++;
        a=a->next;
    }
    return cnt;
}

int findMax(SLIST *t){
    NODE *a=t->st;
    int max=a->data;
    for(a=a->next;a!=NULL;a=a->next)
        if(a->data>max)
            max=a->data;
    return max;


}
int findMin(SLIST *t){
    NODE *a=t->st;
    int min=a->data;
    for(a=a->next;a!=NULL;a=a->next)
        if(a->data<min)
            min=a->data;
    return min;


}

void findReplace(SLIST *a,int sv,int rv){
    NODE *t=a->st;
    while(t!=NULL){
        if(t->data==sv)
            t->data=rv;
        t=t->next;
    }


}

void delfirst(SLIST *t){
    NODE *a=t->st;
    t->st=a->next;
    free(a);

}
void delLast(SLIST *t){
    NODE *a=t->st,*b;
    if(a->next==NULL)
        t->st=NULL;
    else{
        while(a->next!=NULL){
            b=a;a=a->next;
        }
        b->next=NULL;
    }
    free(a);
}
void delAll(SLIST *p){
    NODE *a=p->st;
    while(p->st!=NULL){
        p->st=a->next;
        free(a);
        a=p->st;
    }
}

void insertA(SLIST *t,int pos,int d){
    int i=1;
    NODE *a,*b,*c;
    if(pos<1||t->st==NULL)
        return ;
    a=t->st;
    while(i<=pos&&a!=NULL){
        b=a;
        a=a->next;
        i++;
    }
    if(i<pos){
        printf("\nINVALID REQUEST.");return;
    }
    c=createNode(d);
    b->next=c;
    c->next=a;
}
void insertB(SLIST *t,int pos,int d){
    int i=1;
    NODE *a,*b,*c;
    if(pos<1||t->st==NULL)
        return ;
    if(pos==1)
        addBeg(t,d);
    else{
    a=t->st;
    while(i<pos&&a!=NULL){
        b=a;
        a=a->next;
        i++;
    }
    if(a==NULL){
        printf("\nINVALID REQUEST.");return;
    }
    c=createNode(d);
    b->next=c;
    c->next=a;
    }
}
void delNode(SLIST *t,int pos){
    int i=1;
    NODE *a,*b,*c;
    if(pos<1||t->st==NULL)
        return ;
    if(pos==1)
        delfirst(t);
    else{
        a=t->st;
        while(i<pos&&a!=NULL){
            b=a;
            a=a->next;
            i++;
        }
        if(a==NULL){
           printf("\nINVLAID");return;
        }
        b->next=a->next;
        free(a);

    }


}

void copy(SLIST *d,SLIST *s){
    NODE *a,*b,*c;
    if(s->st==NULL){
        printf("\nSOURCE MISSING");return;
    }
    if(d->st!=NULL)
        delAll(d);
    c=s->st;
    while(c!=NULL){
        a=createNode(c->data);
        if(d->st==NULL)
            d->st=a;
        else
            b->next=a;
        b=a;
        c=c->next;
    }
}
void createList(SLIST *t){
    int d;
    printf("\nDATA :");
    while(1){
        scanf("%d",&d);
        if(d==0) break;
        addEnd(t,d);
    }


}

void main(){
    int  opt,d,res,sv,rv;
    SLIST p,q,r;
    init(&p);init(&q);init(&r);
    while(1){
        printf("\nMENU\n1.Create List 1\n2.Create List 2\n3.Display List 1\n4.Display List 2\n5.Display List 3\n6.Delete list 1\n7.Delete list 2\n8.Delete list 3\n9.Is list 1 ordered\n10.Is list 2 ordered \n11.Sort list 1\n12.Sort list 2\n13.Exit\nOPTION :");
        scanf("%d",&opt);
        if(opt>12) break;
        switch(opt){
        case 1:
            createList(&p);break;
        case 2:
            createList(&q);break;
        case 3:
            display(&p);break;
        case 4:
            display(&q);break;
        case 5:
            display(&r);break;
        case 6:
            delAll(&p);break;
        case 7:
            delAll(&q);break;
        case 8:
            delAll(&r);break;
        case 9:
            if(isOrdered(&p)==0)
                printf("\nNOT ");
            printf("FOUND.");break;
        case 10:
            if(isOrdered(&q)==0)
                printf("\nNOT ");
            printf("FOUND.");break;
        /*
        case 11:
            sort(&p);break;
        case 12:
            sort(&q);break;
        */

        }
    }

}
