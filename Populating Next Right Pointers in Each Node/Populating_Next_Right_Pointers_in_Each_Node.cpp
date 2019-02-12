// Runtime: 32 ms, faster than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 20.8 MB, less than 0.99% of C++ online submissions for Populating Next Right Pointers in Each Node.

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
        if (root == 0 || (root->left == 0 && root->right == 0))
            return;
        
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);    
    }
};

// 非递归版本的
// Runtime: 36 ms, faster than 52.86% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 20.7 MB, less than 0.99% of C++ online submissions for Populating Next Right Pointers in Each Node.
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if (root == 0)
            return;

        while (root->left)
        {
            // 记录每一层的第一个节点
            TreeLinkNode *leftfirstNode = root;
            
            // 循环的完全每一层的链接
            while (root->next)
            {
                root->left->next = root->right;
                root->right->next = root->next->left;
                root = root->next;
            }
            
            root->left->next = root->right;
            
            // 转向下一层
            root = leftfirstNode->left;
        }
    }
};