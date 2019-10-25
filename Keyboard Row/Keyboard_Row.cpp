// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
// Memory Usage: 8.6 MB, less than 57.14% of C++ online submissions for Keyboard Row.

class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> res;
        
        vector<int> memo(26, 0);
        
        // 从上往下数第二层
        memo['a' - 'a'] = 1;
        memo['s' - 'a'] = 1;
        memo['d' - 'a'] = 1;
        memo['f' - 'a'] = 1;
        memo['g' - 'a'] = 1;
        memo['h' - 'a'] = 1;
        memo['j' - 'a'] = 1;
        memo['k' - 'a'] = 1;
        memo['l' - 'a'] = 1;
        
        // 从上往下数第三层
        memo['z' - 'a'] = 2;
        memo['x' - 'a'] = 2;
        memo['c' - 'a'] = 2;
        memo['v' - 'a'] = 2;
        memo['b' - 'a'] = 2;
        memo['n' - 'a'] = 2;
        memo['m' - 'a'] = 2;
        
        for (string word : words)
        {
            bool flag = true;
            
            if (word.length() != 0)
            {
                char temp = word[0] >= 'a' && word[0] <= 'z' ? word[0] : word[0] + 32;
                int layer = memo[temp - 'a'];
                
                for (char chr : word)
                {
                    chr = chr >= 'a' && chr <= 'z' ? chr : chr + 32;
                    if (memo[chr - 'a'] != layer)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            
            if (flag) res.push_back(word);    
        }
        
        return res;
    }
};