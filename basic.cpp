#include <iostream>

using namespace std;

// Define the node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    // Create a new node and assign data to it
    Node* newNode = new Node;
    newNode->data = data;

    // Set the next pointer of the new node to the current head
    newNode->next = *head;

    // Update the head pointer to point to the new node
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    // Create a new node and assign data to it
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty, set the head pointer to the new node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the end of the linked list
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Set the next pointer of the last node to the new node
    current->next = newNode;
}

// Function to insert a new node with the given data value at the given index in the linked list
void insertAtIndex(Node** head, int data, int index) {
    // Create a new node and assign data to it
    Node* newNode = new Node;
    newNode->data = data;

    // If the index is 0, insert the node at the beginning of the linked list
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the linked list to the node before the desired index
    Node* current = *head;
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }

    // If the index is greater than the length of the linked list, return
    if (current == NULL) {
        return;
    }

    // Insert the new node between the previous and current nodes
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node of the linked list
void deleteFirstNode(Node** head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // Save the current head node and update the head pointer to the next node
    Node* temp = *head;
    *head = (*head)->next;

    // Delete the first node
    delete temp;
}

// Function to delete the last node of the linked list
void deleteLastNode(Node** head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If there is only one node in the linked list, delete it and set the head pointer to NULL
    if ((*head)->next == NULL) {
        delete *head;
        *head = NULL;
        return;
    }

    // Traverse the linked list to the second-to-last node
    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Delete the last node and update the next pointer of the second-to-last node
    delete current->next;
    current->next = NULL;
}

// Function to delete a node with the given value from the linked list
void deleteNode(Node** head, int value) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the first node contains the value, update the head pointer
    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    // Traverse the linked list to find the node to delete
    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // If the node is not found, return
    if (current->next == NULL) {
        return;
    }

    // Delete the node and update the next pointer of the previous node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Driver code to test the linked list functions
int main() {
    Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);


    printList(head);

    insertAtBeginning(&head, 0);

    printList(head);

    insertAtIndex(&head, 55, 3);

    printList(head);

    deleteFirstNode(&head);

    printList(head);

    deleteLastNode(&head);
    
    printList(head);

    deleteNode(&head, 2);

    printList(head);

    return 0;
}
