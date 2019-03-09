// Runtime: 12 ms, faster than 96.56% of C++ online submissions for Largest Number.
// Memory Usage: 10.5 MB, less than 32.98% of C++ online submissions for Largest Number.

// stringstream需要添加的库
#include <sstream>

// 比较函数感觉最好还是写在类的外部
bool comp(const string& num1, const string& num2)
{
    return num1 + num2 > num2 + num1;
}
class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return "";
        
        vector<string> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            stringstream stream;
            stream << nums[i];
            string temp;
            stream >> temp;
            vec.push_back(temp);
        }
        
        sort(vec.begin(), vec.end(), comp);
        
        // 多加一个判断条件是为了防止例如 0 0 的情况发生
        if (vec[0] == "0")
            return "0";
        
        string res = "";
        for (int i = 0; i < nums.size(); i++)
            res += vec[i];
        
        return res;
    }
};
