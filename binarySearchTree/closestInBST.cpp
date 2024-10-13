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

int findClosestInBST(Node *root, int target) {
    Node* curr = root;
    int minDiff = INT_MAX, elem = -1;

    while(curr != NULL) {
        int currDiff = abs(target - curr->val);

        if(currDiff == 0) {
            return curr->val;
        }

        if(minDiff > currDiff) {
            minDiff = currDiff;
            elem = curr->val;
        }

        if(target > curr->val) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }

    return elem;
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

    cout << "the closest elem to 16 is " << findClosestInBST(root, 13) << endl;
}
