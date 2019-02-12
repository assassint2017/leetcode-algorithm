// 非递归版本 和上一道题相比就是加入了一点外界条件的处理
// Runtime: 44 ms, faster than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 23.9 MB, less than 0.88% of C++ online submissions for Populating Next Right Pointers in Each Node II.

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        while (true)
        {
            // 记录每一层的第一个存在子树的节点
            TreeLinkNode *leftfirstNode = 0;
            for (; root; root = root->next)
            {
                if (root->left || root->right)
                {
                    leftfirstNode = root;
                    break;
                }
            }
            if (leftfirstNode == 0) return;
            
            // 循环的完成每一层的链接
            while (true)
            {   
                // 寻找下一个可以链接的节点
                TreeLinkNode *nextNode;
                for (nextNode = root->next; nextNode; nextNode = nextNode->next)
                {
                    if (nextNode->left || nextNode->right)
                        break;
                }
                if (nextNode == 0) 
                {
                    if (root->left && root->right)
                        root->left->next = root->right;
                    break;
                }
                
                if (root->left)
                {
                    if (root->right)
                        root->left->next = root->right;
                    else
                    {
                        if (nextNode->left)
                            root->left->next = nextNode->left;
                        else
                            root->left->next = nextNode->right;
                    }
                }
                if (root->right)
                {
                    if (nextNode->left)
                        root->right->next = nextNode->left;
                    else
                        root->right->next = nextNode->right;
                }
                root = nextNode;
            }
            // 转向下一层
            root = leftfirstNode->left ? leftfirstNode->left : leftfirstNode->right;
        }    
    }
};