// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Leaf-Similar Trees.
// Memory Usage: 13.3 MB, less than 88.89% of C++ online submissions for Leaf-Similar Trees.

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leaf1;
        vector<int> leaf2;

        traversal(leaf1, root1);
        traversal(leaf2, root2);

        if (leaf1.size() != leaf2.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < leaf1.size(); ++i)
            {
                if (leaf1[i] != leaf2[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
private:
    void traversal(vector<int>& res, TreeNode* root)
    {
        stack<TreeNode*> memo;

        while (!memo.empty() || root)
        {
            while (root)
            {
                if (root->left == nullptr && root->right == nullptr)
                {
                    res.push_back(root->val);
                }
                memo.push(root);
                root = root->left;
            }
            if (!memo.empty())
            {
                root = memo.top();
                memo.pop();

                root = root->right;
            }
        }
    }
};