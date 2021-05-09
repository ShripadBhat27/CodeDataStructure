#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int rno;
    char nm[15];
    int mrk;
}stu;

typedef struct NODE{
    stu data;
    struct NODE* next;
}node;

node* head=NULL;

void input(stu* a,int no){
    a->rno=no;
    printf("\nEnter Name :");
    scanf("%s",a->nm);
    printf("\nMarks :");
    scanf("%d",&a->mrk);
    system("cls");
}
void display(stu *a){
    printf("\n%5d %-15s %5d",a->rno,a->nm,a->mrk);
}
node* createNode(int no){
    node *a;
    a=(node*)malloc(sizeof(node));
    input(&a->data,no);
    return a;

}

node* search(int no){
    node *a=head;
    while(a!=NULL){
        if ((a->data).rno==no) break;
        a=a->next;
    }
    return a;
}

void add(){
    node *a;int no;
    printf("\nEnter Roll No :");scanf("%d",&no);
    a=search(no);
    if(a!=NULL){
        printf("\nRecord Already Exist.");return;
    }
    a=createNode(no);
    a->next=head;
    head=a;

}
void mod(){
    node*a;
    int no;
    printf("\nEnter Roll No :");scanf("%d",&no);
    a=search(no);
    if(a==NULL){
        printf("\nRecord Not Exist.");return;
    }
    input(&a->data,no);
}

void del(){
    node *a,*b;int no;
    printf("\nEnter Roll No :");scanf("%d",&no);
    b=search(no);
    if(b==NULL){
        printf("\nRecord Not Exist.");return;
    }
    if(b==head)
        head=b->next;
    else {
        a=head;
        while(a->next!=b)
            a=a->next;
        a->next=b->next;
    }
    free(b);

}

void displayall(){
    node *a=head;

    while(a!=NULL){
        display(&a->data);
    a=a->next;
    }
}
void main(){
    int d,opt;
    printf("\n====================STUDENT RECORD============================\n");
    while(1){
        printf("\nMENU\n1.Add\n2.Modify\n3.Delete\n4.Display.\n5.Search\n6.Exit\nOption :");
        scanf("%d",&opt);
        if(opt>5) break;
        switch(opt){
        case 1:
            add();break;
        case 2:
            mod();break;
        case 3:
            del();break;
        case 4:
            displayall();break;
        case 5:
            printf("\nEnter Roll no to search :");scanf("%d",&d);
            if(search(d)==NULL) printf("\nNOT FOUND.");
            else printf("\nFOUND.");break;



        }

    }


}
