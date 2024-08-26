#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;              // Data part of the node
    struct node *next;     // Pointer to the next node in the list
} node;

// Function prototypes
node *createLinkedList(int n);
void displayList(node *head);

int main() {
    int n = 0;
    node *HEAD = NULL;

    // Ask the user for the number of nodes in the linked list
    printf("\nHow many nodes: ");
    scanf("%d", &n);

    // Create the linked list with the specified number of nodes
    HEAD = createLinkedList(n);

    // Display the linked list
    displayList(HEAD);

    return 0;
}

// Function to create a linked list with `n` nodes
node *createLinkedList(int n) {
    int i = 0;
    node *head = NULL;  // Pointer to the first node in the list
    node *temp = NULL;  // Temporary pointer for new nodes
    node *p = NULL;     // Pointer used to traverse the list

    // Loop to create `n` nodes
    for (i = 0; i < n; i++) {
        // Allocate memory for a new node
        temp = (node *)malloc(sizeof(node));
        
        // Get data from the user for the new node
        printf("\nEnter the data for node number %d: ", i + 1);
        scanf("%d", &(temp->data));

        // Initialize the `next` pointer of the new node to NULL
        temp->next = NULL;

        // If this is the first node, set it as the head of the list
        if (head == NULL) {
            head = temp;
        } else {
            // Traverse to the end of the list and link the new node
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }

    // Return the head pointer of the newly created linked list
    return head;
}

// Function to display the linked list
void displayList(node *head) {
    node *p = head;  // Pointer to traverse the list

    // Loop through the list and print each node's data
    while (p != NULL) {
        printf("\t%d->", p->data);
        p = p->next;  // Move to the next node
    }
}
