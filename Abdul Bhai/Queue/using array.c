#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int size,front,rear;
    int *arr;
}queue;
void init(queue *t){
    printf("\nEnter Size of array :");scanf("%d",&t->size);
    t->front=t->rear=-1;
    t->arr=(int*)malloc(sizeof(int)*t->size);
}
void enqueue(queue *t,int d){
    if(t->rear==t->size-1) printf("\nQueue is FULL.");
    else {
        t->rear++;
        t->arr[t->rear]=d;
    }
}
void dequeue(queue *t){
    if(t->rear==t->front) printf("\nEmpty Queue");
    else t->front++;
}
void display(queue t){
    printf("\nDATA :");
    for(int i=t.front+1;i<=t.rear;i++)
        printf("%d ",t.arr[i]);
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
        case 3: dequeue(&q);break;
        case 4: display(q);break;

        }
    }
}
