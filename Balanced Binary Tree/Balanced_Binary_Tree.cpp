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


// 第二种思路，带有剪枝的高效算法

// Runtime: 16 ms, faster than 99.77% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 17.2 MB, less than 76.41% of C++ online submissions for Balanced Binary Tree.

class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        return getDepth(root) != -1;        
    }
private:
    int getDepth(TreeNode* root)
    {
        if (root == 0)
            return 0;
        
        int left = getDepth(root->left);
        if (left == -1)
            return -1;
        int right = getDepth(root->right);
        if (right == -1)
            return -1;
        
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};
