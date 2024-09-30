#include<stdio.h>
#include<stdlib.h>

// Define the structure for the linked list node
struct node {
    int data;
    struct node *next;
};

// Add a node at the beginning of the linked list
struct node* add_begin(struct node* head, int d) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head = ptr;
    return head;
}

// Add a node at the end of the linked list
struct node* add_end(struct node* head, int d) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }   
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;

    return head; 
}

// Add a node at a specific position in the linked list
struct node* add_inbtw(struct node* head, int d, int pos) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        ptr->next = temp->next;  
        temp->next = ptr;        
    }
    return head;
}

// Delete the first node in the linked list
struct node* delete_begin(struct node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);  // Free the memory of the deleted node
    return head;
}

// Delete the last node in the linked list
struct node* delete_end(struct node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    struct node *temp = head;

    // If there's only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Traverse to the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete a node at a specific position in the linked list
struct node* delete_inbtw(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (pos == 1) {
        return delete_begin(head);
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    head = add_begin(head, 3);
    head = add_end(head, 20);
    head = add_inbtw(head, 19, 2);

    printf("Initial list: ");
    print_list(head);

    // Deleting the first node
    head = delete_begin(head);
    printf("After deleting the first node: ");
    print_list(head);

    // Deleting the last node
    head = delete_end(head);
    printf("After deleting the last node: ");
    print_list(head);

    // Deleting the second node (position 2)
    head = delete_inbtw(head, 2);
    printf("After deleting the second node: ");
    print_list(head);

    return 0;
}
