// 可以将问题转换为两个链表求交点的问题
// Runtime: 16 ms, faster than 98.40% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 18.5 MB, less than 22.36% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr)
            return root;

        vector<TreeNode*> path1, path2;

        path1.push_back(p);
        path2.push_back(q);

        get_path(root, p, path1);
        get_path(root, q, path2);

        return find_ancestor(path1, path2);
    }
private:

    // 获取从根节点到目标节点的路径
    // 基于二叉树的后序遍历
    void get_path(TreeNode* root, TreeNode* target, vector<TreeNode*>& path)
    {
        stack<TreeNode*> treeStack;
        TreeNode* preNode = nullptr;

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

                if (root->right == nullptr || root->right == preNode)
                {
                    if (root->left == target || root->right == target)
                    {
                        path.push_back(root);
                        target = root;
                        while (!treeStack.empty())
                        {
                            root = treeStack.top();
                            treeStack.pop();

                            if (root->left == target || root->right == target)
                            {
                                path.push_back(root);
                                target = root;
                            }
                        }
                        break;
                    }
                        
                    preNode = root;
                    root = nullptr;
                }
                else
                {
                    treeStack.push(root);
                    root = root->right;
                }
            }
        }
    }

    // 根据两条路径，获取最后一个相同的节点
    TreeNode* find_ancestor(vector<TreeNode*>& path1, vector<TreeNode*>& path2)
    {
        vector<TreeNode*>::iterator iter1 = path1.end() - 1;
        vector<TreeNode*>::iterator iter2 = path2.end() - 1;

        while (true)
        {
            if (iter1 == path1.begin() || iter2 == path2.begin() || (*(iter1 - 1) != *(iter2 - 1)))
                break;
            else
                iter1--, iter2--;
        }

        return *iter1;
    }
};

// 另外一种写法
// Runtime: 24 ms, faster than 43.62% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 18.2 MB, less than 18.89% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // 边界条件处理
        if (root == nullptr || q == nullptr || p == nullptr)
            return nullptr;
        
        vector<TreeNode*> path1, path2;
        getPath(path1, root, p);
        getPath(path2, root, q);
        
        return find(path1, path2);
    }
private:
    void getPath(vector<TreeNode*>& path, TreeNode* root, TreeNode* target)
    {
        path.push_back(root);
        
        TreeNode* preNode = nullptr;
        stack<TreeNode*> treeStack;
        
        while (root || !treeStack.empty())
        {
            while (root)
            {
                path.push_back(root);
                treeStack.push(root);
                root = root->left;
            }
            if (!treeStack.empty())
            {
                root = treeStack.top();
                treeStack.pop();
                
                if (root->right == nullptr || root->right == preNode)
                {
                    if (root == target)
                        return ;
                    path.pop_back();
                    preNode = root;
                    root = nullptr;
                }
                else
                {
                    treeStack.push(root);
                    root = root->right;
                }
            }
        }
    }
    
    TreeNode* find(vector<TreeNode*>& path1, vector<TreeNode*>& path2)
    {
        TreeNode* res = path1.front();
        for (int i = 0; i < path1.size() && i < path2.size(); )
        {
            if (i + 1 < path1.size() && i + 1 < path2.size() && path1[i + 1] == path2[i + 1])
                ++i, res = path1[i];
            else
                break;
        }
        return res;
    }
};
