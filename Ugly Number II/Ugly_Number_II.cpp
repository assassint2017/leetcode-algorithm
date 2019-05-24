// 第一种思路还是不够快
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        unordered_set<int> hashSet;
        int numOfUgly = 0;
        int num = 1;

        while (true)
        {
            bool found = false;
            if (num % 2 == 0 && hashSet.find(num / 2) != hashSet.end())
                found = true;
            else if (num % 3 == 0 && hashSet.find(num / 3) != hashSet.end())
                found = true;
            else if (num % 5 == 0 && hashSet.find(num / 5) != hashSet.end())
                found = true;
            else if (isUgly(num))
                found = true;

            if (found)
            {
                numOfUgly++;
                hashSet.insert(num);
            }

            if (numOfUgly == n)
                break;
            else
                num++;
        }
        return num;
    }
private:
    bool isUgly(int num) 
    {
        while (num % 2 == 0)     
            num /= 2;
        while (num % 3 == 0)
            num /= 3;
        while (num % 5 == 0)
            num /= 5;   
        return num == 1;
    }
};

// 第二种思路
// Runtime: 8 ms, faster than 93.11% of C++ online submissions for Ugly Number II.
// Memory Usage: 10 MB, less than 54.62% of C++ online submissions for Ugly Number II.
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        // 边界条件处理
        if (n <= 0)
            return 0;
        
        int mutilply2 = 0;
        int mutilply3 = 0;
        int mutilply5 = 0;
        
        vector<int> res(n);
        res[0] = 1;

        for (int index = 1; index < n; index++)
        {
            res[index] = minOfThree(res[mutilply2] * 2, res[mutilply3] * 3, res[mutilply5] * 5);

            while (res[mutilply2] * 2 <= res[index])
                mutilply2++;
            while (res[mutilply3] * 3 <= res[index])
                mutilply3++;
            while (res[mutilply5] * 5 <= res[index])
                mutilply5++;
        }
        return res[n - 1];
    }
private:
    int minOfThree(int num1, int num2, int num3)
    {
        return min(min(num1, num2), num3);
    }
};