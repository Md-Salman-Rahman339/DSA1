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


Node  *input_tree(){
    int val;
    cin>>val;
    Node *root;
    if(val==-1) root=NULL;
    else 
    root=new Node(val);
    queue<Node*>q;
    if(root)
    q.push(root);
    while(!q.empty()){
        Node *p=q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node *myleft;
        Node *myright;
        if(l==-1) myleft=NULL;
        else myleft=new Node(l);
        if(r==-1) myright=NULL;
        else myright=new Node(r);
        p->left=myleft;
        p->right=myright;
        if(p->left)
          q.push(p->left);
        if(p->right)
           q.push(p->right);
    }
    return root;
}
// Preorder traversal
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Inorder traversal
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int count(Node *root){
    if(root==NULL){
        return 0;

    }
    int l=count(root->left);
    int r=count(root->right);
    return l+r+1;
}
int count_leaf(Node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else{
        int l=count_leaf(root->left);
        int r=count_leaf(root->right);
        return l+r;
    }
}
int maxHeight(Node *root){
    if(root==NULL){
        return 0;
    }
    int l=maxHeight(root->left);
    int r=maxHeight(root->right);
    return max(l,r)+1;
}

bool isNodePresent(Node *root,int x){
    if(root==NULL){
        return false;
    }
    if(root->val==x){
        return true;
    }
    bool l=isNodePresent(root->left,x);
    bool r=isNodePresent(root->right,x);
    return (l||r);
}
bool specialbianryTree(Node *root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->left==NULL || root->right==NULL){
        return false;
    }
    bool l=specialbianryTree(root->left);
    bool r=specialbianryTree(root->right);
    if(l==false || r==false){
        return false;
    }
    return true;
}

vector<int> reverseLevelorder(Node *root){
    vector<int>v;
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty()){
        Node *node=q.front();
        q.pop();
        v.push_back(node->val);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        
    }
    reverse(v.begin(),v.end());
    return v;
}
int main() {
    // // Creating nodes
    // Node *root = new Node(10);
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *c = new Node(40);
    // Node *d = new Node(50);
    // Node *e = new Node(60);
    // Node *f = new Node(70);
    // Node *g = new Node(80);
    // Node *h = new Node(90);
    // Node *i = new Node(100);

    // // Connecting nodes to form the tree
    // root->left = a;
    // root->right = b;
    // a->left = c;
    // a->right = h;
    // c->right = e;
    // b->right = d;
    // d->left = f;
    // d->right = g;
    // h->right = i;
    Node *root=input_tree();
    // Traversals
    // cout << "Preorder: ";
    // preorder(root);
    // cout << endl;
    // cout<<count(root)<<endl;
    // cout<<"Leaf node : "<<count_leaf(root);
    // cout<<"Max height: "<<maxHeight(root);
//   bool f= isNodePresent(root,0);
//   cout<<f<<endl;
// cout<<specialbianryTree(root)<<endl;
 vector<int>result= reverseLevelorder(root);
 cout<<"Reverse: ";
 for(int val:result){
    cout<<val<<" ";
 }
 cout<<endl;

    // cout << "Postorder: ";
    // postorder(root);
    // cout << endl;

    // cout << "Inorder: ";
    // inorder(root);
    // cout << endl;

    return 0;
}
