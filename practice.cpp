#include <bits/stdc++.h>
using namespace std;

// Define the size of the queue
#define SIZE 5

int a[SIZE];
int front = -1;
int rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if (rear == SIZE - 1) { // Check if the queue is full
        cout << "Queue overflow! Cannot insert " << value << endl;
        return;
    }
    if (front == -1) { // Initialize front on the first enqueue
        front = 0;
    }
    rear++;
    a[rear] = value;
    cout << "Enqueued element: " << value << endl;
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) { // Check if the queue is empty
        cout << "Queue underflow! Cannot dequeue." << endl;
        return;
    }
    cout << "Dequeued element: " << a[front] << endl;
    front++;
    // Reset front and rear if the queue becomes empty
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Function to display the queue elements
void display() {
    if (front == -1) { // Check if the queue is empty
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test the queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // Attempt to enqueue when the queue is full
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    display();
    return 0;
}
