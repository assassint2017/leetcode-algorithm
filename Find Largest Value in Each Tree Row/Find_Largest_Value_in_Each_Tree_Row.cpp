// Runtime: 8 ms, faster than 99.63% of C++ online submissions for Find Largest Value in Each Tree Row.
// Memory Usage: 20.8 MB, less than 97.97% of C++ online submissions for Find Largest Value in Each Tree Row.

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
    vector<int> largestValues(TreeNode* root) 
    {
        // 边界条件处理
        if (root == nullptr)
            return vector<int>();
        
        vector<int> res;

        queue<TreeNode*> memo;
        memo.push(root);

        while (!memo.empty())
        {
            int max = INT_MIN;
            for (int i = memo.size(); i > 0; --i)
            {
                root = memo.front();
                memo.pop();

                max = root->val > max ? root->val : max;

                if (root->left) memo.push(root->left);
                if (root->right) memo.push(root->right);
            }
            res.push_back(max);
        }
        return res;
    }
};