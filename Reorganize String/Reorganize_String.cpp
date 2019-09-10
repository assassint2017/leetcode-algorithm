// 附参考链接
// https://leetcode.com/problems/reorganize-string/discuss/113427/C%2B%2B-Greedy-sort-O(N)

// Runtime: 4 ms, faster than 71.71% of C++ online submissions for Reorganize String.
// Memory Usage: 8.6 MB, less than 70.59% of C++ online submissions for Reorganize String.

typedef pair<char, int> cell;

class Solution
{
public:
	string reorganizeString(string S)
	{
		vector<pair<char, int>> hashmap(128);
		for (int i = 0; i < 128; ++i)
			hashmap[i] = pair<char, int>(i, 0);

		for (char chr : S)
			hashmap[chr].second++;

		auto comp = [](const cell& num1, const cell& num2) {return num1.second > num2.second; };
		sort(hashmap.begin(), hashmap.end(), comp);

		string sort = "";
		for (int i = 0; i < 128; ++i)
        {
            if (hashmap[i].second != 0)
            {
                // 如果有一个字母超过半数，则一定无法安排
                if (hashmap[i].second > ((S.length() + 1) / 2))
                    return "";
                sort += string(hashmap[i].second, hashmap[i].first);
            }
        }
        
		string res = "";
		for (int leftPtr = 0, rightPtr = (sort.length() - 1) / 2 + 1; leftPtr < (sort.length() - 1) / 2 + 1; ++leftPtr, ++rightPtr)
		{
			res += sort[leftPtr];
			if (rightPtr < sort.length())
				res += sort[rightPtr];
		}
		return res;
	}
};