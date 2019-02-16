// Runtime: 40 ms, faster than 100.00% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 25.4 MB, less than 100.00% of C++ online submissions for Binary Tree Maximum Path Sum.

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
    int maxPathSum(TreeNode* root) 
    {
        this->res = INT_MIN;
        helper(root);
        return this->res;
    }

private:
    int res;

    int helper(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftmax = max(0, helper(root->left));
        int rightmax = max(0, helper(root->right));

        this->res = max(this->res, leftmax + rightmax + root->val);

        return max(leftmax, rightmax) + root->val;
    }
};