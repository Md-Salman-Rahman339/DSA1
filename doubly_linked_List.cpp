#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void InsertAtFirst(Node *&head,int data){
    Node *newnode=new Node(data);
    newnode->next=head;
    newnode->prev=head;
    head=newnode;
    

}
void InsertAtLast(Node *&head,int data){
    Node *newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        return;

    }
    Node *curr=head;
    while(curr->next !=NULL){
        curr=curr->next;

    }
    curr->next=newnode;
    newnode->prev=curr->next;
}
 void InsertAtAny(Node *&head, int data,int pos){
    if(pos<0){
        return;
    }
    Node *newnode=new Node(data);

    Node *curr=head;
    int cpos=0;
    while(curr->next!=NULL && cpos<pos-1){
        curr=curr->next;
        cpos++;
    }
    newnode->next=curr->next;

    curr->next=newnode;
    newnode->prev=curr->next;

 }
 void deleteFirst(Node *&head){
    if(head==NULL){
        return;
    }
    Node *curr=head;
    head=curr->next;
    curr->prev=head;
    delete curr;


 }
 void deleteLast(Node *&head){
    if(head==NULL){
        return;
    }
    else if(head->next==NULL){
        delete head;
        head=nullptr;
        return;
    }
    Node *curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->prev->next=nullptr;
 }
 void deleteAtAny(Node *&head,int pos){
    if(head==NULL){
        return;
    }
    Node *curr=head;
    for(int i=0;i<pos-1;i++){
        curr=curr->next;
    }
    Node *delenode=curr->next;
    curr->next=curr->next->next;
    delete delenode;
 }
void printll(Node *&head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

int main(){
 Node *head=new Node(10);
 Node *one=new Node(20);
 Node *two=new Node(30);
head->next=one;
one->next=two;
two->next=NULL;
int data=5;

// printll(head);
// InsertAtFirst(head,data);
// printll(head);
// InsertAtLast(head,40);
// printll(head);
// InsertAtAny(head,15,2);
// printll(head);
// deleteFirst(head);
// printll(head);
// deleteLast(head);
// printll(head);
deleteAtAny(head,1);
printll(head);

}