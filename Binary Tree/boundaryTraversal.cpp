#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void leftBoundary(TreeNode *root){
    if(!root || (!root->left && !root->right)) return;
    cout << root->val << " ";
    if(root->left) leftBoundary(root->left);
    else leftBoundary(root->right);
}

void rightBoundary(TreeNode *root){
    if(!root || (!root->left && !root->right)) return;
    if(root->right) rightBoundary(root->right);
    else rightBoundary(root->left);
    cout << root->val << " ";
}

void leafNodes(TreeNode *root){
    if(!root) return;
    leafNodes(root->left);
    if(!root->left && !root->right) cout << root->val << " ";
    // cout << root->val << " ";
    leafNodes(root->right);
}

void boundaryTraversal(TreeNode *root){
    if(!root) return;
    cout << root->val << " ";
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(9);
    root->right->left->right->left = new TreeNode(10);

    boundaryTraversal(root);
}