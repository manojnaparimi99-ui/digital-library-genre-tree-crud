#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char genre[50];
    struct Node *left;   
    struct Node *right;  
} Node;


Node* createNode(char *genre) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->genre, genre);
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, char *genre) {
    if (root == NULL) return createNode(genre);

    if (strcmp(genre, root->genre) < 0)
        root->left = insert(root->left, genre);
    else if (strcmp(genre, root->genre) > 0)
        root->right = insert(root->right, genre);

    return root;
}


Node* search(Node* root, char *genre) {
    if (root == NULL || strcmp(root->genre, genre) == 0)
        return root;

    if (strcmp(genre, root->genre) < 0)
        return search(root->left, genre);
    else
        return search(root->right, genre);
}


void update(Node* root, char *oldGenre, char *newGenre) {
    Node* target = search(root, oldGenre);
    if (target != NULL) {
        strcpy(target->genre, newGenre);
        printf("Genre updated successfully!\n");
    } else {
        printf("Genre not found!\n");
    }
}


Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, char *genre) {
    if (root == NULL) return root;

    if (strcmp(genre, root->genre) < 0)
        root->left = deleteNode(root->left, genre);
    else if (strcmp(genre, root->genre) > 0)
        root->right = deleteNode(root->right, genre);
    else {
        
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        strcpy(root->genre, temp->genre);
        root->right = deleteNode(root->right, temp->genre);
    }
    return root;
}


void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%s\n", root->genre);
        display(root->right);
    }
}


int main() {
    Node* root = NULL;
    int choice;
    char genre[50], newGenre[50];

    while (1) {
        printf("\n--- Digital Library Menu ---\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Update Node\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter genre to add: ");
                scanf("%s", genre);
                root = insert(root, genre);
                break;
            case 2:
                printf("Enter genre to delete: ");
                scanf("%s", genre);
                root = deleteNode(root, genre);
                break;
            case 3:
                printf("Enter old genre: ");
                scanf("%s", genre);
                printf("Enter new genre: ");
                scanf("%s", newGenre);
                update(root, genre, newGenre);
                break;
            case 4:
                printf("Enter genre to search: ");
                scanf("%s", genre);
                if (search(root, genre))
                    printf("Genre found!\n");
                else
                    printf("Genre not found!\n");
                break;
            case 5:
                printf("\nLibrary Genres:\n");
                display(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}