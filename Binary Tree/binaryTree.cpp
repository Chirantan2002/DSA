#include <iostream>
#include <climits>
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

void displayTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    displayTree(root->left);   // Visit left subtree
    cout << root->data << " "; // Visit node
    displayTree(root->right);  // Visit right subtree
}

int nodeSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return root->data + nodeSum(root->left) + nodeSum(root->right);
}

int sizeOfTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int maxValueNode(TreeNode *root)
{
    if (!root)
        return INT_MIN;
    int leftMax = maxValueNode(root->left);
    int rightMax = maxValueNode(root->right);
    return max(root->data, max(leftMax, rightMax));
}

int minValueNode(TreeNode *root)
{
    if (!root)
        return INT_MAX;
    int leftMin = minValueNode(root->left);
    int rightMin = minValueNode(root->right);
    return min(root->data, min(leftMin, rightMin));
}

int productOfNodes(TreeNode *root)
{
    if (!root)
        return 1;
    return root->data * productOfNodes(root->left) * productOfNodes(root->right);
}

int levelsInTree(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(levelsInTree(root->left), levelsInTree(root->right));
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
    displayTree(root);
    cout << endl;
    cout << "Sum of all nodes: " << nodeSum(root) << endl;
    cout << "Size of the tree: " << sizeOfTree(root) << endl;
    cout << "Maximum value in the tree: " << maxValueNode(root) << endl;
    cout << "Minimum value in the tree: " << minValueNode(root) << endl;
    cout << "Product of all nodes: " << productOfNodes(root) << endl;
    cout << "Levels in the Tree: " << levelsInTree(root) << endl;
    cout << "Height of the Tree: " << (levelsInTree(root) - 1) << endl;
    vector<string> paths = binaryTreePaths(root);
    cout << "Paths in the Tree: " << endl;
    for (int i = 0; i < paths.size(); i++)
        cout << paths[i] << endl;
    return 0;
}