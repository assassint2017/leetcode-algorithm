// 第一种思路 判定一个节点是否平衡的时候不仅需要平衡因子的绝对值小于1，还需要左子树和右子树同样为平衡树
// 8ms 67.06%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<cmath>

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if (!root) 
            return true;
        else
            return abs(maxDepth(root->right) - maxDepth(root->left)) <= 1 
                    && isBalanced(root->left) 
                    && isBalanced(root->right);
    }

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        else
        {
            int depthLeft = maxDepth(root->left);
            int depthRight = maxDepth(root->right);

            return depthLeft > depthRight ? depthLeft + 1 : depthRight + 1;
        }
    }
};