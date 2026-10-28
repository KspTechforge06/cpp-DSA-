#include <iostream>
using namespace std;

struct BookNode {
    string title;
    BookNode *left;
    BookNode *right;
};

BookNode* createBook(string title) {
    BookNode *newNode = new BookNode();
    newNode->title = title;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void inorder(BookNode *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->title << " ";
    inorder(root->right);
}

void preorder(BookNode *root) {
    if (root == nullptr) return;
    cout << root->title << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BookNode *root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->title << " ";
}

int main() {
    BookNode *root = createBook("Data Structures");
    root->left = createBook("Algorithms");
    root->right = createBook("Operating Systems");
    root->left->left = createBook("C++ Basics");
    root->left->right = createBook("Graph Theory");
    root->right->left = createBook("Computer Networks");

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
