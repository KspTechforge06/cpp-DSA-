#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node *root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int height(Node *root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Level order traversal: ";
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    cout << endl;
}

void printLeafNodes(Node *root) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }

    if (root->left != nullptr) printLeafNodes(root->left);
    if (root->right != nullptr) printLeafNodes(root->right);
}

int main() {
    Node *root = nullptr;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Original BST (level-wise): ";
    printLevelOrder(root);
    cout << "Height of BST: " << height(root) << endl;
    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    return 0;
}
