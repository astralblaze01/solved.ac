#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int val;
    struct _node *next;
} node;

void push(node **head, int key);
void back(node **head);
void front(node **head);
void empty(node **head);
int size(node **head);
void pop(node **head);

int main() {
    node *head = (node *)malloc(sizeof(node));
    if (!head) {
        printf("Memory allocation failed\n");
        return 1;
    }
    head->next = NULL;

    char com[10];
    int comSize, num = 0;
    scanf("%d", &comSize);

    for (int i = 0; i < comSize; i++) {
        scanf("%s", com);

        if (strcmp(com, "push") == 0) {
            scanf("%d", &num);
            push(&head, num);
        } else if (strcmp(com, "pop") == 0) {
            pop(&head);
        } else if (strcmp(com, "size") == 0) {
            printf("%d\n", size(&head));
        } else if (strcmp(com, "empty") == 0) {
            empty(&head);
        } else if (strcmp(com, "front") == 0) {
            front(&head);
        } else if (strcmp(com, "back") == 0) {
            back(&head);
        }
    }

    // 메모리 해제
    node *current = head;
    while (current) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

void push(node **head, int key) {
    node *newN = (node *)malloc(sizeof(node));
    if (!newN) {
        printf("Memory allocation failed\n");
        return;
    }
    newN->val = key;
    newN->next = NULL;

    node *tailN = *head;
    while (tailN->next) {
        tailN = tailN->next;
    }
    tailN->next = newN;
}

void front(node **head) {
    if ((*head)->next == NULL) {
        printf("-1\n");
        return;
    }
    printf("%d\n", (*head)->next->val);
}

void back(node **head) {
    if ((*head)->next == NULL) {
        printf("-1\n");
        return;
    }

    node *ptrf = *head;
    while (ptrf->next) {
        ptrf = ptrf->next;
    }
    printf("%d\n", ptrf->val);
}

int size(node **head) {
    int count = 0;
    node *ptrs = (*head)->next;
    while (ptrs) {
        count++;
        ptrs = ptrs->next;
    }
    return count;
}

void empty(node **head) {
    printf("%d\n", ((*head)->next == NULL) ? 1 : 0);
}

void pop(node **head) {
    if ((*head)->next == NULL) {
        printf("-1\n");
        return;
    }

    node *temp = (*head)->next;
    printf("%d\n", temp->val);
    (*head)->next = temp->next;
    free(temp);
}
