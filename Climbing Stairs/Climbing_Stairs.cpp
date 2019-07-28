// 最基础版，自顶向下的动态规划

// 超时了 21 / 45 test cases passed.
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n <= 2)    
            return n;
        else
            return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// 第二个版本，自顶向下的动态规划+备忘录，可以看到加速效果非常明显
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 9.1 MB, less than 5.02% of C++ online submissions for Climbing Stairs.
class Solution 
{
public:
    int climbStairs(int n) 
    {
        unordered_map<int, int> hashmap;
        return n <= 2 ? n : dp(hashmap, n);
    }
private:
    int dp(unordered_map<int, int>& hashmap, int n)
    {
        if (hashmap.find(n) == hashmap.end())
        {
            int res = n <= 2 ? n : dp(hashmap, n - 1) + dp(hashmap, n - 2);
            hashmap.insert(pair<int, int>(n, res));
        }
        return hashmap.at(n);
    }
};

// 第三个版本，自底向上的动态规划，使用递推而不是递归
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.5 MB, less than 23.91% of C++ online submissions for Climbing Stairs.
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n <= 2) return n;

        vector<int> res(n);
        res[0] = 1; res[1] = 2;
        for (int i = 2; i < n; ++i)
            res[i] = res[i - 1] + res[i - 2];
        
        return res[n];
    }
};


// 第四个版本，自底向上的动态规划，常数级的空间复杂度
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n <= 2) return n;

        int res, lres = 2, llres = 1;
        for (int i = 2; i < n; ++i)
        {
            res = lres + llres;
            llres = lres;
            lres = res;
        }
        return res; 
    }
};