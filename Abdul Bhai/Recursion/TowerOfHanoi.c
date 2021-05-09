/*
TOWER OF HANOI
GIVEN-> 3 Towers. t1 has number of disc. t2 &t3 are empty towers
TASK -> To move all disc from t1 to t3 using t2
CONDITION -> i.Move one disc at a time
             ii.Larger disc SHOULDN'T be kept over smaller one

OUTPUT -> MOVES to perform in order to complete task.


*/

//parameter(no_of_disc,Source, Auxiliary, Destination)
void TOH(int n,char t1,char t2,char t3){

    if(n>0){
        TOH(n-1,t1,t3,t2); //move n-1 from A to B
        printf("\n %c -> %c",t1,t3); //move 1 from A to C
        TOH(n-1,t2,t1,t3); //move n-1 from B to C
    }
}
void main(){
    int n;
    char t1='A',t2='B',t3='C';
    printf("\nENTER NO OF DISC IN TOWER A :");scanf("%d",&n);
    printf("\n MOVES \n");
    TOH(n,t1,t2,t3);
    printf("\n\n");
}
