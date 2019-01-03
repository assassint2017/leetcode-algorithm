// 思路一 二叉树的高度等于 max(depth(左子树), depth(右子树)) + 1 利用递归求解
// 4ms 98.96%

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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return 1;
        else
        {
            int depthLeft = maxDepth(root->left); 
            int depthRight = maxDepth(root->right);
            return depthLeft > depthRight ? depthLeft + 1 : depthRight + 1;
        }
    }
};