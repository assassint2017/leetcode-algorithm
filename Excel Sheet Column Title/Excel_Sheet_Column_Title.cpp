// 进位置

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Excel Sheet Column Title.

class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string str = "";

        while (n > 0)
        {
            char chr;
            if (n % 26 == 0)
            {
                chr = 'Z';
                n /= 26;
                n--;
            }
            else
            {
                chr = 'A' + n % 26 - 1;
                n /= 26;
            }
            str.append(1, chr);
        }
        // 反转字符串
        reverse(str.begin(), str.end());
        return str;
    }
};