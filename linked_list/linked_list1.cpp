#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};


void Insert(Node** head,int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void Insert_nth(Node **head, int data, int pos) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(pos == 1) {
        temp1->next = *head;
        *head = temp1;
        return;
    }
    Node* temp2 = *head;
    for(int i=0; i<pos-2 && temp2->next; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Delete_nth(Node **head, int pos) {
    if(*head == NULL){
        cout<<"List is empty.\n";
        return;
    }
    Node* temp1 = *head;
    if(pos==1){
        *head = temp1->next;
        free(temp1);
        return;
    }
    for(int i=0; i<pos-2 && temp1->next->next; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void Print(Node* head) {
    cout<<"List is : ";
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    Node* head = NULL;
    /*cout<<"How many numbers?\n";
    int n,i,x;
    cin>>n;
    for(i=0; i<n; i++) {
        cout<<"Enter number\n";
        cin>>x;
        Insert(&head,x);
        Print(head);
    }*/
    Insert_nth(&head, 2, 1);
    Print(head);
    Insert_nth(&head, 3, 2);
    Print(head);
    Insert_nth(&head, 4, 1);
    Print(head);
    Insert_nth(&head, 5, 8);
    Print(head);
    Delete_nth(&head, 2);
    Print(head);
    Delete_nth(&head, 5);
    Print(head);
    Delete_nth(&head, 5);
    Print(head);
    Delete_nth(&head, 5);
    Print(head);
}
