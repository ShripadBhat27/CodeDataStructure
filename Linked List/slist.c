#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

typedef struct slist{

    node* st;
}SLIST;
//fn to initialize
void init(SLIST *t){
    t->st=NULL;

}
node* createNode(int d){
    node *a;
    a=(node*)malloc(sizeof(node));
    a->data=d;
    a->next=NULL;

}
node* getLastNode(SLIST *t){
    node *a=t->st;
    while(a->next!=NULL){
        a=a->next;
    }
    return a;
}

void addEnd(SLIST *t,int d){
    node *a=createNode(d);
    if(t->st==NULL)
        t->st=a;
    else{
        node *b=getLastNode(t);
        b->next=a;
    }
}
void display(SLIST *t){
    node *tr=t->st;
    printf("\n");
    if(tr==NULL){
        printf("Empty List.");return ;
    }
    while(tr!=NULL){
        printf("%d ",tr->data);
        tr=tr->next;
    }
}

void delAll(SLIST *t){
    node *a=t->st;
    while(t->st!=NULL){
        t->st=a->next;
        free(a);
        a=t->st;

    }

}

int isOrdered(SLIST *t){
    node *a=t->st,*b;
    while(a!=NULL){
        if(a!=t->st)
            if(a->data<b->data)
                break;
        b=a;
        a=a->next;
    }
    return (a==NULL);

}
void createList(SLIST *t){
    int d;
    printf("\n-1 to exit.\nDATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        addEnd(t,d);
    }
}
void sort(SLIST *t){
    node *a=t->st,*b,*c;
    int tmp;
    if(a==NULL) return;
    while(a->next!=NULL){

        b=a;
        c=a->next;
        while(c!=NULL){
            if(c->data<b->data)
                b=c;
            c=c->next;
        }
        if(a!=b){
            tmp=a->data;
            a->data=b->data;
            b->data=tmp;
        }
        a=a->next;
    }


}
void delfirst(SLIST *t){
    node *a=t->st;
    t->st=a->next;
    free(a);

}

void delNode(SLIST *t,int pos){
    int i=1;
    node *a,*b,*c;
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


void merge(SLIST *d,SLIST *p,SLIST *s){
    node *a=p->st,*b=s->st;
    int val;
    delAll(d);
    if(isOrdered(p)==0) sort(p);
    if(isOrdered(s)==0) sort(s);
    while(a!=NULL&&b!=NULL){
        if(a->data<b->data){
            val=a->data;
            a=a->next;
        }
        else{
            val=b->data;
            b=b->next;
        }
        addEnd(d,val);
    }
    while(a!=NULL){
        addEnd(d,a->data);a=a->next;
    }
    while(b!=NULL){
        addEnd(d,b->data);b=b->next;
    }
}
/*void myunion(SLIST *d,SLIST *p,SLIST *s){
    node *a,*b;
    int i=2;
    delAll(d);
    if(isOrdered(p)==0) sort(p);
    if(isOrdered(s)==0) sort(s);
    merge(d,p,s);
    a=d->st;
    b=a->next;
    while(a->next!=NULL){
        if(a->data==b->data){
            delNode(d,i);

        }
        else{
            a=a->next;


            i++;
        }
        b=a->next;
    }



}*/
void myunion(SLIST *d,SLIST *p,SLIST *s){
    node *a,*b;
    delAll(d);
    sort(p);sort(s);
    merge(d,p,s);
    a=d->st;
    for(b=a,a=a->next;a!=NULL;){
        if(b->data!=a->data){
            b=a;
            a=a->next;
        }
        else {
            b->next=a->next;
            free(a);
            a=b->next;
        }
    }


}

void intersect(SLIST *d,SLIST*p,SLIST*s){
    node *a,*b,*c,*t;int val;
    delAll(d);
    a=p->st;b=s->st;
    if(a==NULL||b==NULL) return;
    sort(p);sort(s);
    while(a!=NULL&&b!=NULL){
        if(a->data<b->data)
            a=a->next;
        else if(b->data<a->data)
            b=b->next;
        else {
            val=a->data;
            a=a->next;
            b=b->next;
            if(d->st==NULL)
                d->st=c=createNode(val);
            if(c->data<val){ //unique entry
                t=createNode(val);
                c->next=t;
                c=t;  // c pointing to last node
            }
        }
    }


}
void main(){
    SLIST p,q,r;
    int opt,d,res;
    init(&p),init(&q),init(&r);
    while(1){
        printf("\nMENU\n1.Create List 1\n2.Create List 2\n3.Display List 1\n4.Display List 2\n5.Display List 3\n6.Delete list 1\n7.Delete list 2\n8.Delete list 3\n9.Is list 1 ordered\n10.Is list 2 ordered \n11.Sort list 1\n12.Sort list 2\n13.Merge list 1&2\n14.Union\n15.Intersection\n16Exit\nOPTION :");
        scanf("%d",&opt);
        if(opt>15) break;
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
            printf("ORDERED.\n");break;
        case 10:
            if(isOrdered(&q)==0)
                printf("\nNOT ");
            printf("ORDERED.\n");break;

        case 11:
            sort(&p);break;
        case 12:
            sort(&q);break;
        case 13:
            merge(&r,&p,&q);break;
        case 14:
            myunion(&r,&p,&q);break;
        case 15:
            intersect(&r,&p,&q);break;

        }
    }
}
