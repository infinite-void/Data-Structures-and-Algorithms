#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* A basic `Node` data structure in a tree.
 * `Nodes` are building blocks in a tree
 */
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


/* A recursive function that builds the 
 * tree starting form head node or root node.
 * The middle element of the sorted makes the 
 * root element for a balanced structure.
 */
Node* buildBST(const vector<int>& input, int start, int end) {
    if(start > end || start < 0 || end >= input.size())
        return nullptr;
    
    int mid = (start + end) / 2;
    Node* root = new Node();
    root->data = input[mid];
    root->left = buildBST(input, start, mid - 1);
    root->right = buildBST(input, mid + 1, end);
    return root;
}

/* We use inOrder traversal to check the 
 * binary tree. inOrder Traversal of a 
 * binary search tree is always in non-decreasing order
 */
void inOrder(Node* root) {
    if(root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int n;
    cout << "Enter number of values :";
    cin >> n;
    
    vector<int> input(n, 0);
    for(int i = 0; i < n; i++) 
        cin >> input[i];

    sort(input.begin(), input.end());

    Node* root = buildBST(input, 0, n -1);
    inOrder(root);

    cout << endl;
    return 0;
}