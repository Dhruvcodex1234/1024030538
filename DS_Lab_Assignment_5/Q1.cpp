#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// (a) Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// (b) Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// (c) Insert before/after a specific value
void insertBefore(int key, int value) {
    if (head == NULL) return;

    if (head->data == key) {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Key not found!\n");
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int key, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Key not found!\n");
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// (d) Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// (e) Delete from end
void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// (f) Delete specific node
void deleteNode(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        deleteFromBeginning();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Key not found!\n");
    } else {
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

// (g) Search for a node
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Not found!\n");
}

// (h) Display list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, key;

    while (1) {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert before key\n4.Insert after key\n5.Delete beginning\n6.Delete end\n7.Delete specific\n8.Search\n9.Display\n10.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &val); insertAtBeginning(val); break;
            case 2: scanf("%d", &val); insertAtEnd(val); break;
            case 3: scanf("%d %d", &key, &val); insertBefore(key, val); break;
            case 4: scanf("%d %d", &key, &val); insertAfter(key, val); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: scanf("%d", &key); deleteNode(key); break;
            case 8: scanf("%d", &key); search(key); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}

