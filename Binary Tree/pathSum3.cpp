#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode *root, vector<int>& currSum, int target){
    if(!root) return 0;
    currSum.push_back(root->val);
    long long sum = 0, count = 0;
    for(int i = currSum.size() - 1;i >= 0;i--){
        sum += currSum[i];
        if(sum == target) count++;
    }
    count += dfs(root->left, currSum, target);
    count += dfs(root->right, currSum, target);
    currSum.pop_back();
    return (int)count;
}

int pathSum(TreeNode *root, int targetSum){
    vector<int> currSum;
    return dfs(root, currSum, targetSum);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->right->right = new TreeNode(11);
    // root->left->left->right = new TreeNode(8);

    cout << "Ans is: " << pathSum(root, 8) << endl;
}