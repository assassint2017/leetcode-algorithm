// Runtime: 48 ms, faster than 52.20% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 16 MB, less than 39.08% of C++ online submissions for Longest Palindromic Substring.

class Solution {
public:
	string longestPalindrome(string s) {
		// 边界条件处理
		string res = "";
		if (s.length() == 0) return res;

		int maxLength = 0;
		for (int center = 0; center < s.length(); ++center) {
			int curLength[] = { 1, 0 }, leftPtr[] = { center, center + 1 }, rightPtr[] = { center, center };
			for (int i = 0; i < 2; ++i) {
				while (--leftPtr[i] >= 0 && ++rightPtr[i] < s.length() && s[leftPtr[i]] == s[rightPtr[i]])
					curLength[i] += 2;

				if (curLength[i] > maxLength) {
					res = s.substr(++leftPtr[i], curLength[i]);
					maxLength = curLength[i];
				}
			}
		}
		return res;
	}
};