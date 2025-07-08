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

void preOrder(TreeNode *root, vector<int> &ans, int level){
    if(!root) return;
    ans[level] = root->val;
    preOrder(root->right, ans, level + 1);
    preOrder(root->left, ans, level + 1);
}

vector<int> leftSideView(TreeNode *root){
    int n = levels(root);
    vector<int> arr(n, 0);
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
    res = leftSideView(root);

    for(int x : res) cout << x << " ";
    cout << endl;
}