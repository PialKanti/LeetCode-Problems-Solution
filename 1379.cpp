#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    if (cloned == NULL)
        return cloned;

    if (cloned->val == target->val)
        return cloned;

    TreeNode *leftResult = getTargetCopy(original, cloned->left, target);
    TreeNode *rightResult = getTargetCopy(original, cloned->right, target);

    if (leftResult)
    {
        return leftResult;
    }
    else if (rightResult)
    {
        return rightResult;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    return 0;
}