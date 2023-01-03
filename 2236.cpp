#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkTree(TreeNode *root)
{
    return root->val == (root->left->val + root->right->val);
}