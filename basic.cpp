#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    newNode->next = *head;

    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void insertAtIndex(Node** head, int data, int index) {
    Node* newNode = new Node;
    newNode->data = data;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirstNode(Node** head) {
    if (*head == NULL) {
        return;
    }

    *head = (*head)->next;

    delete temp;
}

void deleteLastNode(Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        delete *head;
        *head = NULL;
        return;
    }

    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    delete current->next;
    current->next = NULL;
}

void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

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
