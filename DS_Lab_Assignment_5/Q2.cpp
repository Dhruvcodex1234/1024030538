#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insert(int x) {
    struct Node* n = createNode(x);
    n->next = head;
    head = n;
}

int deleteAll(int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        count++;
    }

    struct Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->data == key) {
            struct Node* temp = cur->next;
            cur->next = temp->next;
            free(temp);
            count++;
        } else {
            cur = cur->next;
        }
    }
    return count;
}

void display() {
    struct Node* t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    insert(1); insert(3); insert(1); insert(2); insert(1); insert(2); insert(1);

    int key = 1;
    int count = deleteAll(key);

    printf("Count: %d\nUpdated Linked List: ", count);
    display();

    return 0;
}

