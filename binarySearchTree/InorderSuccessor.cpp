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

Node* findNode(Node* root, int val) {
    while(root != NULL) {
        if(root->val == val) {
            return root;
        }

        if(val > root->val) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }

    return NULL;
}

Node* findLeftMostNode(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* finSuccForLeafNode(Node* root, Node* target) {
    int succ = -10e8;
    Node* temp = root, *temp2 = NULL;

    while(temp != NULL) {
        if(temp->val > target->val) {
            succ = temp->val;
            temp2 = temp;
        }

        if(target->val > temp->val) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    return temp2;
}

Node* findSucc(Node *root, Node* target) {
    Node* temp = root;

    while(temp != NULL) {
        if(temp == target) {
            if(temp->right == NULL) {
                return temp;
            }
            else {
                return findLeftMostNode(temp->right);
            }
        }

        if(target->val > temp->val) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    return NULL;
}

Node *inorderSucc(Node* root, Node* target) {
    Node *ans = NULL;

    if(target->left == NULL && target->right == NULL) {
        ans = finSuccForLeafNode(root, target);
    }
    else {
        ans = findSucc(root, target);
    }

    return ans;
}

int main() {
    Node* root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int elem: arr) {
        root = insertNodeAgain(root, elem);
    }
    cout << "recursively created BST: " << endl;
    inorderTraversal(root);
    cout << endl;

    Node* target = findNode(root, 4);
    Node* succ = inorderSucc(root, target);
    cout << "successor is " << succ->val << endl;

    return 0;
}
