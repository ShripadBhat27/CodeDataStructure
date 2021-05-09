#include<stdio.h>

int sum(int n){
    if(n==1)
        return 1;
    else
        return sum(n-1)+n;

}
int factorial(int n){
    if(n==1)
        return 1;
    else
        return factorial(n-1)*n;

}
int main(){
    int n,opt=0;
    while(opt!=3){

    printf("\n1.Sum \n2.Factorial.\n3.Exit\nOption :");
    scanf("%d",&opt);
    if(opt==1){
    printf("\nSum upto how many natural no :");
    scanf("%d",&n);

    printf("\nSUM IS %d",sum(n));}
    else {
        printf("Enter N :");
        scanf("%d",&n);
        printf("\nFACTORIAL OF %d is %d",n,factorial(n));
    }
    }
    return 0;


}
