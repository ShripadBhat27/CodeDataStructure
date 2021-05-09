/*Taylor series for computing e to power x
e^x= 1+x/1! + x^2/2! + x^3/3! .....

*/
#include<stdio.h>
double e(int,int);
double p=1,f=1; // p is increasing power num & f is factorial in deno
//n ->power of x
double e(int x,int n){

    double r;
    if(n==0)
        return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;


}

void main(){

   int x,n;
    printf("\nx :");scanf("%d",&x);
    printf("\nn :");scanf("%d",&n);

    printf("\n  %lf",e(x,n));
}
