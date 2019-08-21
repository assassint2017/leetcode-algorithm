// 这道题目最直接的方法明显是n3的时间复杂度
// 稍微优化一点就是n2的时间复杂度，常数的空间复杂度
// 加速的思路可以做到线性的时间复杂度，附参考链接如下
// https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165859/C%2B%2B-O(kN)-solution

// Runtime: 1380 ms, faster than 41.00% of C++ online submissions for Bitwise ORs of Subarrays.
// Memory Usage: 299.4 MB, less than 66.67% of C++ online submissions for Bitwise ORs of Subarrays.

class Solution 
{
public:
    int subarrayBitwiseORs(vector<int>& A) 
    {
        unordered_set<int> res, hs1;
        for (int item : A)
        {
            unordered_set<int> hs2;
            for (int iitem : hs1)
                hs2.insert(item | iitem);
            hs2.insert(item);
            
            hs1 = hs2;
            
            for (int iitem : hs2)
                res.insert(iitem);
        }
        return res.size();
    }
};