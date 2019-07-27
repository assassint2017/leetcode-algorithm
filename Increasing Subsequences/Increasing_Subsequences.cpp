// 基本思路依然是求子集的思路
// 引入哈希表是为了解决这种情况 [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]

// Runtime: 196 ms, faster than 81.72% of C++ online submissions for Increasing Subsequences.
// Memory Usage: 21.1 MB, less than 61.15% of C++ online submissions for Increasing Subsequences.

class Solution
{
public:
	vector<vector<int>> findSubsequences(vector<int>& nums)
	{
		vector<vector<int>> res;
		vector<int> candidate;

		helper(res, candidate, nums, 0);

		return res;
	}
private:
	void helper(vector<vector<int>>& res, vector<int>& candidate, vector<int>& nums, int start)
	{
		if (candidate.size() >= 2)
			res.push_back(candidate);
        
        unordered_set<int> hashSet;
		for (int i = start; i < nums.size(); ++i)
		{
			if (!candidate.empty() && candidate.back() > nums[i])
				continue;
            if (hashSet.find(nums[i]) == hashSet.end())
            {
                candidate.push_back(nums[i]);
			    helper(res, candidate, nums, i + 1);
			    candidate.pop_back();
                hashSet.insert(nums[i]);
            }
		}
	}
};