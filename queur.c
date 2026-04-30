// code to implement the queue data structure 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;  
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;

    if(rear==NULL){
        front=rear=new;
        return;
    }
    rear->next=new;
    rear=new;
}

void dequeue(int data){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp=front;
    front=front->next;
    free(temp);
}

void display(){
    struct node* temp=front;
    if (front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    enqueue(23);
    enqueue(34);
    display();
    dequeue(23);
    display();
    return 0;
}