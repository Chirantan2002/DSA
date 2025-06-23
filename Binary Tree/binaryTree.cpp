#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void displayTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    displayTree(root->left);   // Visit left subtree
    cout << root->data << " "; // Visit node
    displayTree(root->right);  // Visit right subtree
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    displayTree(root);
}