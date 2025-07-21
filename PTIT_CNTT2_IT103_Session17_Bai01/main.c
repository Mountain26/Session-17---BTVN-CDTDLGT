#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode() {
    int value;
    printf("Nhap gia tri so nguyen: ");
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void printNode(Node* node) {
    if (node != NULL) {
        printf("data: %d,\n", node->data);
        if (node->left == NULL) {
            printf("left->NULL,\n");
        } else {
            printf("left->NOT NULL,\n");
        }
        if (node->right == NULL) {
            printf("right->NULL\n");
        } else {
            printf("right->NOT NULL\n");
        }
    }
}
int main() {
    Node* node = createNode();
    printNode(node);
    free(node);
    return 0;
}