// 第一种思路 使用层次遍历依次比较各个节点
// 4ms 32.81%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue1;
        queue<TreeNode*> queue2;

        queue1.push(p);
        queue2.push(q);

        while (queue1.size() > 0 && queue2.size() > 0)
        {
            TreeNode *itemP = queue1.front();
            TreeNode *itemQ = queue2.front();

            queue1.pop();
            queue2.pop();

            if (itemP == 0 || itemQ == 0)
            {
                if (!(itemP == 0 && itemQ == 0))
                    return false;
            }
            else if (!(itemP->val == itemQ->val))
                return false;
            else   
            {
                queue1.push(itemP->left);
                queue1.push(itemP->right);

                queue2.push(itemQ->left);
                queue2.push(itemQ->right);
            }
        }

        // 当循环退出的时候，只有两个队列都为空的时候两棵树才是完全相等的
        if (queue1.size() == 0 && queue2.size() == 0)
            return true;
        else
            return false;
    }
};

// 第二种思路，使用简单的递归
// Runtime: 8 ms, faster than 40.17% of C++ online submissions for Same Tree.
// Memory Usage: 9.7 MB, less than 99.72% of C++ online submissions for Same Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (p == nullptr || q == nullptr)
            return q == p;
        else
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
