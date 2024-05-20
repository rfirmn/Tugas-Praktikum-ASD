#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *back;
    int data;
    struct node *next;
} node;

node* create_node(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->back = NULL;
    new_node->next = NULL;
    return new_node;
}

void cetak_depan(node *head) {
    if (head == NULL) {
        printf("[data kosong]\n");
        return;
    }
    node *x = head;
    do {
        printf("addres: %p, Data: %i \n",(void*)&x->data, x->data);
        x = x->next;
    } while (x != head);
    printf("\n");
}

void insert_last(node** head, node** tail, int value) {
    node* temp = create_node(value);
    if (*head == NULL) {
        *head = *tail = temp;
        temp->next = temp;
        temp->back = temp;
    } else {
        temp->next = *head;
        temp->back = (*tail);
        (*tail)->next = temp;
        (*head)->back = temp;
        *tail = temp;
    }
}

void head_kecil(node** head) {
    if (*head == NULL) return;

    node* temp = (*head)->next;
    node* x = *head;

    while(temp != *head){
        if(x->data > temp->data){
            x = temp;
        }
        temp = temp->next;
    }
    *head = x;
}

void urut(node** head) {
    if (*head == NULL || (*head)->next == *head) return;

    bool swapped;
    node* temp;
    node* x = NULL;

    do {
        swapped = false;
        temp = *head;

        while (temp->next != *head && temp->next != NULL) {
            if (temp->data > temp->next->data) {
                node* tempNext = temp->next;
                temp->next = tempNext->next;
                tempNext->next->back = temp;
                tempNext->next = temp;
                tempNext->back = temp->back;
                temp->back->next = tempNext;
                temp->back = tempNext;
                if (temp == *head) {
                    *head = tempNext;
                }
                swapped = true;
            }
            temp = temp->next;
        }
        x = temp;
    } while (swapped);

    head_kecil(head);
}

int main() {
    node *head, *tail;
    head = tail = NULL;

    int x;
    scanf("%i", &x);
    int y[x];
    for (int i = 0; i < x; i++) {
        scanf("%i", &y[i]);
    }

    for (int i = 0; i < x; i++) {
        insert_last(&head, &tail, y[i]);
    }

    cetak_depan(head);
    urut(&head);
    printf("\n");
    cetak_depan(head);

    return 0;
}