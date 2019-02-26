// Runtime: 28 ms, faster than 72.39% of C++ online submissions for House Robber III.
// Memory Usage: 23.8 MB, less than 23.60% of C++ online submissions for House Robber III.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef unordered_map<TreeNode*, int> HashMap;
class Solution 
{
public:
    int rob(TreeNode* root) 
    {
        HashMap hashmap;
        return helper(root, hashmap);
    }
private:
    int helper(TreeNode* root, HashMap& hashmap)
    {
        if (!root)
            return 0;
        if (hashmap.find(root) == hashmap.end())
        {
            int notrobfirst = helper(root->left, hashmap) + helper(root->right, hashmap);
            
            int robfirst = root->val;
            if (root->left && root->right)
                robfirst += helper(root->left->left, hashmap) + 
                            helper(root->left->right, hashmap) +
                            helper(root->right->left, hashmap) +
                            helper(root->right->right, hashmap);

            else if (root->left)
                robfirst += helper(root->left->left, hashmap) + helper(root->left->right, hashmap);
            
            else if (root->right)
                robfirst += helper(root->right->left, hashmap) + helper(root->right->right, hashmap);
            
            hashmap.insert(make_pair(root, max(notrobfirst, robfirst)));
        }
        return hashmap.at(root);
    }
};