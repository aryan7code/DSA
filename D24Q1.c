// Problem: Delete First Occurrence of a Key
// Implement using linked list with dynamic memory allocation.
//
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key
//
// Output:
// - Print the linked list elements after deletion, space-separated
//
// Example:
// Input:
// 5
// 10 20 30 40 50
// 30
//
// Output:
// 10 20 40 50
//
// Explanation:
// Traverse list, find first node with key,
// remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i, value, key;

    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL, *newnode;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    scanf("%d", &key);

    struct Node *temp = head, *prev = NULL;

    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
