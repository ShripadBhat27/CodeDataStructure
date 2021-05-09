#include<stdio.h>

/*In this function, same function is called multiple time
As for fibo(5)..fibo(2) is called multiple times

*/
int fibo(int n){

    if(n<2) return n;
    else
        return fibo(n-1)+fibo(n-2);

}

int F[20] ;
void initailize(){
    for(int i=0;i<20;i++)
        F[i]=-1;

}
/*Efficient way can be storing value of already called function in array
    and using it without calling function
    This method is called Memorizing
*/
int mfibo(int n){
    if(n<2){
        F[n]=n;
        return n;
    }
    if(F[n-2]==-1)
        F[n-2]=mfibo(n-2);
    if(F[n-1]==-1)
        F[n-1]=mfibo(n-1);
    return F[n-1]+F[n-2];
}




int main(){
    initailize();
    int no;
    printf("\nNth number of series :");
    scanf("%d",&no);
    printf("\n%d th no of series :%d",no,mfibo(no));
    return 0;


}
