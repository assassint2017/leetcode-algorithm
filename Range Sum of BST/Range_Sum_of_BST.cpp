// 使用二叉树中序遍历的解法

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
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        stack<TreeNode*> memo;
        int res = 0;
        while (root || !memo.empty())
        {
            while (root)
            {
                memo.push(root);
                root = root->left;
            }
            if (!memo.empty())
            {
                root = memo.top();
                memo.pop();
                
                if (root->val >= L && root->val <= R)
                    res += root->val;
                
                root = root->right;
            }
        }
        
        return res;
    }
};


// 第二种做法 使用递归
// Runtime: 144 ms, faster than 84.60% of C++ online submissions for Range Sum of BST.
// Memory Usage: 41.2 MB, less than 80.00% of C++ online submissions for Range Sum of BST.

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
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if (root == nullptr || L > R)
            return 0;
        else if (L == R && L == root->val)
            return root->val;
        else if (L > root->val)
            return rangeSumBST(root->right, L, R);
        else if (root->val > R)
            return rangeSumBST(root->left, L, R);
        else
            return rangeSumBST(root->left, L, root->val - 1) + rangeSumBST(root->right, root->val + 1, R) + root->val;
    }
};