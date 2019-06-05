// 这道题和给出先序遍历和中序还是有很大区别的

// Runtime: 20 ms, faster than 24.34% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
// Memory Usage: 18.7 MB, less than 9.65% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& pre, vector<int>& post, int preLeft, int preRight, int postLeft, int postRight)
    {
        TreeNode* node = nullptr;
        if (preLeft <= preRight && postLeft <= postRight)
        {
            node = new TreeNode(pre[preLeft]);

            // 寻找分割边界
            unordered_set<int> hashSet;
            int numOfMisMatch = 0;
            int length = 1;
            
            for (; length <= (preRight - preLeft); length++)
            {
                if (hashSet.find(pre[preLeft + length]) == hashSet.end())
                {
                    numOfMisMatch++;
                    hashSet.insert(pre[preLeft + length]);
                }
                else
                {
                    numOfMisMatch--;
                    hashSet.erase(pre[preLeft + length]);
                }

                if (hashSet.find(post[postLeft - 1 + length]) == hashSet.end())
                {
                    numOfMisMatch++;
                    hashSet.insert(post[postLeft - 1 + length]);
                }
                else
                {
                    numOfMisMatch--;
                    hashSet.erase(post[postLeft - 1 + length]);
                }

                if (numOfMisMatch == 0)
                    break;
            }

            // 递归求解
            if (preLeft < preRight)
            {
                node->left = helper(pre, post, preLeft + 1, preLeft + length, postLeft, postLeft + length - 1);
                node->right = helper(pre, post, preLeft + length + 1, preRight, postLeft + length, postRight - 1);
            }
        }

        return node;
    }
};
};


// 第二版代码，使用数组来充当哈希表
// 果然替换之后的时间和空间都得到了很大的提升！！！
// Runtime: 8 ms, faster than 97.36% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
// Memory Usage: 12.2 MB, less than 67.22% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        vector<bool> hashSet(pre.size(), false);
        return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1, hashSet);
    }
private:
    TreeNode* helper(vector<int>& pre, vector<int>& post, int preLeft, int preRight, int postLeft, int postRight, vector<bool>& hashSet)
    {
        TreeNode* node = nullptr;
        if (preLeft <= preRight && postLeft <= postRight)
        {
            node = new TreeNode(pre[preLeft]);

            // 寻找分割边界
            int numOfMisMatch = 0;
            int length = 1;
            
            for (; length <= (preRight - preLeft); length++)
            {
                if (hashSet[pre[preLeft + length]] == false)
                {
                    numOfMisMatch++;
                    hashSet[pre[preLeft + length]] = true;
                }
                else
                {
                    numOfMisMatch--;
                    hashSet[pre[preLeft + length]] = false;
                }

                if (hashSet[post[postLeft - 1 + length]] == false)
                {
                    numOfMisMatch++;
                    hashSet[post[postLeft - 1 + length]] = true;
                }
                else
                {
                    numOfMisMatch--;
                    hashSet[post[postLeft - 1 + length]] = false;
                }

                if (numOfMisMatch == 0)
                    break;
            }

            // 递归求解
            if (preLeft < preRight)
            {
                node->left = helper(pre, post, preLeft + 1, preLeft + length, postLeft, postLeft + length - 1, hashSet);
                node->right = helper(pre, post, preLeft + length + 1, preRight, postLeft + length, postRight - 1, hashSet);
            }
        }

        return node;
    }
};

// 第三版代码，下方是参考链接，这个使用到了二叉树的性质
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161286/C%2B%2B-O(N)-recursive-solution
// 这个思路的时间复杂度是真线性的
// Runtime: 8 ms, faster than 97.13% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
// Memory Usage: 12.7 MB, less than 57.80% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        unordered_map<int, int> hashMap;
        for (int index = 0; index < post.size(); index++)
            hashMap.insert(pair<int, int>(post[index], index));
            
        return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1, hashMap);
    }
private:
    TreeNode* helper(vector<int>& pre, vector<int>& post, int preLeft, int preRight, int postLeft, int postRight, unordered_map<int, int>& hashMap)
    {
        TreeNode* node = nullptr;

        if (preLeft <= preRight && postLeft <= postRight)
        {
            node = new TreeNode(pre[preLeft]);

            if (preLeft == preRight)
                return node;
            
            // 寻找分割边界
            int length = hashMap.at(pre[preLeft + 1]) - postLeft + 1;

            // 递归求解
            node->left = helper(pre, post, preLeft + 1, preLeft + length, postLeft, postLeft + length - 1, hashMap);
            node->right = helper(pre, post, preLeft + length + 1, preRight, postLeft + length, postRight - 1, hashMap);
        }
        
        return node;
    }
};