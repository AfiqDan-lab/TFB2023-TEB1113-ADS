#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> h;

    void insert(int x) {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0 && h[(i - 1)/2] < h[i]) {
            swap(h[(i - 1)/2], h[i]);
            i = (i - 1)/2;
        }
    }

    void print() {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

class MinHeap {
public:
    vector<int> h;

    void insert(int x) {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0 && h[(i - 1)/2] > h[i]) {
            swap(h[(i - 1)/2], h[i]);
            i = (i - 1)/2;
        }
    }

    void print() {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insertBST(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->data) root->left = insertBST(root->left, v);
    else root->right = insertBST(root->right, v);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

struct BTreeNode {
    vector<int> keys;
    vector<BTreeNode*> child;
    bool leaf;

    BTreeNode(bool lf) : leaf(lf) {
        child.resize(4, NULL);
    }
};

class SimpleBTree {
public:
    BTreeNode* root = NULL;

    void insert(int x) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(x);
            return;
        }
        root->keys.push_back(x);
        sort(root->keys.begin(), root->keys.end());
    }

    void print() {
        for (int x : root->keys) cout << x << " ";
        cout << endl;
    }
};

int main() {

    cout << "=== Max Heap ===\n";
    MaxHeap mx;
    mx.insert(40);
    mx.insert(10);
    mx.insert(50);
    mx.insert(20);
    mx.print();

    cout << "\n=== Min Heap ===\n";
    MinHeap mn;
    mn.insert(40);
    mn.insert(10);
    mn.insert(50);
    mn.insert(20);
    mn.print();

    cout << "\n=== Binary Search Tree ===\n";
    Node* root = NULL;
    root = insertBST(root, 30);
    insertBST(root, 10);
    insertBST(root, 50);
    insertBST(root, 20);
    inorder(root);
    cout << endl;

    cout << "\n=== Simple B-Tree (Demo Only) ===\n";
    SimpleBTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(20);
    bt.insert(7);
    bt.insert(12);
    bt.print();

    return 0;
}
