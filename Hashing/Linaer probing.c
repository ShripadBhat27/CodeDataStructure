#include<stdio.h>

typedef struct student{
    int rno;
    char nm[15];
}stu;

stu a[10]; //hash table
void init(){
    for(int i=0;i<10;i++)
        a[i].rno=0;
}
int hash(int no){
    return no%10;
}

void insert(){
    int i=0,j=0,no;
    printf("\nRoll No :");
    scanf("%d",&no);
    i=hash(no);
    if(a[i].rno==0){ //check if home address is empty
        a[i].rno=no;
        printf("\nEnter Name :");scanf("%s",a[i].nm);
        printf("\nINSERTION AT HOME ADDRESS.");return;
    }
    printf("\nCOLLISON OCCURED.");
    for(j=i+1;j<10;j++){ //checking ahead in array
        if(a[j].rno==0){
            a[j].rno=no;
            printf("\nEnter Name :");scanf("%s",a[j].nm);
            break;
        }
    }
    if(j<10){
        printf("\nInsertion on Collision Path.");return;
    }
    for(j=0;j<i;j++){ //checking from starting
         if(a[j].rno==0){
            a[j].rno=no;
            printf("\nEnter Name :");scanf("%s",a[j].nm);
            break;
        }
    }
    if(j==i){
        printf("\n< OVERFLOW >.");
    }
    else
        printf("\n INSERTION on Collision path.");

}

void search(){
    int i=0,j=0,no;
    printf("\nEnter Value to be searched :");scanf("%d",&no);
    i=hash(no);
    if(a[i].rno==no){
        printf("\nFOUND NAME at Home Address %d:%s",i,a[i].nm);
        return;
    }
    printf("\nSearching on Collision Path ...");
    for(j=i+1;j<10;j++){
        if(a[j].rno==no){
            printf("\n FOUND ON COLLISON PATH AT %d",j);
            printf("\nNAME :%s",a[j].nm);return;
        }
    }
    for(j=0;j<i;j++){
        if(a[j].rno==no){
            printf("\n FOUND ON COLLISON PATH AT %d",j);
            printf("\nNAME :%s",a[j].nm);return;
        }
    }
    printf("\n<NOT FOUND >");
}
int main(){
    int opt;
    init();
    while(1){
        printf("\n1.Insert \n2 search \nOption :");
        scanf("%d",&opt);
        if(opt==1) insert();
        else if(opt==2) search();
        else break;
    }
}
