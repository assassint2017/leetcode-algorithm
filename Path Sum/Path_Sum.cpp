// 第一种思路 使用递归
// 8ms 57.10%

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
    bool hasPathSum(TreeNode* root, int sum) {
        
        // 如果是空树，则直接返回
        if (root == 0)
            return false;

        // 如果查询到了叶子节点
        if (root->left == 0 && root->right == 0)
        {
            if (sum == root->val)
                return true;
            else
                return false;
        }
            
       return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};