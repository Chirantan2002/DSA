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

int levels(TreeNode *root){
    if(!root) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void nthLevel(TreeNode *root, int curr, int end, vector<int> &ans){
    if(!root) return;
    if(curr == end){
        ans[curr] = root->val;
        return;
    }
    nthLevel(root->left, curr + 1, end, ans);
    nthLevel(root->right, curr + 1, end, ans);
}

void levelOrder(TreeNode *root, vector<int> &ans){
    int n = levels(root);
    for(int i = 0;i < n;++i){
        nthLevel(root, 0, i, ans);
    }
}

void preOrder(TreeNode *root, vector<int>& ans, int level){
    if(!root) return;
    ans[level] = root->val;
    preOrder(root->left, ans, level + 1);
    preOrder(root->right, ans, level + 1);
}

vector<int> rightSideView(TreeNode* root){
    vector<int> arr(levels(root), 0);
    // levelOrder(root, arr);
    preOrder(root, arr, 0);
    return arr;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(8);

    vector<int> res;
    res = rightSideView(root);

    for(int x : res) cout << x << " ";
    cout << endl;
}