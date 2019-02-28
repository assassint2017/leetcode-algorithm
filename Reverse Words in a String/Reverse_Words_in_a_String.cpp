// 151 第一种思路 使用堆栈

// 可见空间和时间都是非常差的
// Runtime: 56 ms, faster than 9.50% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 132.9 MB, less than 5.03% of C++ online submissions for Reverse Words in a String.

// 改动了一处之后时间的空间得到了巨大的提升！！！
// Runtime: 12 ms, faster than 43.47% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 11.3 MB, less than 17.81% of C++ online submissions for Reverse Words in a String.

class Solution 
{
public:
    string reverseWords(string s) 
    {
        stack<string> memo;
        int head = 0, length = 0;
        for (int ptr = 0; ptr < s.length(); ptr++)
        {
            if (s[ptr] == ' ')
            {
                if (length != 0)
                {
                    memo.push(s.substr(head, length));
                    length = 0;
                }
             
                head = ptr + 1;
            }
            else
                length++;           
        }

        if (length != 0)
            memo.push(s.substr(head, length));

        // 根据堆栈中的内容得到最终的结果
        string res = "";
        while (!memo.empty())
        {
            // 改动前的代码
            // res = res + memo.top() + " ";
            res += (memo.top() + " ");
            memo.pop();
        }
        res.pop_back();
        
        return res;        
    }
};

// 第二种思路 使用vector代替堆栈
// 之后发现性能完全没有得到提升
class Solution 
{
public:
    string reverseWords(string s) 
    {
        vector<string> memo;
        int head = 0, length = 0;
        for (int ptr = 0; ptr < s.length(); ptr++)
        {
            if (s[ptr] == ' ')
            {
                if (length != 0)
                {
                    memo.push_back(s.substr(head, length));
                    length = 0;
                }
             
                head = ptr + 1;
            }
            else
                length++;           
        }
        
        if (length != 0)
            memo.push_back(s.substr(head, length));

        // 根据堆栈中的内容得到最终的结果
        string res = "";
        for (int i = memo.size() - 1; i >= 0; i--)
            res += (memo[i] + " ");
        res.pop_back();
        
        return res;        
    }
};

// 第三种思路 进行in-palce的修改 O(1)的空间复杂度
// 使用双指针 将每一个单词进行翻转，最后将整个字符串进行翻转

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 9.7 MB, less than 37.90% of C++ online submissions for Reverse Words in a String.

class Solution 
{
public:
    string reverseWords(string s) 
    {
        if (s.length() == 0)
            return s;

        int head = 0, temphead = 0, tail = 0;
        bool firstWord = true;
        
        while (true)
        {
            while (tail < s.length() && s[tail] == ' ')
                tail++;
            if (tail >= s.length())
                break;

            if (firstWord)
                firstWord = false;
            else
                s[head++] = ' ';
            
            temphead = head;
            while (tail < s.length() && s[tail] != ' ')
                s[head++] = s[tail++];

            // 翻转单个单词
            reverse(s, temphead, head - 1);
        }

        // 将字符串中的空格键删掉
        s.resize(head);
        
        // 翻转整个字符串
        reverse(s, 0, s.length() - 1);
        return s;
    }
private:

    // 逆转从起点到终点的字符串
    void reverse(string& s, int start, int end)
    {
        for (; start < end; start++, end--)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
        }
    }
};