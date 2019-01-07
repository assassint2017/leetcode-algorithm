// 思路一 层次遍历 使用指针来记录每一层中最后的节点
// 4ms 99.06%

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
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> values;
        if (!root)
            return values;

        queue<TreeNode*> treeQueue;

        treeQueue.push(root);
        TreeNode *endOfLevel = root;
        
        while (!treeQueue.empty())
        {
            vector<int> tempVec;
            TreeNode *nextEndOflevel = 0;

            while (true)
            {
                TreeNode *tempNode = treeQueue.front();
                treeQueue.pop();

                tempVec.push_back(tempNode->val);

                if (tempNode->left)
                {
                    treeQueue.push(tempNode->left);
                    nextEndOflevel = tempNode->left;
                }
                if (tempNode->right)
                {
                    treeQueue.push(tempNode->right);
                    nextEndOflevel = tempNode->right;
                }
                
                if (tempNode == endOfLevel)
                {
                    endOfLevel = nextEndOflevel;
                    break;
                }
            }
            values.push_back(tempVec);
        }
        return values;
    }
};

// 思路二 记住每一层的节点的个数
// 4ms 99.06%

#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> values;
        if (!root)return values;

        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        while (!treeQueue.empty())
        {
            vector<int> tempVec;
            int size = treeQueue.size();

            while (size--)
            {
                TreeNode *tempNode = treeQueue.front();
                treeQueue.pop();

                tempVec.push_back(tempNode->val);

                if (tempNode->left)
                    treeQueue.push(tempNode->left);
                if (tempNode->right)
                    treeQueue.push(tempNode->right);
                
            }
            values.push_back(tempVec);
        }
        return values;
    }
};
