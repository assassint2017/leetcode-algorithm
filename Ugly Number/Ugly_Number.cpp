// 下面的代码虽然没啥问题，但是递归毕竟会有重复的子问题，因此应该加入一个备忘录

// 题目要求如下：
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5
// 1 is typically treated as an ugly number.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Ugly Number.
// Memory Usage: 8.2 MB, less than 15.78% of C++ online submissions for Ugly Number.

class Solution 
{
public:
    bool isUgly(int num) 
    {
        // 边界条件处理
        if (num == 1)
            return true;
        if (num <= 0)
            return false;

        // 开始进行递归的计算
        if (num % 2 == 0 && isUgly(num / 2))
            return true;
        else if (num % 3 == 0 && isUgly(num / 3))
            return true;
        else if (num % 5 == 0 && isUgly(num / 5))
            return true;
        else
            return false;       
    }
};

// 下面是更加高效的版本的代码
// Runtime: 4 ms, faster than 92.43% of C++ online submissions for Ugly Number.
// Memory Usage: 8.2 MB, less than 5.11% of C++ online submissions for Ugly Number.
class Solution 
{
public:
    bool isUgly(int num) 
    {
        // 边界条件处理
        if (num <= 0)
            return false;

        // 开始进行循环计算
        while (num % 2 == 0)     
            num /= 2;
        while (num % 3 == 0)
            num /= 3;
        while (num % 5 == 0)
            num /= 5;
        
        return num == 1;
    }
};
