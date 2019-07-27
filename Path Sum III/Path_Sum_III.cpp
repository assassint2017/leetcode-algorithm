// Runtime: 28 ms, faster than 34.92% of C++ online submissions for Path Sum III.
// Memory Usage: 14.6 MB, less than 77.45% of C++ online submissions for Path Sum III.

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
    int pathSum(TreeNode* root, int sum) 
    {
        if (root == nullptr)
            return 0;
        else
            return pathSumFromRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int pathSumFromRoot(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int temp = root->val == sum ? 1 : 0;
            return pathSumFromRoot(root->left, sum - root->val) + pathSumFromRoot(root->right, sum - root->val) + temp;
        }
    }
};