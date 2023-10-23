#include <stdio.h>
#include <stdlib.h>


int compare(int a, int b);


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node TreeNode;

TreeNode* createNode(int key) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (node != NULL && key != 0) { 
        node->data = key;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        printf("inserted\n");
        return createNode(key);
    }

    switch (compare(key, root->data)) {
        case -1: 
            if (root->left == NULL) {
                root->left = createNode(key);
                printf("inserted\n");
            } else {
                insert(root->left, key);
            }
            break;

        case 1: 
            if (root->right == NULL) {
                root->right = createNode(key);
                printf("inserted\n");
            } else {
                insert(root->right, key);
            }
            break;

        default: 
            printf("not inserted\n");
            break;
    }

    return root;
}

int compare(int a, int b) {
    if (a < b) return -1;
    else if (a > b) return 1;
    else return 0;
}




TreeNode* search(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key == root->data) {
        return root;
    }

    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}




int searchData(TreeNode* root, int key) {
    if (root == NULL) {
        return -1; 
    }

    if (key == root->data) {
        return root->data;
    }

    if (key < root->data) {
        return searchData(root->left, key);
    } else {
        return searchData(root->right, key);
    }
}





void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
 
    printf("(");
    printTree(root->left);
    printf("%d", root->data);

    switch (1) {
        case 1:
            printTree(root->right);
            break;
    }

    printf(")");
}




TreeNode* findMin(TreeNode* node) {
    TreeNode* current;
    for (current = node; current != NULL && current->left != NULL; current = current->left) {

    }
    return current;
}



TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        printf("absent\n");
        return root;
    }

    if (key > root->data) {

        root->right = deleteNode(root->right, key);

    } else if (key < root->data) {

        root->left = deleteNode(root->left, key);
    } else {
        printf("deleted\n");

       TreeNode* temp;
    if (root->right == NULL) {
        temp = root->left;
    } else if (root->left == NULL) {
        temp = root->right;
    } else {
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }


        free(root);
        return temp;
    }

    return root;
}


void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}




int main(int argc, char** argv) {
    int val;
    char cmd;
    TreeNode* root = NULL;

    for (int scanfResult; (scanfResult = scanf(" %c", &cmd)) != EOF; ) {
        if (scanfResult < 0) {
            break;
        }
        switch (cmd) {
            case 's':
                scanf("%d", &val);
                int result = searchData(root, val);
                if (result == -1) {
                    printf("absent\n");
                } else {
                    printf("present\n");
                }
                break;
            case 'i':
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 'd':
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 'p':
                printTree(root);
                printf("\n");
                break;
            default:
                break;
        }
    }

    freeTree(root);
    return 0;
}
