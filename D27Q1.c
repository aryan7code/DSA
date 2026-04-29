#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* advance(struct Node* head, int diff) {
    while (diff--) {
        head = head->next;
    }
    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    if (len1 > len2) {
        p1 = advance(p1, len1 - len2);
    } else {
        p2 = advance(p2, len2 - len1);
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}
