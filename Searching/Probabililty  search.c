#include<stdio.h>
void main(){
    int x[10],i,j,tmp,sv;
    printf("\nDATA :");
    for(i=0;i<10;i++)
        scanf("%d",&x[i]);
    while(1){
        printf("\n-1 to Exit\nSearch Value :");scanf("%d",&sv);
        if(sv==-1) break;
        for(i=0;i<10;i++)
            if(x[i]==sv) break;
        if(i==10) printf("\n<NOT FOUND>\n");
        else{
            j=i-1;
            if(j>=0){
                tmp=x[i];
                x[i]=x[j];
                x[j]=tmp;
            }
            printf("\n<FOUND>\n");
        }
    }
    return;
}
