// Queue using array

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data){
    if (rear==MAX-1){
        printf("Queue is full\n");
        return;
    }
    else{
        rear++;
        queue[rear]=data;
    }
}

void dequeue(){
    if (front>rear){
        printf("Queue is empty\n");
    }
    else{
        int item=queue[front];
        front++;
        printf("Dequeued item: %d\n", item);
    }

}
void display(){
    if (front>rear){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements: ");
        for (int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;

}