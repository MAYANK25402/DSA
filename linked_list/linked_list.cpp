#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *next;
};


// Create Node
Node *createNode(){
    Node *temp = new Node();
    temp->next = NULL;
    return temp;
}

// Insert Node at First
void InsertAtFirst(Node* &head, int data){
    Node *t = createNode();
    if(head == NULL)
        head = t;
    else{
        t->next = head;
        head = t;
    }
    t->data = data;
}

// Insert Node At Last
void InsertAtLast(Node* &head, int data){
    Node *t = createNode();
    if(head==NULL)
        head = t;
    else{
        Node *tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = t;
    }
    t->data = data;
}

// Insert Node at nth Position
void InsertAtnth(Node* &head, int pos, int data){
    if(pos==0){
        Node *n = createNode();
        n->data = data;
        n->next = head;
        head=n;
    }
    else{
        Node *t = head;
        pos--;
        while(pos && t->next!=NULL){
            t = t->next;
            pos--;
        }
        if(!pos){
            Node *n = createNode();
            n->data = data;
            n->next = t->next;
            t->next = n;
        }
        else{
            cout<<"InsertAtnth() Enter valid position.\n";
        }
    }
}


// Delete First Node
void DeleteFirst(Node* &head){
    if(head==NULL)
        return;
    Node *t = head;
    head = head->next;
    delete t;
}

// Delete Last Node
void DeleteLast(Node* &head){
    Node *t = head;
    while(t->next->next != NULL){
        t = t->next;
    }
    Node *a = t->next;
    t->next = NULL;
    delete a;
}

// Delete nth Node
void Deletenth(Node* &head, int pos){
    if(head==NULL){
        cout<<"List is Empty\n";
        return;
    }
    if(pos==0){
        Node *t = head;
        head = t->next;
        delete t;
    }
    else{
        Node *t = head;
        pos--;
        while(pos && t->next != NULL){
            t = t->next;
            pos--;
        }
        if(!pos && t->next!=NULL){
            Node *q = t->next;
            t->next = t->next->next;
            delete q;
        }
        else{
            cout<<"Enter valid Position to delete node\n";
        }
    }
}


// Search Data in List
void Search(Node* &head, int data){
    Node *t = head;
    int i=1;
    while(t!=NULL){
        if(t->data == data){
            cout<<data<<" is present in position "<<i<<endl;
            return;
        }
        t = t->next;
        i++;
    }
    cout<<data<<" is not in list"<<endl;
}


// Count Number of Node ( Iterative Method )
int CountNodeIterative(Node* &head){
    int Count=0;
    Node *t = head;
    while(t!=NULL){
        Count++;
        t=t->next;
    }
    return Count+1;
}

// Count Number of Node ( Recursive Method )
int CountNodeRecursive(Node* &head){
    if(head==NULL)
        return 1;
    return 1 + CountNodeRecursive(head->next);
}


// Display List ( Iterative Method )
void DisplayIterative(Node* &head){
    Node *t = head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

// Display List ( Recursive Method )
void DisplayRecursive(Node* &head){
    if(head == NULL){
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    DisplayRecursive(head->next);
}


// Reverse List ( Iterative Method )
void ReverseIterative(Node* &head){
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Reverse List ( Recursive Method )
void ReverseRecursive(Node* p, Node* &head){
    if(p->next == NULL){
        head = p;
        return;
    }
    ReverseRecursive(p->next, head);
    //Node *q = p->next;
    //q->next = p;
    //p->next = NULL;
    p->next->next = p;
    p->next = NULL;
}

// Reverse List ( Using Stack )
void ReverseUsingStack(Node* &head){
    stack<Node*> s;
    Node *t = head;
    while(t->next!=NULL){
        s.push(t);
        t = t->next;
    }
    s.push(t);
    head = s.top();
    while(!s.empty()){
        t->next = s.top();
        s.pop();
        t = t->next;
    }
    t->next = NULL;
}


// --------> Main Function <--------
int main()
{
    Node *l = NULL;
    Deletenth(l, 1);
    InsertAtFirst(l, 0);
    InsertAtLast(l,5);
    DeleteFirst(l);
    InsertAtLast(l,15);
    DeleteLast(l);
    InsertAtnth(l, 1, 77);
    DisplayIterative(l);
    Deletenth(l, 2);
    DisplayIterative(l);
    InsertAtLast(l,25);
    DisplayIterative(l);
    InsertAtFirst(l,-5);
    InsertAtFirst(l, 715);
    InsertAtFirst(l, 55);
    DisplayIterative(l);
    Search(l,25);
    cout<<CountNodeIterative(l)<<endl;
    cout<<CountNodeRecursive(l)<<endl;
    DisplayRecursive(l);
    ReverseIterative(l);
    DisplayRecursive(l);
    cout<<"Reverse Recursive ";
    ReverseRecursive(l,l); // -----------------------
    DisplayIterative(l);
    cout<<endl<<endl;
    ReverseUsingStack(l);
    DisplayIterative(l);
    ReverseUsingStack(l);
    DisplayIterative(l);
}
