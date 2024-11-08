#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    // Set the next of the new node to the current head
    newNode->next = head;

    // Update the head to the new node
    head = newNode;

    // Return the updated head
    return head;
}

// Function to insert a node at the end of a linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Insert the new node at the end
        current->next = newNode;
    }

    // Return the head of the updated list
    return head;
}

// Function to insert a node at a specific position in a linked list
struct Node* insertAtPosition(struct Node* head, int newData, int position) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // Special case: Insert at the beginning
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    // General case: Traverse to the specified position
    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Insert the new node at the specified position
    if (current == NULL) {
        // Position is beyond the end of the list, do nothing or handle accordingly.
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    // Return the head of the updated list
    return head;
}

// Function to delete a node with a specific value in a linked list
struct Node* deleteNodeByValue(struct Node* head, int valueToDelete) {
    // Special case: If the list is empty, do nothing
    if (head == NULL) {
        return NULL;
    }

    // Special case: If the node to be deleted is the head
    if (head->data == valueToDelete) {
        struct Node* newHead = head->next;
        free(head);
        return newHead;
    }

    // General case: Traverse the list to find the node to be deleted
    struct Node* current = head;
    while (current->next != NULL && current->next->data != valueToDelete) {
        current = current->next;
    }

    // If the value is not found, do nothing
    if (current->next == NULL) {
        return head;
    }

    // Delete the node with the specified value
    struct Node* nodeToDelete = current->next;
    current->next = current->next->next;
    free(nodeToDelete);

    // Return the head of the updated list
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Print the linked list
    printf("Linked List after Insertion at the Beginning: ");
    printList(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Print the linked list
    printf("Linked List after Insertion at the End: ");
    printList(head);

    // Insert nodes at specific positions
    head = insertAtPosition(head, 10, 3);
    head = insertAtPosition(head, 7, 5);

    // Print the linked list
    printf("Linked List after Insertion at Specific Positions: ");
    printList(head);

    // Delete a node with a specific value
    int valueToDelete = 4;
    head = deleteNodeByValue(head, valueToDelete);

    // Print the linked list after deletion
    printf("Linked List after Deletion of %d: ", valueToDelete);
    printList(head);

    return 0;
}
