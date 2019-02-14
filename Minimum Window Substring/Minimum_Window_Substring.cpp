// Runtime: 24 ms, faster than 64.40% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 20.1 MB, less than 100.00% of C++ online submissions for Minimum Window Substring.

class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        if (s.length() == 0 || t.length() == 0)
            return 0;

        // 建立两个字典，第一个是参考，第二个是记录
        // 由于是字符，所以一共就有128种可能，根据这个特性就可以建立一个哈希表
        // 进行高效的查找
        int *map = new int[128], *curmap = new int[128];
        for (int i = 0; i < 128; i++) 
        {
            curmap[i] = -1;
            map[i] = -1;    
        }
        
        for (int i = 0; i < t.length(); i++)
        {
            curmap[t[i]] = 0;
            if (map[t[i]] == -1)
                map[t[i]] = 1;
            else
                map[t[i]]++;
        }
    
        // 建立队列
        queue<pair<char, int>> q;

        // 代表当前拥有的字符个数、需要拥有的字符的总长度、最小窗口长度
        int curnum = 0, num = t.length(), minnum = INT_MAX;
        string res = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (curmap[s[i]] != -1)
            {
                if (curmap[s[i]]++ < map[s[i]])
                    curnum++;
                q.push(pair<char, int>(s[i], i));

                // 当前的窗口拥有了所有的字符
                while (curnum == num)
                {
                    int len = q.back().second - q.front().second + 1;
                    if (len < minnum)
                    {
                        minnum = len;
                        res = s.substr(q.front().second, len);
                    }
                    if (--curmap[q.front().first] < map[q.front().first])
                        curnum--;
                    q.pop();
                }
            }
        }

        delete[] map;
        delete[] curmap;
        return res;
    }
};