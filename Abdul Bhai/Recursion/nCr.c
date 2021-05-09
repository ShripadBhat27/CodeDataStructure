#include<stdio.h>
/*Using Pascal Triangle
    nCr= (n-1)C(r-1)+(n-1)Cr
*/
float C(int n,int r){

    if(r==0||n==r)
        return 1;
    else
        return C(n-1,r-1)+C(n-1,r);


}

int main(){
    int n,r;
    float res;
    printf("\n FOR nCr \n");
    printf(" N :");scanf("%d",&n);
    printf("\n R :");scanf("%d",&r);
    res=C(n,r);
    printf(" Answer :%f",res);
    return 0;

}
