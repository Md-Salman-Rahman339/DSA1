#include <bits/stdc++.h>
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

Node* input_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if (root)
        q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node* myleft, *myright;
        if (l == -1) myleft = NULL;
        else myleft = new Node(l);
        if (r == -1) myright = NULL;
        else myright = new Node(r);

        p->left = myleft;
        p->right = myright;

        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
    return root;
}

// Preorder Traversal (Recursive)
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Recursive)
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Inorder Traversal (Recursive)
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Iterative Inorder Traversal
void inorder_iterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

// Level Order Traversal (Breadth-First Search)
void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// Count Nodes in a Binary Tree
int count(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

// Height of a Binary Tree
int maxHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

// Maximum Depth of a Binary Tree
int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Print Nodes at K-th Level
void printKthLevel(Node* root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        cout << root->val << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

// Check if the Tree is a Binary Search Tree (BST)
bool isBST(Node* root, int min_val = INT_MIN, int max_val = INT_MAX) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= min_val || root->val >= max_val) {
        return false;
    }
    return isBST(root->left, min_val, root->val) && isBST(root->right, root->val, max_val);
}

// Symmetric Tree (Mirror Image Check)
bool isSymmetric(Node* root) {
    if (root == NULL) return true;
    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
        Node* left = q.front();
        q.pop();
        Node* right = q.front();
        q.pop();
        if (left == NULL && right == NULL) continue;
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val) return false;
        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }
    return true;
}

// Find the Lowest Common Ancestor (LCA) of Two Nodes
Node* LCA(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;
    if (root == p || root == q) return root;
    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

// Diameter of a Binary Tree
int diameter(Node* root, int &height) {
    if (root == NULL) {
        height = 0;
        return 0;
    }
    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = diameter(root->left, leftHeight);
    int rightDiameter = diameter(root->right, rightHeight);
    height = max(leftHeight, rightHeight) + 1;
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Flatten the Binary Tree to a Linked List (Preorder)
void flatten(Node* root) {
    if (root == NULL) return;
    if (root->left) {
        flatten(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) root = root->right;
        root->right = temp;
    }
    flatten(root->right);
}

// Right Side View of a Binary Tree
void rightSideView(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (i == size - 1) {
                cout << node->val << " ";
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

// Zigzag Level Order Traversal
void zigzagLevelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    stack<int> s;
    bool leftToRight = true;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (leftToRight) {
                cout << node->val << " ";
            } else {
                s.push(node->val);
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (!leftToRight) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        leftToRight = !leftToRight;
    }
}

// Sum of Nodes at K-th Level
int sumAtKthLevel(Node* root, int k) {
    if (root == NULL) return 0;
    if (k == 0) return root->val;
    return sumAtKthLevel(root->left, k - 1) + sumAtKthLevel(root->right, k - 1);
}

// Convert a Binary Tree to a Doubly Linked List (In-order traversal)
void treeToDoublyList(Node* root, Node* &head, Node* &prev) {
    if (root == NULL) return;
    treeToDoublyList(root->left, head, prev);
    if (prev == NULL) {
        head = root;
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    treeToDoublyList(root->right, head, prev);
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (root == NULL) return;
    map<int, vector<int>> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        m[node.second].push_back(node.first->val);
        if (node.first->left) q.push({node.first->left, node.second - 1});
        if (node.first->right) q.push({node.first->right, node.second + 1});
    }
    for (auto &entry : m) {
        for (auto &val : entry.second) {
            cout << val << " ";
        }
    }
}

// Max Path Sum
int maxPathSum(Node* root, int &maxSum) {
    if (root == NULL) return 0;
    int left = max(0, maxPathSum(root->left, maxSum));
    int right = max(0, maxPathSum(root->right, maxSum));
    maxSum = max(maxSum, left + right + root->val);
    return max(left, right) + root->val;
}

int main() {
    Node* root = input_tree();

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Inorder Iterative: ";
    inorder_iterative(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    cout << "Total Nodes: " << count(root) << endl;

    cout << "Height of Tree: " << maxHeight(root) << endl;

    cout << "Max Depth: " << maxDepth(root) << endl;

    int k = 2;
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k);
    cout << endl;

    cout << "Is BST: " << (isBST(root) ? "Yes" : "No") << endl;

    cout << "Is Symmetric: " << (isSymmetric(root) ? "Yes" : "No") << endl;

    Node* p = new Node(4), *q = new Node(5);  // Modify as per tree structure
    Node* lca = LCA(root, p, q);
    cout << "LCA of 4 and 5: " << (lca ? to_string(lca->val) : "NULL") << endl;

    int diameterHeight = 0;
    cout << "Diameter of Tree: " << diameter(root, diameterHeight) << endl;

    flatten(root);
    cout << "Flattened Tree (Preorder): ";
    preorder(root);
    cout << endl;

    cout << "Right Side View: ";
    rightSideView(root);
    cout << endl;

    cout << "Zigzag Level Order: ";
    zigzagLevelOrder(root);
    cout << endl;

    cout << "Sum at Level " << k << ": " << sumAtKthLevel(root, k) << endl;

    Node* head = NULL, *prev = NULL;
    treeToDoublyList(root, head, prev);
    cout << "Doubly Linked List (Inorder): ";
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;

    cout << "Vertical Order: ";
    verticalOrder(root);
    cout << endl;

    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
    cout << "Max Path Sum: " << maxSum << endl;

    return 0;
}
