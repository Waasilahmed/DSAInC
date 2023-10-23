#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

int lengthOfList = 0;

void customInsert(Node** head, int value) {
    // Check if the value is already in the list
    Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            return;  
        }
        current = current->next;
    }

    Node* new = (Node*)malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;

    // If the list is empty or the new value should be at the beginning
    if (*head == NULL || value < (*head)->data) {
        new->next = *head;
        *head = new;
        lengthOfList++;
        return;
    }

    current = *head;
    Node* previous = NULL;

    while (current != NULL && current->data < value) {
        previous = current;
        current = current->next;
    }

    // Insert the new value between previous and current
    new->next = current;
    previous->next = new;
    lengthOfList++;
}






void delete(Node** head, int value) {
    if (*head == NULL || value == (*head)->data) {
        if (*head != NULL) {
            Node* temp = *head;
            *head = (*head)->next;
            free(temp);
            lengthOfList--;
        }
        return;
    }

    if (value > (*head)->data) {
        delete(&(*head)->next, value);
    }
}



void printList(Node* head) {
    printf("%d :", lengthOfList);
    Node* temp = head;
    if (lengthOfList > 0) {
        do {
            printf(" %d", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
    printf("\n");
}



void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}


int main(int argc, char** argv) {
    Node* root = NULL;
    char lett;
    int dig;

    for (;;) {
        if (scanf(" %c %d", &lett, &dig) == EOF) {
            break; 
        }

        switch (lett) {
            case 'i':
                customInsert(&root, dig);
                break;
            case 'd':
                delete(&root, dig);
                break;
            default:
                break;
        }
        printList(root);
    }

    freeList(root);
    return EXIT_SUCCESS;
}




