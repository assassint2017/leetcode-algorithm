// 第一种思路 二叉树的最小高度等于 左右子树的最小高度+1 但是要注意多一个判断条件
// 8ms 53.51%

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
    int minDepth(TreeNode* root) {
        
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        
        int depthLeft = minDepth(root->left);
        int depthRight = minDepth(root->right);
        
        if (!depthLeft)
            return depthRight + 1;
        else if (!depthRight)
            return depthLeft + 1;
        else
            return depthLeft < depthRight ? depthLeft + 1: depthRight + 1;
    }
};