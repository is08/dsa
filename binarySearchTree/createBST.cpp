#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertNode(Node* root, int x) {
    Node* newNode = new Node(x);
    if(root == NULL) {
        root = newNode;
        return root;
    }

    Node* curr = root;
    while(1) {
        if(x <= curr->val) {
            if(curr->left == NULL) {
                curr->left = newNode;
                break;
            }
            else {
                curr = curr->left;
            }
        }
        else {
            if(curr->right == NULL) {
                curr->right = newNode;
                break;
            }
            else {
                curr = curr->right;
            }
        }
    }
    return root;
}

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

void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    Node* rootAgain = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int elem: arr) {
        root = insertNode(root, elem);
    }
    cout << "iteratively created BST: " << endl;
    inorderTraversal(root);

    for(int elem: arr) {
        rootAgain = insertNodeAgain(rootAgain, elem);
    }
    cout << endl << endl << "recursively created BST: " << endl;
    inorderTraversal(rootAgain);

    return 0;
}

