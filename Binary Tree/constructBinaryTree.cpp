#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* construct(int arr[], int n){ // constructing the tree
    queue<TreeNode*> q;
    TreeNode *root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1, j = 2;
    while(!q.empty() && i < n){
        TreeNode *node = q.front();
        q.pop();
        TreeNode *l, *r;
        if(arr[i] != INT_MIN) l = new TreeNode(arr[i]);
        else l = nullptr;
        if(j != n && arr[j] != INT_MIN) r = new TreeNode(arr[j]);
        else r = nullptr;
        node->left = l;
        node->right = r;
        if(l) q.push(l);
        if(r) q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}

void BFS(TreeNode *root){ // BFS -> very very important!
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    // construct a tree
    int arr[] = {1,2,3,4,5,6,INT_MIN,7,INT_MIN,INT_MIN,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = construct(arr, n);
    // print it level by level
    BFS(root);
}