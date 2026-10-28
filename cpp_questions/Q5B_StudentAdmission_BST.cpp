#include <iostream>
#include <stack>
using namespace std;

struct StudentNode {
    int rollNumber;
    StudentNode *left;
    StudentNode *right;
};

StudentNode* createStudent(int roll) {
    StudentNode *newNode = new StudentNode();
    newNode->rollNumber = roll;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

StudentNode* insertStudent(StudentNode *root, int roll) {
    if (root == nullptr) return createStudent(roll);
    if (roll < root->rollNumber) {
        root->left = insertStudent(root->left, roll);
    } else if (roll > root->rollNumber) {
        root->right = insertStudent(root->right, roll);
    }
    return root;
}

void inorderIterative(StudentNode *root) {
    stack<StudentNode*> st;
    StudentNode *current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->rollNumber << " ";
        current = current->right;
    }
    cout << endl;
}

void preorderIterative(StudentNode *root) {
    if (root == nullptr) return;

    stack<StudentNode*> st;
    st.push(root);

    while (!st.empty()) {
        StudentNode *current = st.top();
        st.pop();
        cout << current->rollNumber << " ";

        if (current->right != nullptr) st.push(current->right);
        if (current->left != nullptr) st.push(current->left);
    }
    cout << endl;
}

int main() {
    StudentNode *root = nullptr;
    int rollNumbers[] = {120, 80, 150, 40, 100, 130, 170};

    for (int roll : rollNumbers) {
        root = insertStudent(root, roll);
    }

    cout << "Inorder (non-recursive): ";
    inorderIterative(root);

    cout << "Preorder (non-recursive): ";
    preorderIterative(root);

    return 0;
}
