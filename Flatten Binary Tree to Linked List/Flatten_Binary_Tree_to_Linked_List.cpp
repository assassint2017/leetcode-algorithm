// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 11 MB, less than 0.99% of C++ online submissions for Flatten Binary Tree to Linked List.

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
    void flatten(TreeNode* root) 
    {
        helper(root);
    }
private:
    TreeNode* helper(TreeNode *root)
    {
        if (root == 0 || (root->left == 0 && root->right == 0))
            return root;

        TreeNode *leftlastNode = helper(root->left);
        TreeNode *rightlastNode = helper(root->right);

        if (leftlastNode)
        {
            TreeNode *rightNode = root->right;
            root->right = root->left;
            root->left = 0;
            leftlastNode->right = rightNode;
        }

        if (rightlastNode == 0)
            return leftlastNode;
        else
            return rightlastNode;
    }
};

// 非递归版本的
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 11 MB, less than 0.99% of C++ online submissions for Flatten Binary Tree to Linked List.
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        while (root)
        {
            if (root->left && root->right)
            {
                TreeNode *temp = root->left;
                while (temp->right)
                    temp = temp->right;
                temp->right = root->right;
            }

            if (root->left)
                root->right = root->left;
            
            root->left = 0;
            root = root->right;
        }
    }
};