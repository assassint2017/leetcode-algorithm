// 8ms 100%

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
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> paths;
        vector<int> path;
        stack<TreeNode*> treeStack;
        TreeNode *lastNode = 0;
        int temp = 0;

        while (root || !treeStack.empty())
        {
            while (root)
            {
                temp += root->val;  
                path.push_back(root->val);

                if (!root->left && !root->right)
                {
                    if (temp == sum)
                        paths.push_back(path);
                }
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
                    path.pop_back();

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
        return paths;
    }
};