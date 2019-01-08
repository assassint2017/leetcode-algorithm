// 和上一道题目的解题思路是一样的
// 16ms 54.05%

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

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return helper(0, postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder);
    }

    TreeNode* helper(int postLeft, int postRight, int inLeft, int inRight, vector<int>& postorder, vector<int>& inorder)
    {   
        if (postLeft > postRight)
            return 0;
        else if (postLeft == postRight)
            return new TreeNode(postorder[postLeft]);
        else
        {
            int rootValue = postorder[postRight];
        
            vector<int>::iterator iter = find(inorder.begin() + inLeft, inorder.begin() + inRight + 1, rootValue);
            int rootIndex = iter - inorder.begin();

            TreeNode *root = new TreeNode(rootValue);
            root->left = helper(postLeft, postLeft + rootIndex - inLeft - 1, inLeft, rootIndex - 1, postorder, inorder);
            root->right = helper(postLeft + rootIndex - inLeft, postRight - 1, rootIndex + 1, inRight, postorder, inorder);

            return root;
        }
    }
};