#include<stdio.h>

void main(){
    int x[11],i,sv;
    printf("\nArray DATA :");
    i=0;
    while(i<10){
        scanf("%d",&x[i]);
        if(i&&x[i]<x[i-1]){
            printf("\nINVALID.\n");continue;
        }
        i++;
    }
    printf("\nSearch Value :");
    scanf("%d",&x[10]);
    if(x[10]>x[9]) printf("\n<NOT FOUND>");
    else{
        i=0;
        while(x[i]<x[10]) i++;
        if(x[i]==x[10]) printf("\nFOUND.");
        else printf("\nNOT FOUND.");
    }

}
