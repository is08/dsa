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

bool isPresent(Node* root,int key){
    if(root == NULL) {
        return false;
    }
    if(root->val == key) {
        return true;
    }

    bool result = false;

    if(key < root->val) {
        result = isPresent(root->left, key);
    }
    else {
        result = isPresent(root->right, key);
    }

    return result;
}

int main() {
    Node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

     for(int elem: arr) {
        root = insertNodeAgain(root, elem);
    }
    inorderTraversal(root);
    cout << endl << endl;

    cout << "is 13 present in the BST? " << isPresent(root, 13) << endl;
    cout << "is 2 present in the BST? " << isPresent(root, 2) << endl;

    return 0;
}
