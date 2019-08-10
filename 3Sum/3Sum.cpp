// 典型的回溯
// n3的时间复杂度，果不其然，直接超时了

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> candidate;
        int curSum = 0;

        sort(nums.begin(), nums.end());

        getCandidate(res, nums, candidate, curSum, 0);
        return res;
    }
private:
    void getCandidate(vector<vector<int>>& res, const vector<int>& nums, vector<int>& candidate, int& curSum, int start)
    {
        bool end = false;

        for (int index = start; index < nums.size() && !end; ++index)
        {
            if (index != start && nums[index] == nums[index - 1])
                continue;
            else
            {
                curSum += nums[index];
                candidate.push_back(nums[index]);

                if (curSum > 0 || candidate.size() == 3)
                {
                    if (curSum == 0) res.push_back(candidate), end = true;
                    if (curSum > 0) end = true;
                }
                else
                    getCandidate(res, nums, candidate, curSum, index + 1);
                
                curSum -= nums[index];
                candidate.pop_back();
            }
        }
    }
};


// 另外的一种思路是，首先实现一个高效的towsum查找，由于这个解法是线性的时间复杂度，所以将原始问题的复杂度降低一个等级

// Runtime: 92 ms, faster than 93.23% of C++ online submissions for 3Sum.
// Memory Usage: 14.8 MB, less than 84.71% of C++ online submissions for 3Sum.

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> candidate;

        sort(nums.begin(), nums.end());

        getCandidate(3, res, nums, candidate, 0, 0);
        return res;
    }
private:
    void getCandidate(int N, vector<vector<int>>& res, const vector<int>& nums, vector<int>& candidate, int target, int start)
    {
        if (start + N > nums.size())
            return ;
        else if (N == 2)
        {
            int leftPtr = start;
            int rightPtr = nums.size() - 1;

            while (leftPtr < rightPtr)
            {
                int tempSum = nums[leftPtr] + nums[rightPtr];
                if (tempSum == target)
                {
                    candidate.push_back(nums[leftPtr]);
                    candidate.push_back(nums[rightPtr]);

                    res.push_back(candidate);

                    candidate.pop_back();
                    candidate.pop_back();

                    ++leftPtr;
                    --rightPtr;

                    while (leftPtr < rightPtr && nums[leftPtr] == nums[leftPtr - 1])
                        ++leftPtr;
                    while (leftPtr < rightPtr && nums[rightPtr] == nums[rightPtr + 1])
                        --rightPtr;
                }
                else if (tempSum > target)
                {
                    --rightPtr;
                }
                else
                {
                    ++leftPtr;
                }
            }
        }   
        else
        {
            for (int i = start; i < nums.size(); ++i)
            {
                if (i != start && nums[i] == nums[i - 1])
                    continue;
                if (nums[start] * N > target || nums.back() * N < target)
                    continue;
                
                candidate.push_back(nums[i]);

                getCandidate(N - 1, res, nums, candidate, target - nums[i], i + 1);

                candidate.pop_back();
            }
        }
    }
};