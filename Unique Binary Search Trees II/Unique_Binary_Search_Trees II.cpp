// 16ms %

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
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1)
        {
            vector<TreeNode*> temp;
            return temp;
        }
        else
            return helper(1, n);
    }

    vector<TreeNode*> helper(int left, int right)
    {
        vector<TreeNode*> vec;
        if (left > right)
            vec.push_back(0);
        else if (left == right)
            vec.push_back(new TreeNode(left));
        else
        {
            for (int i = left; i <= right; i++)
            {
                vector<TreeNode*> leftTree = helper(left, i - 1);
                vector<TreeNode*> rightTree = helper(i + 1, right);
                
                for (vector<TreeNode*>::iterator leftIter = leftTree.begin(); leftIter != leftTree.end(); leftIter++)
                {
                    for (vector<TreeNode*>::iterator rightIter = rightTree.begin(); rightIter != rightTree.end(); rightIter++)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = *leftIter;
                        root->right = *rightIter;

                        vec.push_back(root);
                    }
                }
            }
        }
        return vec;
    }
};