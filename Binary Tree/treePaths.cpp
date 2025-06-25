#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void Inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    Inorder(root->left);   // Visit left subtree
    cout << root->data << " "; // Visit node
    Inorder(root->right);  // Visit right subtree
}

void Preorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " "; // Visit node
    Preorder(root->left);   // Visit left subtree
    Preorder(root->right);  // Visit right subtree
}

void Postorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    Postorder(root->left);   // Visit left subtree
    Postorder(root->right);  // Visit right subtree
    cout << root->data << " "; // Visit node
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    if (!root)
        return ans;
    if (!root->left && !root->right)
    {
        ans.push_back(to_string(root->data));
        return ans;
    }
    vector<string> left = binaryTreePaths(root->left);
    vector<string> right = binaryTreePaths(root->right);
    for (int i = 0; i < left.size(); i++)
        ans.push_back(to_string(root->data) + "->" + left[i]);
    for (int i = 0; i < right.size(); i++)
        ans.push_back(to_string(root->data) + "->" + right[i]);
    return ans;
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
    root->left->left->left = new TreeNode(8);
    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;
    vector<string> paths = binaryTreePaths(root);
    cout << "Paths in the Tree: " << endl;
    for (int i = 0; i < paths.size(); i++)
        cout << paths[i] << endl;
    return 0;
}