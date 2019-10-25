// Runtime: 24 ms, faster than 7.50% of C++ online submissions for Smallest String Starting From Leaf.
// Memory Usage: 19.6 MB, less than 91.30% of C++ online submissions for Smallest String Starting From Leaf.

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
    string smallestFromLeaf(TreeNode* root) 
    {    
        string curString = "", minString = "";
        
        TreeNode* preNode = nullptr;
        stack<TreeNode*> memo;
        
        while (root || !memo.empty())
        {
            while (root)
            {
                curString += root->val + 'a';

                memo.push(root);
                root = root->left;
            }
            if (!memo.empty())
            {
                root = memo.top();
                memo.pop();
                
                if (root->right == nullptr || root->right == preNode)
                {
                    if (root->left == nullptr && root->right == nullptr)
                    {   
                        if (minString.length() == 0 || smaller(curString, minString))
                        {
                            minString = curString;
                        }
                    }
                    
                    curString.pop_back();

                    preNode = root;
                    root = nullptr;
                }
                else
                {
                    memo.push(root);
                    root = root->right;
                }
            }
        }

        reverse(minString.begin(), minString.end());
        return minString;
    }
private: 
    bool smaller(const string& str1, const string& str2)
    {
        int ptr1 = str1.length() - 1;
        int ptr2 = str2.length() - 1;

        while (ptr1 >= 0 && ptr2 >= 0)
        {
            if (str1[ptr1] < str2[ptr2])
            {
                return true;
            }
            else if (str1[ptr1] > str2[ptr2])
            {
                return false;
            }
            else
            {
                --ptr1;
                --ptr2;
            }
        }

        return ptr1 >= 0 ? false : true;
    }
};