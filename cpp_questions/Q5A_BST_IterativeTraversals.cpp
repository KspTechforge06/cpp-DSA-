#include <iostream>
#include <stack>
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

void inorderIterative(Node *root) {
    stack<Node*> st;
    Node *current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

void preorderIterative(Node *root) {
    if (root == nullptr) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node *current = st.top();
        st.pop();
        cout << current->data << " ";

        if (current->right != nullptr) st.push(current->right);
        if (current->left != nullptr) st.push(current->left);
    }
    cout << endl;
}

int main() {
    Node *root = nullptr;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder (non-recursive): ";
    inorderIterative(root);

    cout << "Preorder (non-recursive): ";
    preorderIterative(root);

    return 0;
}
