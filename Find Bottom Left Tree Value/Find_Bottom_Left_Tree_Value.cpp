// 基本思路 二叉树的广度优先搜索
// Runtime: 20 ms, faster than 99.31% of C++ online submissions for Find Bottom Left Tree Value.
// Memory Usage: 20.9 MB, less than 100.00% of C++ online submissions for Find Bottom Left Tree Value.

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
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);

        int res = root->val;
        while (!q.empty())
        {
            int size = q.size() - 1;
            root = q.front();
            q.pop();

            res = root->val;

            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);

            for (; size > 0; size--)
            {
                root = q.front();
                q.pop();

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};