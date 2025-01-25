#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

// 1. Insert into BST
void insert(Node *&root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    if (x < root->val) insert(root->left, x);
    else insert(root->right, x);
}

// 2. Delete from BST
Node* deleteNode(Node* root, int x) {
    if (!root) return root;
    if (x < root->val) root->left = deleteNode(root->left, x);
    else if (x > root->val) root->right = deleteNode(root->right, x);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = root->right;
        while (temp->left) temp = temp->left;
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// 3. Search in BST
bool search(Node* root, int x) {
    if (!root) return false;
    if (root->val == x) return true;
    return x < root->val ? search(root->left, x) : search(root->right, x);
}

// 4. Find Minimum and Maximum
int findMin(Node* root) {
    if (!root) return INT_MAX;
    while (root->left) root = root->left;
    return root->val;
}

int findMax(Node* root) {
    if (!root) return INT_MIN;
    while (root->right) root = root->right;
    return root->val;
}

// 5. Check if tree is BST
bool isBST(Node* root, Node* minNode = NULL, Node* maxNode = NULL) {
    if (!root) return true;
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        return false;
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}

// 6. In-order Traversal (Recursive)
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// 6. In-order Traversal (Iterative)
void inOrderIterative(Node* root) {
    stack<Node*> st;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout << root->val << " ";
        root = root->right;
    }
}

// 7. Pre-order Traversal
void preOrder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 8. Post-order Traversal
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

// 9. Level-order Traversal
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

// 10. Find Height/Depth of BST
int findHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

// Intermediate Problems
// 11. Find K-th Smallest/Largest Element
int findKth(Node* root, int &k, bool smallest) {
    if (!root) return -1;
    int val = smallest ? findKth(root->left, k, smallest) : findKth(root->right, k, smallest);
    if (val != -1) return val;
    if (--k == 0) return root->val;
    return smallest ? findKth(root->right, k, smallest) : findKth(root->left, k, smallest);
}

// 12. Find Floor and Ceil
int findFloor(Node* root, int x) {
    int floor = INT_MIN;
    while (root) {
        if (root->val == x) return root->val;
        if (root->val < x) {
            floor = root->val;
            root = root->right;
        } else root = root->left;
    }
    return floor;
}

int findCeil(Node* root, int x) {
    int ceil = INT_MAX;
    while (root) {
        if (root->val == x) return root->val;
        if (root->val > x) {
            ceil = root->val;
            root = root->left;
        } else root = root->right;
    }
    return ceil;
}

// 13. Lowest Common Ancestor (LCA)
Node* findLCA(Node* root, int p, int q) {
    if (!root) return NULL;
    if (root->val > p && root->val > q) return findLCA(root->left, p, q);
    if (root->val < p && root->val < q) return findLCA(root->right, p, q);
    return root;
}

// 14. Convert Sorted Array to BST
Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// 15. Convert BST to Sorted Doubly Linked List
Node* prevNode = NULL, *head = NULL;
void bstToDLL(Node* root) {
    if (!root) return;
    bstToDLL(root->left);
    if (!prevNode) head = root;
    else {
        prevNode->right = root;
        root->left = prevNode;
    }
    prevNode = root;
    bstToDLL(root->right);
}

// Additional Problems
// 16. Check if two BSTs are identical
bool areIdentical(Node* r1, Node* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2 || r1->val != r2->val) return false;
    return areIdentical(r1->left, r2->left) && areIdentical(r1->right, r2->right);
}

// 17. Count Nodes in BST
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 18. Count Leaf Nodes
int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// 19. Find Distance Between Two Nodes
int findDistance(Node* root, int a, int b) {
    Node* lca = findLCA(root, a, b);
    function<int(Node*, int)> getDist = [&](Node* root, int x) {
        if (!root) return -1;
        if (root->val == x) return 0;
        int dist = root->val > x ? getDist(root->left, x) : getDist(root->right, x);
        return dist == -1 ? -1 : dist + 1;
    };
    return getDist(lca, a) + getDist(lca, b);
}

// 20. Range Sum of BST
int rangeSumBST(Node* root, int low, int high) {
    if (!root) return 0;
    if (root->val < low) return rangeSumBST(root->right, low, high);
    if (root->val > high) return rangeSumBST(root->left, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    Node* root = NULL;
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35};
    for (int v : vals) insert(root, v);

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
