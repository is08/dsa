#include<iostream>
#include<queue>
#include<utility>
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

// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
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

//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
Node* buildLevelOrderTree() {
    int rootVal;
    cin >> rootVal;
    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;
        Node* currNode = q.front();
        q.pop();

        if(leftVal == -1) {
            currNode->left = NULL;
        }
        else {
            Node* leftNode = new Node(leftVal);
            currNode->left = leftNode;
            q.push(leftNode);
        }

         if(rightVal == -1) {
            currNode->right = NULL;
        }
        else {
            Node* rightNode = new Node(rightVal);
            currNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

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

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1 + max(h1, h2);
}

int diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

int replaceWithSum(Node* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return root->val;
    }

    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    int temp = root->val;
    root->val = LS + RS;

    return temp + root->val;
}

pair<bool, int> isHeightBalanced(Node* node) {
    pair<bool, int> ans;
    if(node == NULL) {
        ans.first = true;
        ans.second = 0;
        return ans;
    }

    pair<bool, int> LT = isHeightBalanced(node->left);
    pair<bool, int> RT = isHeightBalanced(node->right);

    ans.first = (abs(LT.second - RT.second) <= 1) && LT.first && RT.first;
    ans.second = 1 + max(LT.second, RT.second);

    return ans;
}

pair<int, int> maxSubsetSum(Node *node) {
    if(node == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> LT = maxSubsetSum(node->left);
    pair<int, int> RT = maxSubsetSum(node->right);

    int nodeIncluded = node->val + LT.second + RT.second;
    int nodeExcluded = max(LT.first, LT.second) + max(RT.first, RT.second);

    return make_pair(nodeIncluded, nodeExcluded);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int l = q.size();

        for(int i = 1; i <= l; i++) {
            Node* curr = q.front();
            q.pop();

            if(i == 1) {
                ans.push_back(curr->val);
            }

            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
    return ans;
}

int main() {
    Node *root = buildTree();
    printTree(root);
    cout << endl;
    printLeveledTree(root);
    cout << endl;
    cout << "diameter is " << diameter(root) << endl;

    Node *rootAgain = buildLevelOrderTree();
    printTree(rootAgain);
    cout << endl;
    printLeveledTree(rootAgain);
    cout << "diameter is " << diameter(rootAgain) << endl;

    replaceWithSum(root);
    cout << "printing the updated tree where all the nodes have been replaced by their descendant sums:" << endl;
    printLeveledTree(root);

    pair<bool, int> ans = isHeightBalanced(rootAgain);
    cout << "the tree is height balanced: " << ans.first << " and height of the tree is " << ans.second << endl;

    pair<int, int> ans2 = maxSubsetSum(rootAgain);
    cout << "the max sum of subset is : " << max(ans2.first, ans2.second) << endl;

    vector<int> left = leftView(rootAgain);
    for(int i = 0; i < left.size(); i++) {
        cout << left[i] << " ";
    }
    cout << endl;

    return 0;
}
