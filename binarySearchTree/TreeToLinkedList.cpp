#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node * right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Pair {
public:
    Node* head;
    Node* tail;

    Pair() {
        this->head = NULL;
        this->tail = NULL;
    }

    Pair(Node* head, Node* tail) {
        this->head = head;
        this->tail = tail;
    }
};


Node* insertNodeAgain(Node* root, int x) {
    if(root == NULL) {
        return new Node(x);
    }

    if(x <= root->val) {
        root->left = insertNodeAgain(root->left, x);
    }
    else {
        root->right = insertNodeAgain(root->right, x);
    }

    return root;
}

void printTree(Node* root) {
    if(root == NULL) {
        return;
    }

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

void printLinkedList(Node* root) {
    Node *temp = root;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->right;
    }
}

Pair convertTreeToLinkedList(Node* root) {
    Pair p;
    if(root == NULL) {
        return p;
    }
    if(root->left == NULL && root->right == NULL) {
        p.head = root, p.tail = root;
        return p;
    }

    Pair LT = convertTreeToLinkedList(root->left);
    Pair RT = convertTreeToLinkedList(root->right);

    if(LT.head == NULL && LT.tail == NULL) {
        root->right = RT.head;
        p.head = root;
        p.tail = RT.tail;
        return p;
    }
    if(RT.head == NULL && RT.tail == NULL) {
        LT.tail->right = root;
        p.head = LT.head;
        p.tail = root;
        return p;
    }

    LT.tail->right = root;
    root->right = RT.head;

    p.head = LT.head;
    p.tail = RT.tail;
    return p;
}

int main() {
    Node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int elem: arr) {
        root = insertNodeAgain(root, elem);
    }
    cout << "recursively created BST: " << endl;
    printTree(root);
    cout << endl;

    Pair HT = convertTreeToLinkedList(root);
    printLinkedList(HT.head);
}
