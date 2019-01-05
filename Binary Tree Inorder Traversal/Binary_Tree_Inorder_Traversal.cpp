// 第一种思路 使用递归
// 4ms 6.20%

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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        traversal(root);
        return values;
    }

    void traversal(TreeNode *root)
    {
        if (!root)
            return;
        else
        {
            traversal(root->left);
            values.push_back(root->val);
            traversal(root->right);
        }
    }
private:
    vector<int> values;
};

// 第二种思路 换一种写法
// 0ms 100%

#include<vector>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> values;
        traversal(root, values);
        return values;
    }

    void traversal(TreeNode *root, vector<int> &values)
    {
        if (!root)
            return;
        else
        {
            if (root->left)
                traversal(root->left, values);
            values.push_back(root->val);
            if (root->right)
                traversal(root->right, values);
        }
    }
};

// 第二种思路 使用堆栈代替递归
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> treeStack;
        TreeNode *temp = root;

        while (temp || treeStack.size() > 0)
        {
            while (temp)
            {
                treeStack.push(temp);
                temp = temp->left;
            }
            if (treeStack.size() > 0)
            {
                temp = treeStack.top();
                treeStack.pop();
                values.push_back(temp->val);
                temp = temp->right;
            }
        }
        return values;
    }
};