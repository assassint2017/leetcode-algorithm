// 二叉树的序列化与反序列化，使用前序遍历解决
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
// Runtime: 36 ms, faster than 97.70% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 26.3 MB, less than 58.80% of C++ online submissions for Serialize and Deserialize Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:

    // Encodes a tree to a single string.
    // 节点之间使用，分隔，空节点使用#进行表示
    string serialize(TreeNode* root) 
    {
        ostringstream os;
        stack<TreeNode*> myStack;

        while (root || !myStack.empty())
        {
            while (root)
            {
                os << root->val << ' ';
                myStack.push(root);
                root = root->left;
            }

            // 需要使用空格进行分割
            os << "# ";

            if (!myStack.empty())
            {
                root = myStack.top();
                myStack.pop();
                root = root->right;
            }
        }

        os << "# ";
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream is(data);
        return helper(is);
    }

private:
    TreeNode* helper(istringstream& is)
    {
        // istringstream 永远不会弹完，只会在最后一个string上循环
        string temp;
        is >> temp;

        if (temp == "#")
            return nullptr;

        int value = stoi(temp);
        TreeNode* newNode = new TreeNode(value);

        newNode->left = helper(is);
        newNode->right = helper(is);

        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));