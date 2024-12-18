#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Insert at the beginning
void insert_at_first(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}
// parameters:value it will insert at first

// new node is dynamically allocated and data set to value
//if the list is empty (head==nullptr) the newnode prev,next pointers points itself
// else newnode next is to head and prev is set to tail.tail node next is updated to new node and head node prev point  updated to new node.head is updated to newnode

// Insert at the end
void insert_at_last(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}
// parameters:value it will insert at last
// new node is dynamically allocated and data set to value
//if the list is empty (head==Null) the newnode prev,next pointers points itself
// else newnode next is to head and prev is set to tail.tail node next is updated to new nodeand head node prev point updated to new node.head is updated to newnode

// Insert before a specific value
void insert_before_a_value(int beforeValue, int value) {
    if (!head) return;

    Node* current = head;
    bool found = false;

    while (current != head || !found) {
        if (current->data == beforeValue) {
            found = true;
            Node* newNode = new Node();
            newNode->data = value;
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;

            if (current == head) head = newNode;
            return;
        }
        current = current->next;
    }
}
// parameters: beforeValue:the value before which  the new node should be inserted;value:the value to be inserted into the list
// Algorithm:
// if the list is empty it will be return.
//if current data is equal to before value found is set  true. new node is dynamically allocated and data set to value.if before value is found at the head ,head is updated to new node

// Insert after a specific value
void insert_after_a_value(int afterValue, int value) {
    if (!head) return;

    Node* current = head;
    bool found = false;

    while (current != head || !found) {
        if (current->data == afterValue) {
            found = true;
            Node* newNode = new Node();
            newNode->data = value;

            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}
// Parameters:afterValue: The value after which the new node should be inserted;value: The value to be inserted into the list.
// Algorithm:
// If the list is empty, the function will be return
// A loop starts from the head and iterates over the list to find the node that contains afterValue. The loop continues until the starting point head is encountered again, as the list is circular.
// Once the afterValue is found, a new node is created with the value.
// The new node is inserted between the node containing afterValue and the next node:
// The new node’s next pointer is set to point to the node after afterValue, and its prev pointer is set to the afterValue.
// The node containing afterValue updates its next pointer to point to the new node, and the node after afterValue updates its prev pointer to point to the new node.




// Insert at a specific index
void insert_at_index(int index, int value) {
    if (index == 0) {
        insert_at_first(value);
        return;
    }

    Node* current = head;
    int count = 0;
    while (current->next != head && count < index - 1) {
        current = current->next;
        count++;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Parameters:

// index: The position in the list where the new node should be inserted ,starting from 0.
// value: The value to be inserted into the list.
// Algorithm:

// If the index is 0, call insert_at_first to add the node at the start.
// If the index is greater than 0, start from the head and loop through the list to find the node just before the  index.
// Once the position is found:
// Create a new node with the value.
// Insert the new node between the current node and the next node:
// The new node’s next points to the next node, and its prev points to the current node.
// Update the current node’s next to point to the new node, and the next node’s prev to point to the new node.

// Print the linked list
void print_LL() {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    bool firstIteration = true;

    while (current != head || firstIteration) {
        firstIteration = false;
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// there is no parameters
// if the list is empty it will print "list is empty" else the loop starts from the head and iterates the list and printing data of each 

int main() {
    insert_at_first(10);
    insert_at_first(5);
    insert_at_last(20);
    insert_after_a_value(10, 15);
    insert_before_a_value(20, 17);
    insert_at_index(2, 12);

    print_LL(); 

    return 0;
}
