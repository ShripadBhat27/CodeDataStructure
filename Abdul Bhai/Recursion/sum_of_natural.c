#include<stdio.h>

int sum(int n){
    if(n==1)
        return 1;
    else
        return sum(n-1)+n;

}
int main(){
    int n;
    printf("\nSum upto how many natural no :");
    scanf("%d",&n);
    printf("\nSUM IS %d",sum(n));
    return 0;


}
