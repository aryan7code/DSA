// Problem: Count Occurrences of an Element in Linked List
// Implement using linked list with dynamic memory allocation.
//
// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)
//
// Output:
// - Print the number of times the key appears in the linked list
//
// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20
//
// Output:
// 3
//
// Explanation:
// Traverse the linked list from head to end.
// Each time a node's data matches the given key,
// increment a counter. After traversal, print the final count.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i, value, key, count = 0;

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

    struct Node *temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
