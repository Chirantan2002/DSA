
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode *creatBST(const vector<int> &levelOrder)
{
    if (levelOrder.empty() || !levelOrder[0] == INT_MIN)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(levelOrder[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < levelOrder.size() && levelOrder[i] != INT_MIN)
        {
            curr->left = new TreeNode(levelOrder[i]);
            q.push(curr->left);
        }
        i++;

        // Right  child
        if (i < levelOrder.size() && levelOrder[i] != INT_MIN)
        {
            curr->right = new TreeNode(levelOrder[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

TreeNode *inorderSuccessor(TreeNode *root)
{
    TreeNode *succ = root->right;
    while(succ->left){
        succ = succ->left;
    }
    return succ;
}

TreeNode *inorderPredecessor(TreeNode *root)
{
    TreeNode *pred = root->left;
    while(pred->right){
        pred = pred->right;
    }
    return pred;
}

void printLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

int main()
{
    TreeNode *root = NULL;
    vector<int> levelOrder = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    root = creatBST(levelOrder);
    printLevelOrder(root);
    cout << endl;
    TreeNode *succ = inorderSuccessor(root);
    cout << succ->data;
    cout << endl;
    TreeNode *pred = inorderPredecessor(root);
    cout << pred->data;
}