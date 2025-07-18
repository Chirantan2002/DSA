#include <iostream>
#include <stack>
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

void postorderIterative(TreeNode *root){
    stack<TreeNode*> st;
    st.push(root);
    vector<int> temp;
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        temp.push_back(node->val);
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    reverse(begin(temp), end(temp));
    for(auto &x : temp){
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    postorderIterative(root);
}