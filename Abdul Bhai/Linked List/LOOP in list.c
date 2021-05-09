/*If last Node is pointing to Node other than First Node it said that there
 there is LOOP in List
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;
}node;
node *head=NULL,*last;

void createList(){
    node *a;
    int d;
    printf("\n-1 to Exit.\nDATA :");
    while(1){
        scanf("%d",&d);
        if(d==-1) break;
        a=(node*)malloc(sizeof(node));
        a->data=d;
        a->next=NULL;
        if(head==NULL)
            head=last=a;
        else{
            last->next=a;
            last=a;
        }
    }


}
/*Run two pointer at different rate, if LOOP present they will meet again*/
int isLOOP(){
    node *a,*b;
    a=b=head;
    do{
        a=a->next;
        b=b->next;
        if(b!=NULL)
            b=b->next;
    }while(a!=NULL&&b!=NULL&&a!=b);

    return (a==b);
}

int main(){
    createList();
   //making loop in list
    last->next=head->next->next;

    if(isLOOP()) printf("\nLOOP EXIST IN LIST.");
    else printf("\nLOOP DOESN'T EXIST IN LIST");
    return 0;

}
