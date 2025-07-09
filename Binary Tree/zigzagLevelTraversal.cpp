#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int levels(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void nthLevelValues(TreeNode *root, int level, int req, vector<int> &v)
{
    if (!root)
        return;
    if (level == req)
    {
        v.push_back(root->data);
        return;
    }
    nthLevelValues(root->left, level + 1, req, v);
    nthLevelValues(root->right, level + 1, req, v);
}

void helper(TreeNode *root, vector<vector<int>> &ans)
{
    int n = levels(root);
    for (int i = 0; i < n; ++i)
    {
        vector<int> v;
        nthLevelValues(root, 0, i, v);
        if (i % 2 & 1)
            reverse(begin(v), end(v));
        ans.push_back(v);
    }
}

vector<vector<int>> zigzagTraversal(TreeNode *root){
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        int sz = q.size();
        vector<int> level;
        for(int i = 0;i < sz;++i){
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(flag) reverse(begin(level), end(level));
        ans.push_back(level);
        flag = !flag;
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans;
    ans = zigzagTraversal(root);
    // helper(root, ans);
    for (auto &v : ans)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}