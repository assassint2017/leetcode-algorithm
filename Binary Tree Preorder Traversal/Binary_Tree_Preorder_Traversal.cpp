// 递归的过于简单了，这里就直接使用堆栈来做了
// 0ms 100%

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
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> treeStack;
        if (!root)        
            return values;
        
        while (root || !treeStack.empty())
        {
            while (root)
            {
                values.push_back(root->val);
                treeStack.push(root);
                root = root->left;
            }

            if (!treeStack.empty())
            {
                root = treeStack.top();
                treeStack.pop();

                root = root->right;
            }
        }
        return values;
    }
};