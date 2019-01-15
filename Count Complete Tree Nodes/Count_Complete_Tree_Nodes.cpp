// 高票的java解决方案 由于每次处理一个子树，因此大神分析说是logn的速度
// 16ms 99.34%

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
    int countNodes(TreeNode* root) 
    {   
        if (!root)
            return 0;
        
        int leftMaxHeight = 0;
        TreeNode *temp = root->left;
        while (temp)
        {
            temp = temp->left;
            leftMaxHeight++;
        }

        int rightMaxHeight = 0;
        temp = root->right;
        while (temp)
        {
            temp = temp->left;
            rightMaxHeight++;
        }

        if (leftMaxHeight == rightMaxHeight)
            return countNodes(root->right) + (1 << leftMaxHeight);
        else 
            return countNodes(root->left) + (1 << rightMaxHeight);
    }
};