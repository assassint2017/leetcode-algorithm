// 最暴力的方式就是n2的时间复杂度，但是可以用双指针加速到n的复杂度
// 非常尴尬的是这样速度依然还是超时了，而且leftPtr如果使用int的话，也很容易发生溢出，因此需要使用long long
class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        // 边界条件处理
        if (c == 0 || c == 1)
            return true;
        
        long long leftPtr = 0;
        long long rightPtr = c;
        long long res = c;
        
        while (leftPtr <= rightPtr)
        {
            if ((leftPtr * leftPtr + rightPtr * rightPtr) > res)
                --rightPtr;
            else if ((leftPtr * leftPtr + rightPtr * rightPtr) < res)
                ++leftPtr;
            else
                return true;
        }
        
        return false;
    }
};


// 其实上边的思路是正确是，只要加上一个简单的trick就可以达到logn的时间复杂度，就是限制rightPtr的最大值
// 所以这道题目最棒的一点就是需要考虑这个加速的小trick、以及使用更大的数据范围！！！！考察点还是非常棒的
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Sum of Square Numbers.

class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        // 边界条件处理
        if (c == 0 || c == 1)
            return true;
        
        long long leftPtr = 0;
        long long rightPtr = static_cast<int>(sqrt(c));
        long long res = c;
        
        while (leftPtr <= rightPtr)
        {
            if ((leftPtr * leftPtr + rightPtr * rightPtr) > res)
                --rightPtr;
            else if ((leftPtr * leftPtr + rightPtr * rightPtr) < res)
                ++leftPtr;
            else
                return true;
        }
        
        return false;
    }
};