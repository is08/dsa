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

int getLengthOfLinkedList(Node *head) {
    Node *temp = head;
    int len = 0;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    return len;
}

Node* kReverseLinkedListRecursively(Node *head, int k) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *curr = head, *tempCurr = head, *prev = NULL, *next = NULL;
    int tempK = k;

    while(curr != NULL && tempK--) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* newHead = kReverseLinkedListRecursively(curr, k);
    tempCurr->next = newHead;

    return prev;
}

int main() {
    Node *head = NULL;
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);


    printLL(head);
    Node* newHead = kReverseLinkedListRecursively(head, 3);
    cout << "reverse k-list: ";
    printLL(newHead);

    return 0;
}
