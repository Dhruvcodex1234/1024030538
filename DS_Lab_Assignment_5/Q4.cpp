#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    return n;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* n = createNode(value);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node* t = *head;
    while (t->next)
        t = t->next;

    t->next = n;
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    printf("Original List: ");
    display(head);

    head = reverseList(head);

    printf("Reversed List: ");
    display(head);

    return 0;
}


