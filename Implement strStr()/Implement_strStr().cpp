// 这道题目完全在考察KMP算法
// Runtime: 4 ms, faster than 91.22% of C++ online submissions for Implement strStr().
// Memory Usage: 9.3 MB, less than 21.43% of C++ online submissions for Implement strStr().

class Solution
{
public:
	int strStr(string s, string p)
	{
		// 边界条件处理
		if (p.length() == 0) return 0;
        if (s.length() == 0 && p.length() != 0) return -1;

		// 获取next数组
		vector<int> next(p.length());
		getNext(next, p);

		// KMP
		int i = 0, j = 0;
		while (i < s.length() && j < static_cast<int>(p.size())
		{
			if (j == -1 || s[i] == p[j])
				++i, ++j;
			else
				j = next[j];
		}
		return j == p.length() ? i - j : -1;
	}
private:
	void getNext(vector<int>& next, const string& p) 
	{
		next[0] = -1;
		int i = 0, j = -1;

		while (i < p.length() - 1) 
		{
			if (j == -1 || p[i] == p[j]) 
			{
				++i, ++j;
				next[i] = j;
			}
			else 
				j = next[j];
		}
	}
};