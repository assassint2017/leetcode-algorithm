// 题目虽然比较简单，但是需要考虑的条件还不少!
// Runtime: 12 ms, faster than 23.38% of C++ online submissions for Valid Palindrome.
// Memory Usage: 5.4 MB, less than 0.99% of C++ online submissions for Valid Palindrome.

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        int leftPtr = 0, rightPtr = s.length() - 1;
        while (leftPtr <= rightPtr)
        {
            while (leftPtr <= rightPtr && !judge(s[leftPtr])) leftPtr++;
            while (leftPtr <= rightPtr && !judge(s[rightPtr])) rightPtr--;
            if (leftPtr > rightPtr) break;
            if ((s[leftPtr] == s[rightPtr]) || iscase(s[leftPtr], s[rightPtr]))
                leftPtr++, rightPtr--;
            else
                return false;
        }
        return true;
    }

private:
    inline bool judge(char letter)
    {
        return (letter >= 'a' && letter <= 'z') || 
               (letter >= 'A' && letter <= 'Z') || 
               (letter >= '0' && letter <= '9');
    }

    inline bool iscase(char letter1, char letter2)
    {
        return (letter1 < '0' || letter1 > '9') &&
               (letter2 < '0' || letter2 > '9') &&
               (abs(letter2 - letter1) == 32);
    }
};