#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:

        int val;
        Node *left;
        Node *right;

        Node(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree() {
    int val;
    cin >> val;

    if(val == -1) {
        return NULL;
    }

    Node *newNode = new Node(val);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

//1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void printTree(Node *root) {
    queue<Node*> nodesToBePrinted;
    nodesToBePrinted.push(root);

    while(!nodesToBePrinted.empty()) {
        Node* currNode = nodesToBePrinted.front();
        cout << currNode->val << " ";

        if(currNode->left != NULL) {
            nodesToBePrinted.push(currNode->left);
        }
        if(currNode->right != NULL) {
            nodesToBePrinted.push(currNode->right);
        }

        nodesToBePrinted.pop();
    }
    cout << endl;
}

void printLeveledTree(Node *root) {
    queue<Node*> nodesToBePrinted;
    nodesToBePrinted.push(root);
    nodesToBePrinted.push(NULL);

    while(1) {
        Node* currNode = nodesToBePrinted.front();
        nodesToBePrinted.pop();

        if(currNode == NULL) {
            cout << endl;

            if(nodesToBePrinted.empty()) {
                break;
            }
            nodesToBePrinted.push(NULL);
        }
        else {
            cout << currNode->val << " ";

            if(currNode->left != NULL) {
                nodesToBePrinted.push(currNode->left);
            }
            if(currNode->right != NULL) {
                nodesToBePrinted.push(currNode->right);
            }
        }
    }
    cout << endl;
}


int main() {
    Node *root = buildTree();
    printTree(root);
    cout << endl;
    printLeveledTree(root);

    return 0;
}
