// 16ms 57.59%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       return helper(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* helper(int preLeft, int preRight, int inLeft, int inRight, vector<int>& preorder, vector<int>& inorder)
    {   
        if (preLeft > preRight)
            return 0;
        else if (preLeft == preRight)
            return new TreeNode(preorder[preLeft]);
        else
        {
            int rootValue = preorder[preLeft];
        
            vector<int>::iterator iter = find(inorder.begin() + inLeft, inorder.begin() + inRight + 1, rootValue);
            int rootIndex = iter - inorder.begin();

            TreeNode *root = new TreeNode(rootValue);
            root->left = helper(preLeft + 1, preLeft + rootIndex - inLeft, inLeft, rootIndex - 1, preorder, inorder);
            root->right = helper(preLeft + rootIndex - inLeft + 1, preRight, rootIndex + 1, inRight, preorder, inorder);

            return root;
        }
    }
};