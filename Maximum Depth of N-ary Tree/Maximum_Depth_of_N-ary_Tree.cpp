// Runtime: 140 ms, faster than 80.18% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 32 MB, less than 90.00% of C++ online submissions for Maximum Depth of N-ary Tree.

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
    int maxDepth(Node* root) 
    {
        if (root == nullptr)
            return 0;

        int res = 0;
        for (auto children : root->children)
        {
            res = max(res, maxDepth(children));
        }    
        
        return res + 1;
    }
};