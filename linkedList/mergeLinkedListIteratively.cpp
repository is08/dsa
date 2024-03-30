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

Node* mergeLinkedList(Node* headOne, Node* headTwo) {
    Node *tempOne = headOne, *tempTwo = headTwo, *curr = NULL, *newHead = NULL;

    while(tempOne != NULL && tempTwo != NULL) {
        if(curr == NULL) {
            if(tempOne->data < tempTwo->data) {
                curr = tempOne;
                tempOne = tempOne->next;
            }
            else{
                curr = tempTwo;
                tempTwo = tempTwo->next;
            }
            newHead = curr;
        }
        else {
            if(tempOne->data < tempTwo->data) {
                curr->next = tempOne;
                curr = tempOne;
                tempOne = tempOne->next;
            }
            else {
                curr->next = tempTwo;
                curr = tempTwo;
                tempTwo = tempTwo->next;
            }
        }
    }

    if(tempOne != NULL) {
        curr->next = tempOne;
    }

    if(tempTwo != NULL) {
        curr->next = tempTwo;
    }

    return newHead;
}

int main() {
    Node *headOne = NULL;
    insertAtHead(headOne, 10);
    insertAtHead(headOne, 7);
    insertAtHead(headOne, 5);
    insertAtHead(headOne, 1);
    printLL(headOne);

    Node *headTwo = NULL;
    insertAtHead(headTwo, 6);
    insertAtHead(headTwo, 3);
    insertAtHead(headTwo, 2);
    printLL(headTwo);

    Node *mergedHead = mergeLinkedList(headOne, headTwo);
    printLL(mergedHead);

    return 0;
}
