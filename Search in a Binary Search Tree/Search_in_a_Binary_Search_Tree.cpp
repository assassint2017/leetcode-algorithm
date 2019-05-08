// Runtime: 60 ms, faster than 90.80% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 29.2 MB, less than 92.83% of C++ online submissions for Search in a Binary Search Tree.

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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        while (root)
        {
            if (root->val == val)
                break;
            else if (root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};