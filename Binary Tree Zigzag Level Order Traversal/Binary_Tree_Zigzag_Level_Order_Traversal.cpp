// 4ms 63.18%

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> values;
        if (!root)return values;

        queue<TreeNode*> treeQueue;
        treeQueue.push(root);

        bool leftToRight = true;
        
        while (!treeQueue.empty())
        {
            int size = treeQueue.size();
            vector<int> tempVec;
            if (!leftToRight)
                tempVec.resize(size);

            while (size--)
            {
                TreeNode *tempNode = treeQueue.front();
                treeQueue.pop();

                if (leftToRight)
                    tempVec.push_back(tempNode->val);
                else
                    tempVec[size] = tempNode->val;

                if (tempNode->left)
                    treeQueue.push(tempNode->left);
                if (tempNode->right)
                    treeQueue.push(tempNode->right);
            }
            values.push_back(tempVec);
            leftToRight = !leftToRight;
        }
        return values;
    }
};