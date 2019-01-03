// 第一种思路 使用递归
// 8ms 34.97%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root)
            return true;
        else
            return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* left, TreeNode *right)
    {
        if (left == 0 && right == 0)
            return true;
        if (left == 0 || right == 0)
            return false;
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};