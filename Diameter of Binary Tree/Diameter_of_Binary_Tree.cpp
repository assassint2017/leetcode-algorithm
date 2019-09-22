// 第一种方案，使用简单递归进行处理，虽然过了，但是明显很慢，加入备忘录之后提升也不是很明显

// Runtime: 56 ms, faster than 8.09% of C++ online submissions for Diameter of Binary Tree.
// Memory Usage: 35.5 MB, less than 7.41% of C++ online submissions for Diameter of Binary Tree.

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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        
        int a = getDepth(root->left) + getDepth(root->right);
        int b = diameterOfBinaryTree(root->left);
        int c = diameterOfBinaryTree(root->right);
        
        return max(a, max(b, c));
    }
private:
    unordered_map<TreeNode*, int> hashmap;

    int getDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        if (hashmap.find(root) == hashmap.end())
        {
            int left = getDepth(root->left);
            int right = getDepth(root->right);

            hashmap.insert(root, max(left, right) + 1);
        }
        return hashmap.at(root);
    }
};

// 第2种方案，速度提升还是非常明显的
// Runtime: 12 ms, faster than 68.92% of C++ online submissions for Diameter of Binary Tree.
// Memory Usage: 19.6 MB, less than 92.59% of C++ online submissions for Diameter of Binary Tree.

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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        getDepth(root);
        return res;
    }
private:
    int res = 0;

    int getDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);

        res = max(res, left + right);

        return max(left, right) + 1;
    }
};