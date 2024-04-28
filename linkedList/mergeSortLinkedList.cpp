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

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node *merge(Node* left, Node* right) {
    Node* newHead = NULL, *curr = NULL;

    while(left != NULL && right != NULL) {
        if(newHead == NULL) {
            if(left->data < right->data) {
                newHead = left;
                left = left->next;
            }
            else {
                newHead = right;
                right = right->next;
            }
            curr = newHead;
        }
        else {
            if(left->data < right->data) {
                curr->next = left;
                curr = left;
                left = left->next;
            }
            else {
                curr->next = right;
                curr = right;
                right = right->next;
            }
        }
    }

    if(left != NULL) {
        curr->next = left;
    }
    if(right != NULL) {
        curr->next = right;
    }

    return newHead;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* newHead = merge(left, right);

    return newHead;
}

int main() {
    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 11);
    printLL(head);

    Node *newHead = mergeSort(head);
    printLL(newHead);

    return 0;
}
