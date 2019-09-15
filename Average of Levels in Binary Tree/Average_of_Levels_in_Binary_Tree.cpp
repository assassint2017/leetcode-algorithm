// Runtime: 20 ms, faster than 69.74% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 21.7 MB, less than 77.78% of C++ online submissions for Average of Levels in Binary Tree.

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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> res;
        if (root == nullptr)
            return res;
        
        queue<TreeNode*> memo;
        memo.push(root);
        
        while (!memo.empty())
        {
            double size = memo.size();
            double temp = 0;
            
            for (int i = memo.size(); i > 0; --i)
            {
                root = memo.front();
                memo.pop();
                
                temp += root->val;
                
                if (root->left) memo.push(root->left);
                if (root->right) memo.push(root->right);
            }
            
            res.push_back(temp / size);
        }
        return res;
    }
};