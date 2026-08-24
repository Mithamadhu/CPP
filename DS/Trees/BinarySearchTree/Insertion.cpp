#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure for a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int key) {

    // If tree is empty, create a new node
    if (root == nullptr) {
        return new Node(key);
    }

    // Insert into the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }

    // Insert into the right subtree
    else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Print the tree in level order
void printTree(Node* root) {
    if (root == nullptr) {
        cout << "[]";
        return;
    }

    vector<string> ans;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == nullptr) {
            ans.push_back("N");
        } else {
            ans.push_back(to_string(curr->data));
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    // Remove trailing N's
    while (!ans.empty() && ans.back() == "N") {
        ans.pop_back();
    }

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i + 1 < ans.size()) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main() {

    // Create the BST
    //        22
    //       /  \
    //     12    30
    //    /  \
    //   8    20
    //          \
    //           21

    Node* root = new Node(22);
    root->left = new Node(12);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(20);
    root->left->right->right = new Node(21);

    int key = 15;

    root = insert(root, key);

    printTree(root);

    return 0;
}
