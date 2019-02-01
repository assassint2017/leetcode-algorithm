// 思路一，使用二叉树的中序遍历，空间复杂度为on
// 24ms 98.68%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void recoverTree(TreeNode* root) 
    {    
        stack<TreeNode*> treeStack;
        vector<TreeNode*> vec;
        TreeNode *preNode = 0;
        
        while (root || !treeStack.empty())
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

                if (preNode && preNode->val > root->val)
                {
                    vec.push_back(preNode);
                    vec.push_back(root);
                }
                preNode = root;
                root = root->right;
            }
        }
        int temp = vec[0]->val;
        vec[0]->val = vec[vec.size() - 1]->val;
        vec[vec.size() - 1]->val = temp;
    }
};

// 思路二 二叉树的莫尔斯遍历 空间复杂度为o1
// ms %
class Solution {
public:
    void recoverTree(TreeNode* root) 
    {
        // 当前节点、前序节点、上一个输出的节点
        TreeNode *curNode = root, *preNode = 0, *lastNode = 0;    
        vector<TreeNode*> vec;

        while (curNode)
        {
            if (curNode->left == 0)
            {
                if (lastNode && lastNode->val > curNode->val)
                {
                    vec.push_back(lastNode);
                    vec.push_back(curNode);
                }
                lastNode = curNode;
                curNode = curNode->right;
            }
            else
            {
                // 寻找前序节点
                preNode = curNode->left;
                while (preNode->right && preNode->right != curNode)
                    preNode = preNode->right;

                // 找到前序节点后进行判断
                if (preNode->right == 0)
                {
                    preNode->right = curNode;
                    curNode = curNode->left;
                }
                else
                {
                    preNode->right = 0;
                    if (preNode->val > curNode->val)
                    {
                        vec.push_back(preNode);
                        vec.push_back(curNode);
                    }
                    lastNode = curNode;
                    curNode = curNode->right;
                }
            }
        }

        // 交换
        int temp = vec[0]->val;
        vec[0]->val = vec[vec.size() - 1]->val;
        vec[vec.size() - 1]->val = temp;
    }
};