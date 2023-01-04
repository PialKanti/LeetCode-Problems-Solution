#include <iostream>
#include <vector>
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

TreeNode *construct(vector<int> nums, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }

    int maxIndex = l;
    for (int i = l; i <= r; i++)
    {
        if (nums[i] > nums[maxIndex])
        {
            maxIndex = i;
        }
    }

    TreeNode *parent = new TreeNode(nums[maxIndex]);
    parent->left = construct(nums, l, maxIndex - 1);
    parent->right = construct(nums, maxIndex + 1, r);

    return parent;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return construct(nums, 0, nums.size() - 1);
}