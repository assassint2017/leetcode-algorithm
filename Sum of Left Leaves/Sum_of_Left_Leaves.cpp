// 4ms 99.50%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
using namespace std;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if (!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0;

        while (!q.empty())
        {
            root = q.front();
            q.pop();

            if (root->left && !root->left->left && !root->left->right)
                sum += root->left->val;
            if (root->left)q.push(root->left);
            if (root->right)q.push(root->right);
        }
        return sum;
    }
};