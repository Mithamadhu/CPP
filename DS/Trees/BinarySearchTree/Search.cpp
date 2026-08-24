#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

bool search(Node* root, int key) {
 
    // root is null -> return false
    if (root == nullptr) return false;

    // if root has key -> return true
    if (root->data == key) return true;

    if (key > root->data) 
        return search(root->right, key);
        
    else
        return search(root->left, key);
}

int main() {
    // Creating BST
    //    6
    //   / \
    //  2   8
    //     / \
    //    7   9
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    
    // Searching for key in BST
    cout << search(root, key) << endl;
}
