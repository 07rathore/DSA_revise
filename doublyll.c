#include <stdio.h>
#include <stdlib.h>

/* ---------- Node structure ---------- */
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

/* ---------- Global head pointer ---------- */
struct Node* head = NULL;

/* ============================================
   CREATE a new node
   ============================================ */
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* ============================================
   INSERT at beginning
   ============================================ */
void insertFront(int val) {
    struct Node* newNode = createNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev    = newNode;
    head          = newNode;
}

/* ============================================
   INSERT at end
   ============================================ */
void insertEnd(int val) {
    struct Node* newNode = createNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next    = newNode;
    newNode->prev = temp;
}

/* ============================================
   DELETE a node by value
   ============================================ */
void deleteNode(int val) {
    struct Node* temp = head;

    /* search for the node */
    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", val);
        return;
    }

    /* fix previous node's next pointer */
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;   /* deleting head */

    /* fix next node's prev pointer */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted %d\n", val);
}

/* ============================================
   DISPLAY forward
   ============================================ */
void display() {
    struct Node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- Main ---------- */
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertFront(5);

    printf("List: ");
    display();

    deleteNode(20);
    printf("After deleting 20: ");
    display();

    deleteNode(5);
    printf("After deleting 5 (head): ");
    display();

    return 0;
}
