#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;

    int heightDiff = abs(height(root->left) - height(root->right));

    return heightDiff <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int height(TreeNode *root)
{
    if (!root)
        return 1;

    return max(height(root->left), height(root->right)) + 1;
}