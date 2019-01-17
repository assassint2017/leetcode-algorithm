// 使用广度优先搜索返回每一层中最后的一个节点的值
// ms %

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
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> values;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        if (!root)
            return values;

        while (!treeQueue.empty())
        {
            int size = treeQueue.size();
            while (--size >= 1)
            {
                root = treeQueue.front();
                treeQueue.pop();

                if (root->left) treeQueue.push(root->left);
                if (root->right) treeQueue.push(root->right);
            }

            root = treeQueue.front();
            treeQueue.pop();

            values.push_back(root->val);

            if (root->left) treeQueue.push(root->left);
            if (root->right) treeQueue.push(root->right);
        }
        return values;
    }
};