// 二叉树的后序遍历

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Binary Tree Paths.

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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        vector<int> vec;
        vector<vector<int>> resint;

        stack<TreeNode*> myStack;
        TreeNode* preNode = nullptr;

        while (root || !myStack.empty())
        {
            while (root)
            {
                myStack.push(root);
                vec.push_back(root->val);
                root = root->left;
            }
            if (!myStack.empty())
            {
                root = myStack.top();
                myStack.pop();

                if (root->right == nullptr || root->right == preNode)
                {
                    if (root->left == nullptr && root->right == nullptr)
                        resint.push_back(vec);
                    vec.pop_back();

                    preNode = root;
                    root = nullptr;
                }
                else
                {
                    myStack.push(root);
                    root = root->right;
                }
            }
        }

        toString(resint, res);
        return res
    }
private:

    // 将路径转换为对应的字符串
    void toString(vector<vector<int>>& resint, vector<string>& res)
    {
        stringstream ss;
        for (int i = 0; i < resint.size(); i++)
        {
            string str = "";
            for (int j = 0; j < resint[i].size() - 1; j++)
            {
                ss.clear();
                string temp;
                ss << resint[i][j];
                ss >> temp;
                str += temp;
                str += "->";
            }
            
            ss.clear();
            string temp;
            ss << resint[i].back();
            ss >> temp;
            str += temp;

            res.push_back(str);
        }
    }
};