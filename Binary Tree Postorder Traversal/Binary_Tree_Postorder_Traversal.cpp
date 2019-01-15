// 树的三种序的遍历 后序的非递归形式是最难的
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> treeStack;
        TreeNode *preNode = 0;
        
        if (!root)
            return values;
        
        while(root || !treeStack.empty())
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

                if (root->right == 0 || root->right == preNode)
                {
                    values.push_back(root->val);
                    preNode = root;
                    root = 0;
                }
                else
                {
                    treeStack.push(root);
                    root = root->right;
                }
            }
        }
        return values;
    }
};