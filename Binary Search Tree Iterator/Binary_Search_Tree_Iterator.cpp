// LeetCode上有人分析了，这种方式其实是满足题目对于时间复杂度和空间复杂度的要求的
// Runtime: 60 ms, faster than 98.85% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.4 MB, less than 97.41% of C++ online submissions for Binary Search Tree Iterator.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator 
{
public:
    BSTIterator(TreeNode* root) 
    {
        push(root);
    }
    
    /** @return the next smallest number */
    int next() 
    {
        TreeNode* tempNode = nodeStack.top();
        nodeStack.pop();

        if (tempNode->right)
            push(tempNode->right);
        
        return tempNode->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !nodeStack.empty();
    }
private:
    stack<TreeNode*> nodeStack;

    void push(TreeNode* root)
    {
        while (root)
        {
            this->nodeStack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */