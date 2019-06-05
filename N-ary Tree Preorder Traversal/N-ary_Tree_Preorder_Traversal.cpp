// 和590多叉树的后序遍历可以看成是一类题目
// Runtime: 152 ms, faster than 88.63% of C++ online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 33.1 MB, less than 46.95% of C++ online submissions for N-ary Tree Preorder Traversal.

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
    vector<int> preorder(Node* root) 
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

            for (int i = root->children.size() - 1; i >= 0; i--)
                treeStack.push(root->children[i]);
            
            res.push_back(root->val);
        }
        
        return res;
    }
};