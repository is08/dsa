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

Node* kReverseLinkedList(Node *head, int k) {
    int len = getLengthOfLinkedList(head);
    int partitions = (len / k) + 1;
    Node *curr = head, *prev = NULL, *next = NULL, *connectionOne = curr, *connectionTwo = NULL, *newHead = NULL;
    bool isFirstTime = true;

    while(partitions--) {
        int temp = k;
        prev = NULL;
        Node *tempHead = curr;
        while(curr != NULL && temp--) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        if(!isFirstTime) {
            connectionTwo = prev;
            connectionOne -> next = connectionTwo;
            connectionOne = tempHead;
        }

        if(isFirstTime) {
            isFirstTime = false;
            newHead = prev;
        }
    }

    return newHead;
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

    /*insertInTheMiddle(head, 8, 3);
    insertInTheMiddle(head, 9, 4);
    insertInTheMiddle(head, 10, 5);*/

    printLL(head);
    Node* newHead = kReverseLinkedList(head, 3);
    cout << "reverse k-list: ";
    printLL(newHead);

    return 0;
}
