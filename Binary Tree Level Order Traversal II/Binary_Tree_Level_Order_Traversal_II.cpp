// 和102思路一致 区别在于使用堆栈来存储
// 4ms 99.02%

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
#include<stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> values;
        if (!root)return values;

        stack<vector<int>> valueStack;

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
            valueStack.push(tempVec);
        }

        while (!valueStack.empty())
        {
            values.push_back(valueStack.top());
            valueStack.pop();
        }

        // 或者使用下边的一句话结束
        // reverse(values.begin(), values.end());
        return values;
    }
};