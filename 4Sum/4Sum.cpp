// 解决这类问题有一个通用的模板，并且复杂度比常规的回溯低了一个数量级

// Runtime: 4 ms, faster than 99.85% of C++ online submissions for 4Sum.
// Memory Usage: 9.2 MB, less than 89.47% of C++ online submissions for 4Sum.

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        vector<int> candidate;

        sort(nums.begin(), nums.end());

        getCandidate(4, res, candidate, nums, target, 0);
        return res;
    }
private:
    void getCandidate(int N, vector<vector<int>>& res, vector<int>& candidate, const vector<int>& nums, int target, int start)
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
            for (int i = start; i <= nums.size() - N; ++i)
            {
                if (i != start && nums[i] == nums[i - 1])
                    continue;
                if (nums[i] * N > target || nums.back() * N < target)
                    continue;

                candidate.push_back(nums[i]);

                getCandidate(N - 1, res, candidate, nums, target - nums[i], i + 1);
                
                candidate.pop_back();
            }
        }
    }
};