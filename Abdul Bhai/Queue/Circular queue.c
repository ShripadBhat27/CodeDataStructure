/*Drawback of simple array queue is we cannot use deleted element space.
Each Memory block is been used only once.
Solution : 1. Resetting pointer-> once queue is full, we can reset back pointer
,however this works only if all elements are deleted
2. Circular Queue => Best WAY to implement using Array.
front and rear pointer move circularly, using % operator.
Once block is deliberately kept empty, cause front==rear is Empty condition
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int size,front,rear;
    int *arr;
}queue;
void init(queue *t){
    printf("\nEnter Size of array :");scanf("%d",&t->size);
    t->front=t->rear=0;
    t->arr=(int*)malloc(sizeof(int)*t->size);
}
void enqueue(queue *t,int d){
    if((t->rear+1)%t->size==t->front)
        printf("\nQueue is FULL.");
    else {
        t->rear=(t->rear+1)%t->size;
        t->arr[t->rear]=d;
    }
}
int dequeue(queue *t){
    int x=-1;
    if(t->rear==t->front) printf("\nEmpty Queue");
    else {
        t->front=(t->front+1)%t->size;
        x=t->arr[t->front];
    }
    return x;
}
void display(queue t){
    int i=(t.front+1)%t.size;
    if(t.rear==t.front) {printf("\nEmpty Queue");return;}
    printf("\nDATA :");
    do{
        printf("%d ",t.arr[i]);
        i=(i+1)%t.size;

    }while(i!=(t.rear+1)%t.size);
    printf("\n");
}
int main(){
    queue q;
    int opt,d;
    while(1){
        printf("\n1.Create\n2.Insert \n3.Delete \n4.Display\nOption :");scanf("%d",&opt);
        if(opt>4) break;
        switch(opt){
        case 1: init(&q);break;
        case 2: printf("\nEnter Value :");scanf("%d",&d);enqueue(&q,d);break;
        case 3: printf("\nDeleted Element :%d",dequeue(&q));break;
        case 4: display(q);break;

        }
    }
}

