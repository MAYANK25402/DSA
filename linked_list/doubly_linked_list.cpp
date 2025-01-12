#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* head;

struct Node* GetNewNode(int x) {
    struct Node* newNode = new Node;

    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void InsertAtHead(int x) {
    struct Node *newNode = GetNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print() {
    struct Node *temp = head;
    cout<<"Forward: ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void ReversePrint() {
    struct Node *temp = head;
    if(temp == NULL)
        return;
    while(temp->next != NULL)
        temp = temp->next;

    cout<<"Reverse: ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main() {
    head = NULL;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    InsertAtHead(8); Print(); ReversePrint();
}
