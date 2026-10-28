#include <iostream>
#include <queue>
using namespace std;

struct EmployeeNode {
    int employeeId;
    EmployeeNode *left;
    EmployeeNode *right;
};

EmployeeNode* createEmployee(int id) {
    EmployeeNode *newNode = new EmployeeNode();
    newNode->employeeId = id;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

EmployeeNode* insertEmployee(EmployeeNode *root, int id) {
    if (root == nullptr) return createEmployee(id);
    if (id < root->employeeId) {
        root->left = insertEmployee(root->left, id);
    } else if (id > root->employeeId) {
        root->right = insertEmployee(root->right, id);
    }
    return root;
}

int height(EmployeeNode *root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void printLevelOrder(EmployeeNode *root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<EmployeeNode*> q;
    q.push(root);

    cout << "Level order traversal: ";
    while (!q.empty()) {
        EmployeeNode *current = q.front();
        q.pop();
        cout << current->employeeId << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    cout << endl;
}

void printLeafEmployees(EmployeeNode *root) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->employeeId << " ";
        return;
    }

    if (root->left != nullptr) printLeafEmployees(root->left);
    if (root->right != nullptr) printLeafEmployees(root->right);
}

int main() {
    EmployeeNode *root = nullptr;
    int ids[] = {50, 20, 70, 10, 30, 60, 80};

    for (int id : ids) {
        root = insertEmployee(root, id);
    }

    cout << "Original tree (level-wise): ";
    printLevelOrder(root);
    cout << "Height of BST: " << height(root) << endl;
    cout << "Leaf employee IDs: ";
    printLeafEmployees(root);
    cout << endl;

    return 0;
}
