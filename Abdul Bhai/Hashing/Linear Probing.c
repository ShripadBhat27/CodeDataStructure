/*
    CLOSE HASHING : As it don't use extra Space,to resolve collision

    lambda always less than 1
    ideally should be less than 0.5

*/

#include<stdio.h>
#define size 10
int hash(int key){
    return key%size;
}
int probe(int h[],int key){
    int index=hash(key),i=0;
    while(h[(index+i)%size]!=0)
        i++;
    return (index+i)%size;
}
void insert(int h[],int key){
    int index=hash(key);
    if(h[index]!=0)
        index=probe(h,key);
    h[index]=key;

}
int search(int h[],int key){
    int index=hash(key);
    int i=0;
    while(h[(index+i)%size]!=key)
        i++;
    return (index+i)%size;
}
int main(){
    int HT[size]={0};
    insert(HT,12);
    insert(HT,22);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26);
    printf("\nElement found at %d",search(HT,35));
    return;
}
