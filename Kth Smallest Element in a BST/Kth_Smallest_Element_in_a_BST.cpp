// Runtime: 20 ms, faster than 84.89% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 21.5 MB, less than 72.76% of C++ online submissions for Kth Smallest Element in a BST.

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
    int kthSmallest(TreeNode* root, int k) 
	{
		stack<TreeNode*> treeStack;
		while (true)
		{
			while (root)
			{
				treeStack.push(root);
				root = root->left;
			}
			if (!treeStack.empty())
			{
				root = treeStack.top();
				treeStack.pop();

				if (k == 1)
					break;
				else
					--k;
				
				root = root->right;
			}
		}
		return root->val;
    }
};