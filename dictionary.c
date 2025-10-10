#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};


struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, char word[], char meaning[]) {
    if (root == NULL)
        return createNode(word, meaning);
    
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word already exists \n");

    return root;
}


void search(struct Node* root, char word[]) {
    if (root == NULL) {
        printf("Word not found!\n");
        return;
    }

    if (strcmp(word, root->word) == 0)
        printf("Meaning of '%s' is %s\n", word, root->meaning);
    else if (strcmp(word, root->word) < 0)
        search(root->left, word);
    else
        search(root->right, word);
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s means %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    
    do {
        printf("\nMenu\n");
        printf("1. Insert Word\n2. Search Word\n3. Display \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter Word: ");
                fgets(word,sizeof(word),stdin);
                printf("Enter Meaning: ");
                fgets(meaning,sizeof(meaning),stdin);
                root = insert(root, word, meaning);
                break;
            case 2:
                printf("Enter Word to Search: ");
                fgets(word,sizeof(word),stdin);
                search(root, word);
                break;
            case 3:
                printf("\nDictionary Words\n");
                inorder(root);
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    
    return 0;
}
