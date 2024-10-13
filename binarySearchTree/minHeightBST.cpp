#include<iostream>
#include<vector>
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

Node* mst(vector<int> arr, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* newNode = new Node(arr[mid]);

    newNode->left = mst(arr, start, mid - 1);
    newNode->right = mst(arr, mid + 1, end);

    return newNode;
}

void printTree(Node* root) {
    if(root == NULL) {
        return;
    }

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 5, 6, 7};
    int start = 0;
    int end = arr.size() - 1;

    Node* root = mst(arr, start, end);
    printTree(root);

    return 0;
}
