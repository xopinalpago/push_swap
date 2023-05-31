/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_chaine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:56:44 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/24 14:56:46 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur lors de l'allocation de mémoire.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sa(Node** head) {
    if (*head != NULL && (*head)->next != NULL) {
        Node* temp = (*head)->next;
        (*head)->next = temp->next;
        temp->next = *head;
        *head = temp;
    }
}

void pa(Node** src, Node** dst) {
    if (*src != NULL) {
        Node* temp = *src;
        *src = (*src)->next;
        temp->next = *dst;
        *dst = temp;
    }
}

void ra(Node** head) {
    if (*head != NULL && (*head)->next != NULL) {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *head;
        *head = (*head)->next;
        current->next->next = NULL;
    }
}

void quickSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    int pivot = (*head)->data;
    Node* less = NULL;
    Node* greater = NULL;
    Node* current = (*head)->next;

    while (current != NULL) {
        Node* nextNode = current->next;
        if (current->data < pivot) {
            current->next = less;
            less = current;
        } else {
            current->next = greater;
            greater = current;
        }
        current = nextNode;
    }

    quickSort(&less);
    quickSort(&greater);

    if (less != NULL) {
        Node* tail = less;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = *head;
        *head = less;
    }

    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = greater;
}

int main() {
    Node* head = NULL;
    push(&head, 64);
    push(&head, 25);
    push(&head, 12);
    push(&head, 22);
    push(&head, 11);

    printf("Liste avant le tri rapide :\n");
    printList(head);

    quickSort(&head);

    printf("Liste après le tri rapide :\n");
    printList(head);

    return 0;
}
