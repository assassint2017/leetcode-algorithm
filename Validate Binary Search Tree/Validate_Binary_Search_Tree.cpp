// 第一种思路 利用中序遍历一个二叉树，返回的结果应该是依次递增的
// 比较蠢的一种写法 需要依赖一个flag
// 12ms 32.28% 

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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int preValue;
        stack<TreeNode*> treeStack;
        bool flag = false;

        while (root || treeStack.size() > 0)
        {
            while (root)
            {
                treeStack.push(root);
                root = root->left;
            }
            if (treeStack.size() > 0)
            {
                root = treeStack.top();
                treeStack.pop();

                if (flag && root->val <= preValue)
                    return false;
                else
                {
                    preValue = root->val;
                    if (!flag)
                        flag = true;
                }
                root = root->right;
            }
        }
        return true;
    }
};

// 第二种写法
// 8ms 70.05%

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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* preValue = 0;
        stack<TreeNode*> treeStack;

        while (root || treeStack.size() > 0)
        {
            while (root)
            {
                treeStack.push(root);
                root = root->left;
            }
            if (treeStack.size() > 0)
            {
                root = treeStack.top();
                treeStack.pop();

                if (preValue && root->val <= preValue->val)
                    return false;
                else
                    preValue = root;
                root = root->right;
            }
        }
        return true;
    }
};