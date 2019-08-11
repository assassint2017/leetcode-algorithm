// 很明显可以使用n2的时间复杂度以及常数的空间复杂度解决问题
// 但是可以用前缀树来以空间换取时间实现线性的时间复杂度
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/130427/()-92

// Runtime: 164 ms, faster than 23.69% of C++ online submissions for Maximum XOR of Two Numbers in an Array.
// Memory Usage: 108.1 MB, less than 10.00% of C++ online submissions for Maximum XOR of Two Numbers in an Array.

struct TrieNode
{
    TrieNode* left = nullptr;
    TrieNode* right = nullptr;
};

class Solution 
{
public:
    Solution() : root(new TrieNode()) {}
    
    ~Solution() { clear(root); }
    
    int findMaximumXOR(vector<int>& nums) 
    {
        // 建立前缀树
        buildTrie(nums);
        
        // 迭代查找
        int res = INT_MIN;
        for (auto item : nums)
        {
            int temp = 0;
            TrieNode* head = root;
            for (int i = 1, ptr = 0x40000000; i < 32; ++i, ptr >>= 1)
            {
                int carry = 0;

                if (ptr & item)
                {
                    if (head->left == nullptr) head = head->right;
                    else ++carry, head = head->left;
                }
                else
                {
                    if (head->right == nullptr) head = head->left;
                    else ++carry, head = head->right;
                }
                
                temp *= 2;
                temp += carry;
            }
            res = temp > res ? temp : res;
        }
        return res;
    }

private:
    TrieNode* root = nullptr;

private:
    void buildTrie(const vector<int>& nums)
    {
        for (auto num : nums)
        {
            TrieNode* head = root;
            for (int i = 1, ptr = 0x40000000; i < 32; ++i, ptr >>= 1)
            {
                if (ptr & num)
                {
                    if (head->right == nullptr)
                    {
                        TrieNode* node = new TrieNode();
                        head->right = node;
                    }
                    head = head->right;
                }
                else
                {
                    if (head->left == nullptr)
                    {
                        TrieNode* node = new TrieNode();
                        head->left = node;
                    }
                    head = head->left;
                }
            }
        }
    }
    
    void clear(TrieNode* root)
    {
        if (root == nullptr) return ;
        clear(root->left);
        clear(root->right);
        delete root;
    }
};