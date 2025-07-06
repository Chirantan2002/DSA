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

void inorderIterative(TreeNode *root){
    stack<TreeNode*> st;
    TreeNode *node = root;
    vector<int> ans_vector;
    while(node || !st.empty()){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            node = st.top();
            st.pop();
            ans_vector.push_back(node->val);
            node = node->right;
        }
    }
    for(auto &x : ans_vector){
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

    inorderIterative(root);
}