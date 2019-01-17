// 0ms 100%
// 使用后序遍历，并利用一个变量去追踪sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<stack>
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> treeStack;
        TreeNode *lastNode = 0;
        int sum = 0, temp = 0;

        while (root || !treeStack.empty())
        {
            while (root)
            {
                temp *= 10;
                temp += root->val;

                if (!root->left && !root->right)
                    sum += temp;   
                treeStack.push(root);
                
                root = root->left;
            }
            if (!treeStack.empty())
            {
                root = treeStack.top();
                treeStack.pop();
                
                if (!root->right || root->right == lastNode)
                {
                    temp -= root->val;
                    temp /= 10;
                    lastNode = root;
                    root = 0;
                }
                else
                {
                    treeStack.push(root);
                    root = root->right;    
                }
            }
        }
        return sum;
    }
};