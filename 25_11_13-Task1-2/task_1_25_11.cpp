#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

Node* findMin(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void update(Node* root, int oldValue, int newValue) {
    Node* node = search(root, oldValue);
    if (node != nullptr) {
        node->data = newValue;
        cout << "Node updated successfully!\n";
    } else {
        cout << "Value not found in tree.\n";
    }
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "\nDeleting 20...\n";
    root = deleteNode(root, 20);
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "\nUpdating 40 -> 45...\n";
    update(root, 40, 45);
    cout << "Inorder after update: ";
    inorder(root);
    cout << endl;

    return 0;
}
