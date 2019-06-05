// Runtime: 144 ms, faster than 97.68% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 34 MB, less than 42.89% of C++ online submissions for N-ary Tree Level Order Traversal.

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
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> res;
        
        // 边界条件处理
        if (root == nullptr)
            return res;
        
        queue<Node*> treeQueue;
        treeQueue.push(root);
        
        while (!treeQueue.empty())
        {
            vector<int> vec;
            for (int i = treeQueue.size(); i > 0; i--)
            {
                root = treeQueue.front();
                treeQueue.pop();
                
                for (auto node : root->children)
                    treeQueue.push(node);
                
                vec.push_back(root->val);
            }
            
            res.push_back(vec);
        }
        
        return res;
    }
};