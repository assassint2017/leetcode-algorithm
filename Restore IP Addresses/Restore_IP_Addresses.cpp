// 典型的DFS

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Restore IP Addresses.
// Memory Usage: 8.5 MB, less than 91.67% of C++ online submissions for Restore IP Addresses.

class Solution 
{
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> res;
        
        getCandidate(s, "", res, 4);
        
        return res;
    }
private:
    void getCandidate(string input, string curStr, vector<string>& res, int numOfDigit)
    {
        // 边界条件处理
        if (input.length() < numOfDigit || input.length() > numOfDigit * 3)
            return ;
        
        if (numOfDigit == 1)
        {
            if (atoi(input.c_str()) <= 255)
            {
                if (input.length() == 1)
                    res.push_back(curStr + input);
                else if (input[0] != '0')
                    res.push_back(curStr + input);
            }
            return ;
        }
        
        for (int i = 1; i <= 3; ++i)
        {
            if (input.length() < i) return ;
            string substr = input.substr(0, i);
            
            if (i < 3 || atoi(substr.c_str()) <= 255)
                getCandidate(input.substr(i), curStr + substr + '.', res, numOfDigit - 1);
            
            if (input[0] == '0')
                break;
        }
    }
};