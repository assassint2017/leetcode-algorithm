// 多叉树的后序遍历

// 递归版本的
// Runtime: 156 ms, faster than 83.88% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 32.4 MB, less than 86.06% of C++ online submissions for N-ary Tree Postorder Traversal.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution 
{
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> res;
        
        helper(res, root);
        
        return res;
    }
private:
    void helper(vector<int>& res, Node* root)
    {
        // 边界条件处理
        if (root == nullptr)
            return ;
        
        for (auto node : root->children)
            helper(res, node);

        res.push_back(root->val);
    }
};


// 非递归版本的
// Runtime: 156 ms, faster than 83.88% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 33.1 MB, less than 41.87% of C++ online submissions for N-ary Tree Postorder Traversal.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution 
{
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> res;

        // 边界条件处理
        if (root == nullptr)
            return res;

        stack<Node*> treeStack;
        treeStack.push(root);

        while (!treeStack.empty())
        {
            root = treeStack.top();
            treeStack.pop();

            for (auto node : root->children)
                treeStack.push(node);
            
            res.push_back(root->val);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};