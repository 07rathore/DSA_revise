// Circular Queue using linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // Point rear to front to make it circular
    } else {
        rear->next = newNode; // Link the new node after rear
        rear = newNode; // Update rear to the new node
        rear->next = front; // Point rear to front to maintain circular structure
    }
}

void dequeue(){
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    if (front == rear) { // Only one element in the queue
        printf("Dequeued item: %d\n", front->data);
        free(front);
        front = rear = NULL; // Reset the queue
    } else {
        struct Node* temp = front;
        printf("Dequeued item: %d\n", temp->data);
        front = front->next; // Move front to the next node
        rear->next = front; // Update rear's next to the new front
        free(temp); // Free the old front node
    }
}

void display(){
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front); // Loop until we come back to the front
    printf("\n");
}







// Circular queue using array

// #include <stdio.h>
// #define MAX 100
// int queue[MAX];
// int front=-1;
// int rear=-1;


// void enqueue(int data){
//     if ((rear + 1) % MAX == front) {
//         printf("Queue is full\n");
//         return;
//     }
//     rear = (rear + 1) % MAX; // Move rear to the next position
//     queue[rear] = data; // Add the new element to the rear
//     if (front == -1) { // If the queue was empty, set front to the first element
//         front = rear;
//     }
// }


// void dequeue(){
//     if (front == -1) {
//         printf("Queue is empty\n");
//         return;
//     }
//     int item = queue[front];
//     if (front == rear) { // Only one element in the queue
//         front = rear = -1; // Reset the queue
//     } 
//     else {
//         front = (front + 1) % MAX; // Move front to the next position
//     }
//     printf("Dequeued item: %d\n", item);
// }

// void display(){
//     if (front == -1) {
//         printf("Queue is empty\n");
//         return;
//     }
//     printf("Queue elements: ");
//     for(int i = front; i <= rear; i = (i + 1) % MAX) {
//         printf("%d ", queue[i]);
//     }
//     printf("\n");
// }



