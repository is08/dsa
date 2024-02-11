#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printLL(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertInTheMiddle(Node* &head, int data, int pos) {
    if(pos == 0) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *newNode = new Node(data);
    Node *temp = head;

    while(--pos) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);

    printLL(head);

    insertAtHead(head, 6);
    insertAtHead(head, 7);

    printLL(head);

    insertInTheMiddle(head, 8, 3);

    printLL(head);

    insertInTheMiddle(head, 9, 4);
    insertInTheMiddle(head, 10, 5);

    printLL(head);

    return 0;
}
