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

void helper(TreeNode *root, vector<int> &arr, vector<vector<int>> &ans, int target){
    if(!root) return;
    if(!root->left && !root->right && root->val == target){
        arr.push_back(root->val);
        ans.push_back(arr);
        arr.pop_back();
        return;
    }
    arr.push_back(root->val);
    helper(root->left, arr, ans, target - root->val);
    helper(root->right, arr, ans, target - root->val);
    arr.pop_back();
    return;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum){
    vector<vector<int>> ans;
    vector<int> arr;
    helper(root, arr, ans, targetSum);
    arr.clear();
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> ans;
    int target = 22;
    ans = pathSum(root, target);

    for(auto v : ans){
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}