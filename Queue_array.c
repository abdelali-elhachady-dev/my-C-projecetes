#include <stdio.h>
#include <stdlib.h>
#define size 5

void enqueue(int T[],int **front ,int** rear, int val){
        if( **front==-1 &&**rear== -1){
            T[++(**rear)] = val;
           (*front)++;
        }else if(**rear < size-1){
            T[++(**rear)]= val;
        }else{
            printf("plaaaaaan");
        }
}
void dequeue(int T[],int **front ,int** rear ){
        if(*front == -1 && *rear == -1){
            printf("the queue is empty");
        }
        if(*front == *rear ){
            *front=-1;
           * rear=-1;
        }else{
                printf("dequeued %d\n",T[**front]);
            (**front)++;
        }
}
void displayQueue(int T[], int *front, int *rear) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", T[i]);
        }
        printf("\n");
    }
}int main()
{
    int T[size],n = 0;
    int *front = -1;
    int *rear = -1;
   enqueue(T,&*front , &*rear , 1);
    enqueue(T,&*front , &*rear , 2);
     enqueue(T,&*front , &*rear , 3);
      enqueue(T,&*front , &*rear, 4);
   displayQueue(T,front,rear);
    dequeue(T, &*front ,&*rear);
       displayQueue(T,&front , &rear);


    return 0;
}
