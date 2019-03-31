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

// 典型的使用bfs来进行查找\
// Runtime: 16 ms, faster than 99.26% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 19.4 MB, less than 96.36% of C++ online submissions for Minimum Depth of Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        if (!root)
            return 0;
        
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        int layer = 1;
        while (!treeQueue.empty())
        {
            for (int i = treeQueue.size(); i > 0; i--)
            {
                root = treeQueue.front();
                treeQueue.pop();

                if(root->left == nullptr && root->right == nullptr)
                    return layer;
                
                if (root->left) treeQueue.push(root->left);
                if (root->right) treeQueue.push(root->right);
            }
            layer++;
        }
        
        // 这里如果不加的话，编译可能会出现问题，因为可能会出现没有返回值的情况
        return layer;
    }
};
