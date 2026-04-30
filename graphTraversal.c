#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data  = val;
    node->left  = node->right = NULL;
    return node;
}

/* Left -> Root -> Right */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Root -> Left -> Right */
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* Left -> Right -> Root */
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    /*
         1
        / \
       2   3
      / \
     4   5
    */
    struct Node* root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);

    printf("Inorder   (L->Root->R): "); inorder(root);   printf("\n");
    printf("Preorder  (Root->L->R): "); preorder(root);  printf("\n");
    printf("Postorder (L->R->Root): "); postorder(root); printf("\n");

    return 0;
}