// Runtime: 4 ms, faster than 61.67% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.

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
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<int> nums;
        
        inOrderTraversal(root, nums);
        
        unordered_map<int, int> hashmap;
        int temp = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            temp += nums[i];
            hashmap.insert(make_pair(nums[i], temp));
        }
        
        inOrderModify(root, hashmap);
        return root;
    }
private:
    void inOrderTraversal(TreeNode* root, vector<int>& nums)
    {
        stack<TreeNode*> memo;
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
                
                nums.push_back(root->val);
                
                root = root->right;
            }
        }
    }
    
    void inOrderModify(TreeNode* root, unordered_map<int, int>& hashmap)
    {
        stack<TreeNode*> memo;
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
                
                root->val = hashmap.at(root->val);
                
                root = root->right;
            }
        }
    }
};