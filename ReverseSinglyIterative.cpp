#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val):data(val),next(NULL){}
};

Node *ReverseL(Node *head){
    Node *prev=NULL;
    Node *curr=head;
    Node *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
       
        prev=curr;
        curr=next;
    }
    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = ReverseL(head);

    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl; // Output: 3 -> 2 -> 1 -> NULL
    return 0;
}