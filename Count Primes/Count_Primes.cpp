// 附参考链接
https://leetcode.com/problems/count-primes/discuss/?currentPage=1&orderBy=most_votes&query=
https://assets.leetcode.com/static_assets/public/images/solutions/Sieve_of_Eratosthenes_animation.gif


class Solution 
{
public:
    int countPrimes(int n) 
    {
        // 边界条件处理
        if (n < 2) return 0;

        vector<bool> memo(n, true);
        memo[0] = false;
        memo[1] = false;

        for (int i = 2; i <= sqrt(n); ++i)
            if (memo[i])
                for (int j = 2; i * j < n; ++j)
                    memo[i * j] = false;
        
        int res = 0;
        for (auto item : memo)
            if (item)
                ++res;
        return res;
    }
};