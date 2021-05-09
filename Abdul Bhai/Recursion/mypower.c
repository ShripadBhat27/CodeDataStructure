#include<stdio.h>
int mypower(int p,int q){
    if(q==0)
        return 1;

    if(q==1)
        return p;
    else
        return mypower(p,q-1)*p;
}
int main(){
 int base,power;
 printf("\nEnter Base :");scanf("%d",&base);
 printf("\nPower to be raised :");scanf("%d",&power);
 printf("\nANSWER :%d",mypower(base,power));
 return 0;

}
