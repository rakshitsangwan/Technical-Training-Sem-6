#include <stdio.h>
#include <stdlib.h>

// Forward declaration of Node structure
struct Node;

// Function to perform preorder traversal
void preorderTraversal(struct Node* root);

// Define the structure for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    printf("Preorder traversal: ");
    
    // Constructing the sample binary tree
    struct Node* root = createNode(1);
    root->right = createNode(2);
    root->right->right = createNode(5);
    root->right->right->left = createNode(3);
    root->right->right->left->right = createNode(4);
    root->right->right->right = createNode(6);
    
    // Print preorder traversal
    preorderTraversal(root);
    
    return 0;
}
